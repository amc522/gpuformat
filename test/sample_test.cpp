#include <gpufmt/sample.h>
#include <gpufmt/decompress.h>

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

    CHECK(std::equal(wideSample.cbegin(), wideSample.cend(), expectedSampleSpan.cbegin()));

    auto narrowSample = sampler.narrowSample(surface, { 0, 0, 0 }, error);
    CHECK(std::equal(narrowSample.cbegin(), narrowSample.cend(), expectedSampleSpan.cbegin()));
}