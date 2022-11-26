#pragma once

#include <gpufmt/definitions.h>
#include <gpufmt/format.h>
#include <gpufmt/internal/format_traits_common.h>

namespace gpufmt {
[[nodiscard]] const FormatInfo& formatInfo(Format format) noexcept;

[[nodiscard]] SampleType formatSampleType(Format format) noexcept;

[[nodiscard]] constexpr bool isFormat4444UNorm(Format format) noexcept
{
    return format == Format::B4G4R4A4_UNORM_PACK16 ||
        format == Format::R4G4B4A4_UNORM_PACK16 ||
        format == Format::A4R4G4B4_UNORM_PACK16;
}

[[nodiscard]] constexpr bool isFormat4444UNorm(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.redBitMask.width == 4 &&
        formatInfo.greenBitMask.width == 4 &&
        formatInfo.blueBitMask.width == 4 &&
        formatInfo.alphaBitMask.width == 4;
}

[[nodiscard]] constexpr bool isFormat565UNorm(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.redBitMask.width == 5 &&
        formatInfo.greenBitMask.width == 6 &&
        formatInfo.blueBitMask.width == 5 &&
        formatInfo.alphaBitMask.width == 0;
}

[[nodiscard]] constexpr bool isFormat5551UNorm(Format format) noexcept
{
    return format == Format::A1R5G5B5_UNORM_PACK16 ||
        format == Format::R5G5B5A1_UNORM_PACK16 ||
        format == Format::B5G5R5A1_UNORM_PACK16;
}

[[nodiscard]] constexpr bool isFormat5551UNorm(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.redBitMask.width == 5 &&
        formatInfo.greenBitMask.width == 5 &&
        formatInfo.blueBitMask.width == 5 &&
        formatInfo.alphaBitMask.width == 1;
}

[[nodiscard]] constexpr bool isFormat888UNorm(Format format) noexcept
{
    return format == Format::R8G8B8_UNORM || format == Format::B8G8R8_UNORM;
}

[[nodiscard]] constexpr bool isFormat888SRgb(Format format) noexcept
{
    return format == Format::R8G8B8_SRGB || format == Format::B8G8R8_SRGB;
}

[[nodiscard]] constexpr bool isFormat888UNorm(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.blockByteSize == 3 &&
        !formatInfo.isSigned &&
        formatInfo.normalized &&
        !formatInfo.srgb &&
        formatInfo.channels == ChannelMask::RGB &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat888SRgb(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.blockByteSize == 3 &&
        !formatInfo.isSigned &&
        formatInfo.normalized &&
        formatInfo.srgb &&
        formatInfo.channels == ChannelMask::RGB &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat8888Or888XUNorm(Format format) noexcept
{
    return format == Format::A8B8G8R8_UNORM_PACK32 ||
        format == Format::R8G8B8A8_UNORM ||
        format == Format::B8G8R8A8_UNORM ||
        format == Format::B8G8R8X8_UNORM;
}

[[nodiscard]] constexpr bool isFormat8888UNorm(Format format) noexcept
{
    return format == Format::A8B8G8R8_UNORM_PACK32 ||
        format == Format::R8G8B8A8_UNORM ||
        format == Format::B8G8R8A8_UNORM;
}

[[nodiscard]] constexpr bool isFormat8888Or888XSRgb(Format format) noexcept
{
    return format == Format::A8B8G8R8_SRGB_PACK32 ||
        format == Format::R8G8B8A8_SRGB ||
        format == Format::B8G8R8A8_SRGB ||
        format == Format::B8G8R8X8_SRGB;
}

[[nodiscard]] constexpr bool isFormat8888SRgb(Format format) noexcept
{
    return format == Format::A8B8G8R8_SRGB_PACK32 ||
        format == Format::R8G8B8A8_SRGB ||
        format == Format::B8G8R8A8_SRGB;
}

[[nodiscard]] constexpr bool isFormat8888Or888XUNorm(const FormatInfo& formatInfo) noexcept
{
    return !formatInfo.isSigned &&
        formatInfo.normalized &&
        !formatInfo.srgb &&
        formatInfo.blockByteSize == 4 &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat8888UNorm(const FormatInfo& formatInfo) noexcept
{
    return !formatInfo.isSigned &&
        formatInfo.normalized && 
        !formatInfo.srgb &&
        formatInfo.blockByteSize == 4 &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8 &&
        formatInfo.alphaBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat8888Or888XSRgb(const FormatInfo& formatInfo) noexcept
{
    return !formatInfo.isSigned &&
        formatInfo.normalized &&
        formatInfo.srgb &&
        formatInfo.blockByteSize == 4 &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat8888SRgb(const FormatInfo& formatInfo) noexcept
{
    return !formatInfo.isSigned &&
        formatInfo.normalized &&
        formatInfo.srgb &&
        formatInfo.blockByteSize == 4 &&
        formatInfo.redBitMask.width == 8 &&
        formatInfo.greenBitMask.width == 8 &&
        formatInfo.blueBitMask.width == 8 &&
        formatInfo.alphaBitMask.width == 8;
}

[[nodiscard]] constexpr bool isFormat1010102UNorm(Format format) noexcept
{
    return format == Format::A2B10G10R10_UNORM_PACK32 || format == Format::A2R10G10B10_UNORM_PACK32;
}

[[nodiscard]] constexpr bool isFormat1010102UNorm(const FormatInfo& formatInfo) noexcept
{
    return formatInfo.blockByteSize == 4 &&
        !formatInfo.isSigned &&
        formatInfo.normalized &&
        formatInfo.redBitMask.width == 10 &&
        formatInfo.greenBitMask.width == 10 &&
        formatInfo.blueBitMask.width == 10 &&
        formatInfo.alphaBitMask.width == 2;
}
}