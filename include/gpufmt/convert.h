#pragma once

#include <gpufmt/config.h>
#include <gpufmt/format.h>
#include <gpufmt/info.h>
#include <gpufmt/internal/bit_packing.h>
#include <gpufmt/traits.h>

namespace gpufmt
{
    [[nodiscard]] constexpr uint32_t convert5551UNormTo8888UNorm(uint16_t value, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat5551UNorm(sourceInfo));
        assert(isFormat8888Or888XUNorm(destInfo));

        uint32_t outValue = 0xffffffff & (internal::packBitsUNorm<uint32_t, 8>(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.redBitMask.offset), destInfo.redBitMask.offset) |
            internal::packBitsUNorm<uint32_t, 8>(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.greenBitMask.offset), destInfo.greenBitMask.offset) |
            internal::packBitsUNorm<uint32_t, 8>(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.blueBitMask.offset), destInfo.blueBitMask.offset));

        outValue |= (destInfo.alphaBitMask.width > 0) ?
            internal::packBitsUNorm<uint32_t, 8>(internal::unpackBitsUNorm<uint16_t, 1>(value, sourceInfo.alphaBitMask.offset), destInfo.alphaBitMask.offset) :
            0;

        return outValue;
    }

    [[nodiscard]] constexpr void convert5551UNormTo8888UNorm(uint16_t value, gpufmt::span<gpufmt::byte> outBuffer, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(outBuffer.size() >= 4);
        assert(isFormat5551UNorm(sourceInfo));
        assert(isFormat8888Or888XUNorm(destInfo));

        auto out8888 = std::span<uint8_t>(reinterpret_cast<uint8_t*>(outBuffer.data()), outBuffer.size());

        out8888[destInfo.redIndex] = internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.redBitMask.offset);
        out8888[destInfo.greenIndex] = internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.greenBitMask.offset);
        out8888[destInfo.blueIndex] = internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.blueBitMask.offset);

        if(destInfo.alphaIndex != kInvalidChannelIndex)
        {
            out8888[destInfo.alphaIndex] = internal::unpackBitsUNorm<uint16_t, 1>(value, sourceInfo.alphaBitMask.offset);
        }
    }

    [[nodiscard]] constexpr uint32_t convert5551UNormTo8888SRgb(uint16_t value, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat5551UNorm(sourceInfo));
        assert(isFormat8888Or888XSRgb(destInfo));

        return internal::packBitsUNorm<uint32_t, 8>(linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.redBitMask.offset)), destInfo.redBitMask.offset) |
            internal::packBitsUNorm<uint32_t, 8>(linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.greenBitMask.offset)), destInfo.greenBitMask.offset) |
            internal::packBitsUNorm<uint32_t, 8>(linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.blueBitMask.offset)), destInfo.blueBitMask.offset) |
            internal::packBitsUNorm<uint32_t, 8>(internal::unpackBitsUNorm<uint16_t, 1>(value, sourceInfo.alphaBitMask.offset), destInfo.alphaBitMask.offset);
    }

    [[nodiscard]] constexpr void convert5551UNormTo8888SRgb(uint16_t value, gpufmt::span<gpufmt::byte> outBuffer, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(outBuffer.size() >= 4);
        assert(isFormat5551UNorm(sourceInfo));
        assert(isFormat8888Or888XSRgb(destInfo));

        auto out8888 = std::span<uint8_t>(reinterpret_cast<uint8_t*>(outBuffer.data()), outBuffer.size());

        out8888[destInfo.redIndex] = linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.redBitMask.offset));
        out8888[destInfo.greenIndex] = linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.greenBitMask.offset));
        out8888[destInfo.blueIndex] = linearTosRGB(internal::unpackBitsUNorm<uint16_t, 5>(value, sourceInfo.blueBitMask.offset));

        if(destInfo.alphaIndex != kInvalidChannelIndex)
        {
            out8888[destInfo.alphaIndex] = internal::unpackBitsUNorm<uint16_t, 1>(value, sourceInfo.alphaBitMask.offset);
        }
    }

    [[nodiscard]] constexpr uint32_t convert888UNormTo8888Or888XUNorm(glm::u8vec3 value, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat888UNorm(sourceInfo));
        assert(isFormat8888Or888XUNorm(destInfo));

        return (value[sourceInfo.redIndex] << destInfo.redBitMask.offset) |
            (value[sourceInfo.greenIndex] << destInfo.greenBitMask.offset) |
            (value[sourceInfo.blueIndex] << destInfo.blueBitMask.offset) |
            (destInfo.hasChannel(Channel::Alpha) ? 0xff << destInfo.alphaBitMask.offset : 0u);
    }

    [[nodiscard]] constexpr uint32_t convert888SRgbTo8888Or888XSRgb(glm::u8vec3 value, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat888SRgb(sourceInfo));
        assert(isFormat8888Or888XSRgb(destInfo));

        return (value[sourceInfo.redIndex] << destInfo.redBitMask.offset) |
            (value[sourceInfo.greenIndex] << destInfo.greenBitMask.offset) |
            (value[sourceInfo.blueIndex] << destInfo.blueBitMask.offset) |
            (destInfo.hasChannel(Channel::Alpha) ? 0xff << destInfo.alphaBitMask.offset : 0u);
    }

    [[nodiscard]] constexpr void convert888UNormTo8888Or888XUNorm(glm::u8vec3 value, std::span<std::byte> outBuffer, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat888UNorm(sourceInfo));
        assert(isFormat8888Or888XUNorm(destInfo));
        
        auto out8888 = std::span<uint8_t>(reinterpret_cast<uint8_t*>(outBuffer.data()), outBuffer.size());

        out8888[destInfo.redIndex] = value[sourceInfo.redIndex];
        out8888[destInfo.greenIndex] = value[sourceInfo.greenIndex];
        out8888[destInfo.blueIndex] = value[sourceInfo.blueIndex];

        if(destInfo.hasChannel(Channel::Alpha))
        {
            out8888[destInfo.alphaIndex] = 0xff;
        }
    }

    [[nodiscard]] constexpr void convert888SRgbTo8888Or888XSRgb(glm::u8vec3 value, std::span<std::byte> outBuffer, const gpufmt::FormatInfo& sourceInfo, const gpufmt::FormatInfo& destInfo) noexcept
    {
        assert(isFormat888SRgb(sourceInfo));
        assert(isFormat8888Or888XSRgb(destInfo));

        auto out8888 = std::span<uint8_t>(reinterpret_cast<uint8_t*>(outBuffer.data()), outBuffer.size());

        out8888[destInfo.redIndex] = value[sourceInfo.redIndex];
        out8888[destInfo.greenIndex] = value[sourceInfo.greenIndex];
        out8888[destInfo.blueIndex] = value[sourceInfo.blueIndex];

        if(destInfo.hasChannel(Channel::Alpha))
        {
            out8888[destInfo.alphaIndex] = 0xff;
        }
    }
}