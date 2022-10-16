#include <gpufmt/decompress.h>
#include <gpufmt/limits.h>
#include <gpufmt/sample.h>
#include <gpufmt/storage.h>
#include <gpufmt/string.h>
#include <gpufmt/traits.h>
#include <gpufmt/utility.h>
#include <gpufmt/write.h>

#include <catch.hpp>

TEST_CASE("BlockSampler") {
    glm::u8vec4 color{ 1, 2, 3, 255 };

    gpufmt::Surface<const gpufmt::byte> surface;
    surface.blockData = gpufmt::asBytes(color);
    surface.extentInBlocks = { 1, 1, 1 };

    gpufmt::BlockSampler sampler{ gpufmt::Format::R8G8B8A8_UNORM };
    gpufmt::BlockSampleError error;
    auto wideSample = sampler.wideSample(surface, { 0, 0, 0 }, error);

    std::vector<float> expectedSample{ 1.0f / 255.0f, 2.0f / 255.0f, 3.0f / 255.0f, 1.0f };
    gpufmt::span<gpufmt::byte> expectedSampleSpan(reinterpret_cast<gpufmt::byte*>(expectedSample.data()), expectedSample.size() * sizeof(float));

    CHECK(std::equal(wideSample.begin(), wideSample.end(), expectedSampleSpan.begin()));

    auto narrowSample = sampler.narrowSample(surface, { 0, 0, 0 }, error);
    CHECK(std::equal(narrowSample.begin(), narrowSample.end(), expectedSampleSpan.begin()));
}

[[nodiscard]] bool equal(float left, float right, float epsilon) noexcept {
    return std::abs(left - right) <= epsilon;
}

[[nodiscard]] bool equal(double left, double right, double epsilon) noexcept {
    return std::abs(left - right) <= epsilon;
}

[[nodiscard]] bool equal(int32_t left, int32_t right, int32_t epsilon) noexcept {
    return std::abs(left - right) <= epsilon;
}

[[nodiscard]] bool equal(int64_t left, int64_t right, int64_t epsilon) noexcept {
    return std::abs(left - right) <= epsilon;
}

[[nodiscard]] constexpr bool equal(uint32_t left, uint32_t right, uint32_t) noexcept {
    return left == right;
}

[[nodiscard]] constexpr bool equal(uint64_t left, uint64_t right, uint64_t) noexcept {
    return left == right;
}

template<class T>
void requireChannel(gpufmt::Format format, glm::tvec4<T> expectedColor, std::span<const T> sampledColor, T epsilon, gpufmt::ChannelMask channelMask, gpufmt::Channel channel) noexcept {
    INFO(gpufmt::toString(channel));

    const gpufmt::ChannelMask channelAsMask = gpufmt::channelToChannelMask(channel);

    if ((channelMask & channelAsMask) == channelAsMask) {
        const auto clampedExpected = gpufmt::clampToFormatLimits(format, channel, expectedColor[(size_t)channel]);
        INFO("Expected Value = " << clampedExpected << " +/- " << epsilon << " [" << clampedExpected - epsilon << ", " << clampedExpected + epsilon << "]");
        REQUIRE(equal(sampledColor[(size_t)channel], clampedExpected, epsilon));
    } else {
        const T defaultValue = (channel == gpufmt::Channel::Alpha) ? T(1) : T(0);
        REQUIRE(sampledColor[(size_t)channel] == defaultValue);
    }
}

template<class T>
void runWriteSampleTest(gpufmt::Format format, std::span<const glm::tvec4<T>> colors, glm::tvec4<T> epsilon = glm::tvec4<T>{ T(0) }) {
    gpufmt::Writer writer(format);
    gpufmt::BlockSampler sampler(format);

    REQUIRE(writer.isFormatWriteable());

    const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

    for(const glm::tvec4<T>& color : colors) {
        INFO("Color = (" << color.x << ", " << color.y << ", " << color.z << ", " << color.w << ")");

        std::array<std::byte, sizeof(uint64_t) * 4> writeBuffer;
        gpufmt::WriteError writeError = writer.writeTo(color, writeBuffer);

        INFO("WriteError::" << gpufmt::toString(writeError));
        REQUIRE(writeError == gpufmt::WriteError::None);

        gpufmt::Surface<const gpufmt::byte> surface;
        surface.blockData = writeBuffer;
        surface.extentInBlocks = { 1, 1, 1 };

        std::array<std::byte, sizeof(uint64_t) * 4> sampleBuffer;
        gpufmt::BlockSampleError sampleError = sampler.wideSampleTo(surface, { 0, 0, 0 }, sampleBuffer);

        INFO("BlockSampleError::" << gpufmt::toString(sampleError));
        REQUIRE(sampleError == gpufmt::BlockSampleError::None);

        gpufmt::span<T> sampledValues(reinterpret_cast<T*>(sampleBuffer.data()), 4);
        INFO("Sample = (" << sampledValues[0] << ", " << sampledValues[1] << ", " << sampledValues[2] << ", " << sampledValues[3] << ")");
            
        requireChannel<T>(format, color, sampledValues, epsilon.r, formatInfo.channels, gpufmt::Channel::Red);
        requireChannel<T>(format, color, sampledValues, epsilon.g, formatInfo.channels, gpufmt::Channel::Green);
        requireChannel<T>(format, color, sampledValues, epsilon.b, formatInfo.channels, gpufmt::Channel::Blue);
        requireChannel<T>(format, color, sampledValues, epsilon.a, formatInfo.channels, gpufmt::Channel::Alpha);
    }
}

TEST_CASE("FloatSampler") {
    std::array<glm::vec4, 4> f32samples = { {
        {1.0f, 2.0f, 3.0f, 4.0f},
        {2.0f, 3.0f, 4.0f, 1.0f},
        {3.0f, 4.0f, 1.0f, 2.0f},
        {4.0f, 1.0f, 2.0f, 3.0f},
    } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.floatingPoint) {
            continue;
        }

        if(formatInfo.redBitMask.width == 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<float>(format, f32samples);
    }
}

TEST_CASE("NormalizedSampler") {
    std::array<glm::vec4, 8> f32samples = { {
        {0.0f, 0.33f, 0.66f, 1.0f},
        {1.0f, 0.0f, 0.33f, 0.66f},
        {0.66f, 1.0f, 0.0f, 0.33f},
        {0.33f, 0.66f, 1.0f, 0.0f},
        {0.0f, -0.33f, -0.66f, -1.0f},
        {-1.0f, 0.0f, -0.33f, -0.66f},
        {-0.66f, -1.0f, 0.0f, -0.33f},
        {-0.33f, -0.66f, -1.0f, 0.0f},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.normalized) {
            continue;
        }

        INFO(gpufmt::toString(format));

        glm::vec4 epsilon;

        for(int i = 0; i < 4; ++i) {
            const gpufmt::Channel channel = (gpufmt::Channel)i;
            const gpufmt::ChannelMask channelAsMask = gpufmt::channelToChannelMask(channel);

            if ((formatInfo.channels & channelAsMask) == channelAsMask) {
                const auto bitWidth = formatInfo.channelBitMask(channel).width;
                const auto nonSignBitWidth = (formatInfo.isSigned) ? bitWidth - 1 : bitWidth;

                epsilon[i] = static_cast<float>(0.5 / ((std::pow(2.0, (double)nonSignBitWidth) - 1.0)));
            } else {
                epsilon[i] = 0.0f;
            }
        }

        runWriteSampleTest<float>(format, f32samples, epsilon);
    }
}

TEST_CASE("Int32Sampler") {
    std::array<glm::i32vec4, 8> samples = { {
        {0, 1, 255, 10000},
        {10000, 0, 1, 255},
        {255, 10000, 0, 1},
        {1, 255, 1000, 0},
        {-1, -255, -10000, -123456789101112},
        {-123456789101112, -1, -255, -10000},
        {-10000, -123456789101112, -1, -255},
        {-255, -10000, -123456789101112, -1},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.integer) {
            continue;
        }

        if(!formatInfo.isSigned) {
            continue;
        }

        if(formatInfo.redBitMask.width == 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<int32_t>(format, samples);
    }
}

TEST_CASE("UInt32Sampler") {
    std::array<glm::u32vec4, 8> samples = { {
        {0, 1, 255, 10000},
        {10000, 0, 1, 255},
        {255, 10000, 0, 1},
        {1, 255, 1000, 0},
        {-1, -255, -10000, -123456789101112},
        {-123456789101112, -1, -255, -10000},
        {-10000, -123456789101112, -1, -255},
        {-255, -10000, -123456789101112, -1},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.integer) {
            continue;
        }

        if(formatInfo.isSigned) {
            continue;
        }

        if(formatInfo.redBitMask.width == 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<uint32_t>(format, samples);
    }
}

#ifndef GF_EXCLUDE_64BIT_FORMATS

TEST_CASE("DoubleSampler") {
    std::array<glm::dvec4, 8> samples = { {
        {1.0, 2.0, 3.0, 4.0},
        {2.0, 3.0, 4.0, 1.0},
        {3.0, 4.0, 1.0, 2.0},
        {4.0, 1.0, 2.0, 3.0},
        {-1.0, -2.0, -3.0, -4.0},
        {-2.0, -3.0, -4.0, -1.0},
        {-3.0, -4.0, -1.0, -2.0},
        {-4.0, -1.0, -2.0, -3.0},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.floatingPoint) {
            continue;
        }

        if(formatInfo.redBitMask.width != 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<double>(format, samples);
    }
}

TEST_CASE("Int64Sampler") {
    std::array<glm::i64vec4, 8> samples = { {
        {0, 1, 255, 10000},
        {10000, 0, 1, 255},
        {255, 10000, 0, 1},
        {1, 255, 1000, 0},
        {-1, -255, -10000, -123456789101112},
        {-123456789101112, -1, -255, -10000},
        {-10000, -123456789101112, -1, -255},
        {-255, -10000, -123456789101112, -1},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.integer) {
            continue;
        }

        if(!formatInfo.isSigned) {
            continue;
        }

        if(formatInfo.channelBitMask(gpufmt::Channel::Red).width != 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<int64_t>(format, samples);
    }
}

TEST_CASE("UInt64Sampler") {
    std::array<glm::u64vec4, 8> samples = { {
        {0, 1, 255, 10000},
        {10000, 0, 1, 255},
        {255, 10000, 0, 1},
        {1, 255, 1000, 0},
        {-1, -255, -10000, -123456789101112},
        {-123456789101112, -1, -255, -10000},
        {-10000, -123456789101112, -1, -255},
        {-255, -10000, -123456789101112, -1},
        } };

    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo& formatInfo = gpufmt::formatInfo(format);

        if(!formatInfo.writeable) {
            continue;
        }

        if(!formatInfo.integer) {
            continue;
        }

        if(formatInfo.isSigned) {
            continue;
        }

        if(formatInfo.channelBitMask(gpufmt::Channel::Red).width != 64) {
            continue;
        }

        INFO(gpufmt::toString(format));

        runWriteSampleTest<uint64_t>(format, samples);
    }
}

#endif // GF_EXCLUDE_64BIT_FORMATS