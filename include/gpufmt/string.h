#pragma once

#include <gpufmt/definitions.h>
#include <gpufmt/format.h>

#include <string_view>

namespace gpufmt {
    [[nodiscard]]
    constexpr std::string_view toString(gpufmt::Format format) noexcept {
        switch(format)
        {
        case gpufmt::Format::UNDEFINED:
            return "UNDEFINED";
        case gpufmt::Format::R4G4_UNORM_PACK8:
            return "R4G4_UNORM_PACK8";
        case gpufmt::Format::R4G4B4A4_UNORM_PACK16:
            return "R4G4B4A4_UNORM_PACK16";
        case gpufmt::Format::B4G4R4A4_UNORM_PACK16:
            return "B4G4R4A4_UNORM_PACK16";
        case gpufmt::Format::A4R4G4B4_UNORM_PACK16:
            return "A4R4G4B4_UNORM_PACK16";
        case gpufmt::Format::R5G6B5_UNORM_PACK16:
            return "R5G6B5_UNORM_PACK16";
        case gpufmt::Format::B5G6R5_UNORM_PACK16:
            return "B5G6R5_UNORM_PACK16";
        case gpufmt::Format::R5G5B5A1_UNORM_PACK16:
            return "R5G5B5A1_UNORM_PACK16";
        case gpufmt::Format::B5G5R5A1_UNORM_PACK16:
            return "B5G5R5A1_UNORM_PACK16";
        case gpufmt::Format::A1R5G5B5_UNORM_PACK16:
            return "A1R5G5B5_UNORM_PACK16";
        case gpufmt::Format::R8_UNORM:
            return "R8_UNORM";
        case gpufmt::Format::R8_SNORM:
            return "R8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R8_USCALED:
            return "R8_USCALED";
        case gpufmt::Format::R8_SSCALED:
            return "R8_SSCALED";
#endif
        case gpufmt::Format::R8_UINT:
            return "R8_UINT";
        case gpufmt::Format::R8_SINT:
            return "R8_SINT";
        case gpufmt::Format::R8_SRGB:
            return "R8_SRGB";
        case gpufmt::Format::A8_UNORM:
            return "A8_UNORM";
        case gpufmt::Format::R8G8_UNORM:
            return "R8G8_UNORM";
        case gpufmt::Format::R8G8_SNORM:
            return "R8G8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R8G8_USCALED:
            return "R8G8_USCALED";
        case gpufmt::Format::R8G8_SSCALED:
            return "R8G8_SSCALED";
#endif
        case gpufmt::Format::R8G8_UINT:
            return "R8G8_UINT";
        case gpufmt::Format::R8G8_SINT:
            return "R8G8_SINT";
        case gpufmt::Format::R8G8_SRGB:
            return "R8G8_SRGB";
        case gpufmt::Format::R8G8B8_UNORM:
            return "R8G8B8_UNORM";
        case gpufmt::Format::R8G8B8_SNORM:
            return "R8G8B8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R8G8B8_USCALED:
            return "R8G8B8_USCALED";
        case gpufmt::Format::R8G8B8_SSCALED:
            return "R8G8B8_SSCALED";
#endif
        case gpufmt::Format::R8G8B8_UINT:
            return "R8G8B8_UINT";
        case gpufmt::Format::R8G8B8_SINT:
            return "R8G8B8_SINT";
        case gpufmt::Format::R8G8B8_SRGB:
            return "R8G8B8_SRGB";
        case gpufmt::Format::B8G8R8_UNORM:
            return "B8G8R8_UNORM";
        case gpufmt::Format::B8G8R8_SNORM:
            return "B8G8R8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::B8G8R8_USCALED:
            return "B8G8R8_USCALED";
        case gpufmt::Format::B8G8R8_SSCALED:
            return "B8G8R8_SSCALED";
#endif
        case gpufmt::Format::B8G8R8_UINT:
            return "B8G8R8_UINT";
        case gpufmt::Format::B8G8R8_SINT:
            return "B8G8R8_SINT";
        case gpufmt::Format::B8G8R8_SRGB:
            return "B8G8R8_SRGB";
        case gpufmt::Format::R8G8B8A8_UNORM:
            return "R8G8B8A8_UNORM";
        case gpufmt::Format::R8G8B8A8_SNORM:
            return "R8G8B8A8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R8G8B8A8_USCALED:
            return "R8G8B8A8_USCALED";
        case gpufmt::Format::R8G8B8A8_SSCALED:
            return "R8G8B8A8_SSCALED";
#endif
        case gpufmt::Format::R8G8B8A8_UINT:
            return "R8G8B8A8_UINT";
        case gpufmt::Format::R8G8B8A8_SINT:
            return "R8G8B8A8_SINT";
        case gpufmt::Format::R8G8B8A8_SRGB:
            return "R8G8B8A8_SRGB";
        case gpufmt::Format::B8G8R8A8_UNORM:
            return "B8G8R8A8_UNORM";
        case gpufmt::Format::B8G8R8A8_SNORM:
            return "B8G8R8A8_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::B8G8R8A8_USCALED:
            return "B8G8R8A8_USCALED";
        case gpufmt::Format::B8G8R8A8_SSCALED:
            return "B8G8R8A8_SSCALED";
#endif
        case gpufmt::Format::B8G8R8A8_UINT:
            return "B8G8R8A8_UINT";
        case gpufmt::Format::B8G8R8A8_SINT:
            return "B8G8R8A8_SINT";
        case gpufmt::Format::B8G8R8A8_SRGB:
            return "B8G8R8A8_SRGB";
        case gpufmt::Format::B8G8R8X8_UNORM:
            return "B8G8R8X8_UNORM";
        case gpufmt::Format::B8G8R8X8_SRGB:
            return "B8G8R8X8_SRGB";
        case gpufmt::Format::A8B8G8R8_UNORM_PACK32:
            return "A8B8G8R8_UNORM_PACK32";
        case gpufmt::Format::A8B8G8R8_SNORM_PACK32:
            return "A8B8G8R8_SNORM_PACK32";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::A8B8G8R8_USCALED_PACK32:
            return "A8B8G8R8_USCALED_PACK32";
        case gpufmt::Format::A8B8G8R8_SSCALED_PACK32:
            return "A8B8G8R8_SSCALED_PACK32";
#endif
        case gpufmt::Format::A8B8G8R8_UINT_PACK32:
            return "A8B8G8R8_UINT_PACK32";
        case gpufmt::Format::A8B8G8R8_SINT_PACK32:
            return "A8B8G8R8_SINT_PACK32";
        case gpufmt::Format::A8B8G8R8_SRGB_PACK32:
            return "A8B8G8R8_SRGB_PACK32";
        case gpufmt::Format::A2R10G10B10_UNORM_PACK32:
            return "A2R10G10B10_UNORM_PACK32";
        case gpufmt::Format::A2R10G10B10_SNORM_PACK32:
            return "A2R10G10B10_SNORM_PACK32";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::A2R10G10B10_USCALED_PACK32:
            return "A2R10G10B10_USCALED_PACK32";
        case gpufmt::Format::A2R10G10B10_SSCALED_PACK32:
            return "A2R10G10B10_SSCALED_PACK32";
#endif
        case gpufmt::Format::A2R10G10B10_UINT_PACK32:
            return "A2R10G10B10_UINT_PACK32";
        case gpufmt::Format::A2R10G10B10_SINT_PACK32:
            return "A2R10G10B10_SINT_PACK32";
        case gpufmt::Format::A2B10G10R10_UNORM_PACK32:
            return "A2B10G10R10_UNORM_PACK32";
        case gpufmt::Format::A2B10G10R10_SNORM_PACK32:
            return "A2B10G10R10_SNORM_PACK32";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::A2B10G10R10_USCALED_PACK32:
            return "A2B10G10R10_USCALED_PACK32";
        case gpufmt::Format::A2B10G10R10_SSCALED_PACK32:
            return "A2B10G10R10_SSCALED_PACK32";
#endif
        case gpufmt::Format::A2B10G10R10_UINT_PACK32:
            return "A2B10G10R10_UINT_PACK32";
        case gpufmt::Format::A2B10G10R10_SINT_PACK32:
            return "A2B10G10R10_SINT_PACK32";
        case gpufmt::Format::R16_UNORM:
            return "R16_UNORM";
        case gpufmt::Format::R16_SNORM:
            return "R16_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R16_USCALED:
            return "R16_USCALED";
        case gpufmt::Format::R16_SSCALED:
            return "R16_SSCALED";
#endif
        case gpufmt::Format::R16_UINT:
            return "R16_UINT";
        case gpufmt::Format::R16_SINT:
            return "R16_SINT";
        case gpufmt::Format::R16_SFLOAT:
            return "R16_SFLOAT";
        case gpufmt::Format::R16G16_UNORM:
            return "R16G16_UNORM";
        case gpufmt::Format::R16G16_SNORM:
            return "R16G16_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R16G16_USCALED:
            return "R16G16_USCALED";
        case gpufmt::Format::R16G16_SSCALED:
            return "R16G16_SSCALED";
#endif
        case gpufmt::Format::R16G16_UINT:
            return "R16G16_UINT";
        case gpufmt::Format::R16G16_SINT:
            return "R16G16_SINT";
        case gpufmt::Format::R16G16_SFLOAT:
            return "R16G16_SFLOAT";
        case gpufmt::Format::R16G16B16_UNORM:
            return "R16G16B16_UNORM";
        case gpufmt::Format::R16G16B16_SNORM:
            return "R16G16B16_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R16G16B16_USCALED:
            return "R16G16B16_USCALED";
        case gpufmt::Format::R16G16B16_SSCALED:
            return "R16G16B16_SSCALED";
#endif
        case gpufmt::Format::R16G16B16_UINT:
            return "R16G16B16_UINT";
        case gpufmt::Format::R16G16B16_SINT:
            return "R16G16B16_SINT";
        case gpufmt::Format::R16G16B16_SFLOAT:
            return "R16G16B16_SFLOAT";
        case gpufmt::Format::R16G16B16A16_UNORM:
            return "R16G16B16A16_UNORM";
        case gpufmt::Format::R16G16B16A16_SNORM:
            return "R16G16B16A16_SNORM";
#ifndef GF_EXCLUDE_SCALED_FORMATS
        case gpufmt::Format::R16G16B16A16_USCALED:
            return "R16G16B16A16_USCALED";
        case gpufmt::Format::R16G16B16A16_SSCALED:
            return "R16G16B16A16_SSCALED";
#endif
        case gpufmt::Format::R16G16B16A16_UINT:
            return "R16G16B16A16_UINT";
        case gpufmt::Format::R16G16B16A16_SINT:
            return "R16G16B16A16_SINT";
        case gpufmt::Format::R16G16B16A16_SFLOAT:
            return "R16G16B16A16_SFLOAT";
        case gpufmt::Format::R32_UINT:
            return "R32_UINT";
        case gpufmt::Format::R32_SINT:
            return "R32_SINT";
        case gpufmt::Format::R32_SFLOAT:
            return "R32_SFLOAT";
        case gpufmt::Format::R32G32_UINT:
            return "R32G32_UINT";
        case gpufmt::Format::R32G32_SINT:
            return "R32G32_SINT";
        case gpufmt::Format::R32G32_SFLOAT:
            return "R32G32_SFLOAT";
        case gpufmt::Format::R32G32B32_UINT:
            return "R32G32B32_UINT";
        case gpufmt::Format::R32G32B32_SINT:
            return "R32G32B32_SINT";
        case gpufmt::Format::R32G32B32_SFLOAT:
            return "R32G32B32_SFLOAT";
        case gpufmt::Format::R32G32B32A32_UINT:
            return "R32G32B32A32_UINT";
        case gpufmt::Format::R32G32B32A32_SINT:
            return "R32G32B32A32_SINT";
        case gpufmt::Format::R32G32B32A32_SFLOAT:
            return "R32G32B32A32_SFLOAT";
#ifndef GF_EXCLUDE_64BIT_FORMATS
        case gpufmt::Format::R64_UINT:
            return "R64_UINT";
        case gpufmt::Format::R64_SINT:
            return "R64_SINT";
        case gpufmt::Format::R64_SFLOAT:
            return "R64_SFLOAT";
        case gpufmt::Format::R64G64_UINT:
            return "R64G64_UINT";
        case gpufmt::Format::R64G64_SINT:
            return "R64G64_SINT";
        case gpufmt::Format::R64G64_SFLOAT:
            return "R64G64_SFLOAT";
        case gpufmt::Format::R64G64B64_UINT:
            return "R64G64B64_UINT";
        case gpufmt::Format::R64G64B64_SINT:
            return "R64G64B64_SINT";
        case gpufmt::Format::R64G64B64_SFLOAT:
            return "R64G64B64_SFLOAT";
        case gpufmt::Format::R64G64B64A64_UINT:
            return "R64G64B64A64_UINT";
        case gpufmt::Format::R64G64B64A64_SINT:
            return "R64G64B64A64_SINT";
        case gpufmt::Format::R64G64B64A64_SFLOAT:
            return "R64G64B64A64_SFLOAT";
#endif // GF_EXCLUDE_64BIT_FORMATS
        case gpufmt::Format::B10G11R11_UFLOAT_PACK32:
            return "B10G11R11_UFLOAT_PACK32";
        case gpufmt::Format::E5B9G9R9_UFLOAT_PACK32:
            return "E5B9G9R9_UFLOAT_PACK32";
        case gpufmt::Format::D16_UNORM:
            return "D16_UNORM";
        case gpufmt::Format::X8_D24_UNORM_PACK32:
            return "X8_D24_UNORM_PACK32";
        case gpufmt::Format::D32_SFLOAT:
            return "D32_SFLOAT";
        case gpufmt::Format::S8_UINT:
            return "S8_UINT";
        case gpufmt::Format::D16_UNORM_S8_UINT:
            return "D16_UNORM_S8_UINT";
        case gpufmt::Format::D24_UNORM_S8_UINT:
            return "D24_UNORM_S8_UINT";
        case gpufmt::Format::D32_SFLOAT_S8_UINT:
            return "D32_SFLOAT_S8_UINT";
#ifndef GF_EXCLUDE_COMPRESSED_FORMATS
#ifndef GF_EXCLUDE_BC_COMPRESSED_FORMATS
        case gpufmt::Format::BC1_RGB_UNORM_BLOCK:
            return "BC1_RGB_UNORM_BLOCK";
        case gpufmt::Format::BC1_RGB_SRGB_BLOCK:
            return "BC1_RGB_SRGB_BLOCK";
        case gpufmt::Format::BC1_RGBA_UNORM_BLOCK:
            return "BC1_RGBA_UNORM_BLOCK";
        case gpufmt::Format::BC1_RGBA_SRGB_BLOCK:
            return "BC1_RGBA_SRGB_BLOCK";
        case gpufmt::Format::BC2_UNORM_BLOCK:
            return "BC2_UNORM_BLOCK";
        case gpufmt::Format::BC2_SRGB_BLOCK:
            return "BC2_SRGB_BLOCK";
        case gpufmt::Format::BC3_UNORM_BLOCK:
            return "BC3_UNORM_BLOCK";
        case gpufmt::Format::BC3_SRGB_BLOCK:
            return "BC3_SRGB_BLOCK";
        case gpufmt::Format::BC4_UNORM_BLOCK:
            return "BC4_UNORM_BLOCK";
        case gpufmt::Format::BC4_SNORM_BLOCK:
            return "BC4_SNORM_BLOCK";
        case gpufmt::Format::BC5_UNORM_BLOCK:
            return "BC5_UNORM_BLOCK";
        case gpufmt::Format::BC5_SNORM_BLOCK:
            return "BC5_SNORM_BLOCK";
        case gpufmt::Format::BC6H_UFLOAT_BLOCK:
            return "BC6H_UFLOAT_BLOCK";
        case gpufmt::Format::BC6H_SFLOAT_BLOCK:
            return "BC6H_SFLOAT_BLOCK";
        case gpufmt::Format::BC7_UNORM_BLOCK:
            return "BC7_UNORM_BLOCK";
        case gpufmt::Format::BC7_SRGB_BLOCK:
            return "BC7_SRGB_BLOCK";
#endif //GF_EXCLUDE_BC_COMPRESSED_FORMATS
#ifndef GF_EXCLUDE_ETC_COMPRESSED_FORMATS
        case gpufmt::Format::ETC2_R8G8B8_UNORM_BLOCK:
            return "ETC2_R8G8B8_UNORM_BLOCK";
        case gpufmt::Format::ETC2_R8G8B8_SRGB_BLOCK:
            return "ETC2_R8G8B8_SRGB_BLOCK";
        case gpufmt::Format::ETC2_R8G8B8A1_UNORM_BLOCK:
            return "ETC2_R8G8B8A1_UNORM_BLOCK";
        case gpufmt::Format::ETC2_R8G8B8A1_SRGB_BLOCK:
            return "ETC2_R8G8B8A1_SRGB_BLOCK";
        case gpufmt::Format::ETC2_R8G8B8A8_UNORM_BLOCK:
            return "ETC2_R8G8B8A8_UNORM_BLOCK";
        case gpufmt::Format::ETC2_R8G8B8A8_SRGB_BLOCK:
            return "ETC2_R8G8B8A8_SRGB_BLOCK";
        case gpufmt::Format::EAC_R11_UNORM_BLOCK:
            return "EAC_R11_UNORM_BLOCK";
        case gpufmt::Format::EAC_R11_SNORM_BLOCK:
            return "EAC_R11_SNORM_BLOCK";
        case gpufmt::Format::EAC_R11G11_UNORM_BLOCK:
            return "EAC_R11G11_UNORM_BLOCK";
        case gpufmt::Format::EAC_R11G11_SNORM_BLOCK:
            return "EAC_R11G11_SNORM_BLOCK";
#endif //GF_EXCLUDE_ETC_COMPRESSED_FORMATS
#ifndef GF_EXCLUDE_ASTC_COMPRESSED_FORMATS
        case gpufmt::Format::ASTC_4x4_UNORM_BLOCK:
            return "ASTC_4x4_UNORM_BLOCK";
        case gpufmt::Format::ASTC_4x4_SRGB_BLOCK:
            return "ASTC_4x4_SRGB_BLOCK";
        case gpufmt::Format::ASTC_5x4_UNORM_BLOCK:
            return "ASTC_5x4_UNORM_BLOCK";
        case gpufmt::Format::ASTC_5x4_SRGB_BLOCK:
            return "ASTC_5x4_SRGB_BLOCK";
        case gpufmt::Format::ASTC_5x5_UNORM_BLOCK:
            return "ASTC_5x5_UNORM_BLOCK";
        case gpufmt::Format::ASTC_5x5_SRGB_BLOCK:
            return "ASTC_5x5_SRGB_BLOCK";
        case gpufmt::Format::ASTC_6x5_UNORM_BLOCK:
            return "ASTC_6x5_UNORM_BLOCK";
        case gpufmt::Format::ASTC_6x5_SRGB_BLOCK:
            return "ASTC_6x5_SRGB_BLOCK";
        case gpufmt::Format::ASTC_6x6_UNORM_BLOCK:
            return "ASTC_6x6_UNORM_BLOCK";
        case gpufmt::Format::ASTC_6x6_SRGB_BLOCK:
            return "ASTC_6x6_SRGB_BLOCK";
        case gpufmt::Format::ASTC_8x5_UNORM_BLOCK:
            return "ASTC_8x5_UNORM_BLOCK";
        case gpufmt::Format::ASTC_8x5_SRGB_BLOCK:
            return "ASTC_8x5_SRGB_BLOCK";
        case gpufmt::Format::ASTC_8x6_UNORM_BLOCK:
            return "ASTC_8x6_UNORM_BLOCK";
        case gpufmt::Format::ASTC_8x6_SRGB_BLOCK:
            return "ASTC_8x6_SRGB_BLOCK";
        case gpufmt::Format::ASTC_8x8_UNORM_BLOCK:
            return "ASTC_8x8_UNORM_BLOCK";
        case gpufmt::Format::ASTC_8x8_SRGB_BLOCK:
            return "ASTC_8x8_SRGB_BLOCK";
        case gpufmt::Format::ASTC_10x5_UNORM_BLOCK:
            return "ASTC_10x5_UNORM_BLOCK";
        case gpufmt::Format::ASTC_10x5_SRGB_BLOCK:
            return "ASTC_10x5_SRGB_BLOCK";
        case gpufmt::Format::ASTC_10x6_UNORM_BLOCK:
            return "ASTC_10x6_UNORM_BLOCK";
        case gpufmt::Format::ASTC_10x6_SRGB_BLOCK:
            return "ASTC_10x6_SRGB_BLOCK";
        case gpufmt::Format::ASTC_10x8_UNORM_BLOCK:
            return "ASTC_10x8_UNORM_BLOCK";
        case gpufmt::Format::ASTC_10x8_SRGB_BLOCK:
            return "ASTC_10x8_SRGB_BLOCK";
        case gpufmt::Format::ASTC_10x10_UNORM_BLOCK:
            return "ASTC_10x10_UNORM_BLOCK";
        case gpufmt::Format::ASTC_10x10_SRGB_BLOCK:
            return "ASTC_10x10_SRGB_BLOCK";
        case gpufmt::Format::ASTC_12x10_UNORM_BLOCK:
            return "ASTC_12x10_UNORM_BLOCK";
        case gpufmt::Format::ASTC_12x10_SRGB_BLOCK:
            return "ASTC_12x10_SRGB_BLOCK";
        case gpufmt::Format::ASTC_12x12_UNORM_BLOCK:
            return "ASTC_12x12_UNORM_BLOCK";
        case gpufmt::Format::ASTC_12x12_SRGB_BLOCK:
            return "ASTC_12x12_SRGB_BLOCK";
#endif //GF_EXCLUDE_ASTC_COMPRESSED_FORMATS
#ifndef GF_EXCLUDE_PVRTC_COMPRESSED_FORMATS
        case gpufmt::Format::PVRTC1_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_2BPP_UNORM_BLOCK_IMG";
        case gpufmt::Format::PVRTC1_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_4BPP_UNORM_BLOCK_IMG";
        case gpufmt::Format::PVRTC2_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_2BPP_UNORM_BLOCK_IMG";
        case gpufmt::Format::PVRTC2_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_4BPP_UNORM_BLOCK_IMG";
        case gpufmt::Format::PVRTC1_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_2BPP_SRGB_BLOCK_IMG";
        case gpufmt::Format::PVRTC1_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_4BPP_SRGB_BLOCK_IMG";
        case gpufmt::Format::PVRTC2_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_2BPP_SRGB_BLOCK_IMG";
        case gpufmt::Format::PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_4BPP_SRGB_BLOCK_IMG";
#endif //GF_EXCLUDE_PVRTC_COMPRESSED_FORMATS
#endif //GF_EXCLUDE_COMPRESSED_FORMATS
        default:
            return "UNDEFINED";
        }
    }

    [[nodiscard]]
    constexpr std::string_view toString(gpufmt::WriteError error) {
        switch (error)
        {
        case gpufmt::WriteError::None:
            return "None";
        case gpufmt::WriteError::FormatNotWriteable:
            return "FormatNotWriteable";
        case gpufmt::WriteError::DestinationTooSmall:
            return "DestinationTooSmall";
        default:
            return "Unknown WriteError";
        }
    }

    [[nodiscard]]
    constexpr std::string_view toString(gpufmt::BlockSampleError error) {
        switch (error)
        {
        case gpufmt::BlockSampleError::None:
            return "None";
        case gpufmt::BlockSampleError::SourceTooSmall:
            return "SourceTooSmall";
        case gpufmt::BlockSampleError::DestinationTooSmall:
            return "DestinationTooSmall";
        case gpufmt::BlockSampleError::DepthStencilUnsupported:
            return "DepthStencilUnsupported";
        case gpufmt::BlockSampleError::InvalidFormat:
            return "InvalidFormat";
        case gpufmt::BlockSampleError::BloxelOutOfRange:
            return "BloxelOutOfRange";
        default:
            return "Unknown BlockSampleError";
        }
    }

    [[nodiscard]]
    constexpr std::string_view toString(gpufmt::Channel channel) {
        switch(channel)
        {
        case gpufmt::Channel::Red:
            return "Red";
        case gpufmt::Channel::Green:
            return "Green";
        case gpufmt::Channel::Blue:
            return "Blue";
        case gpufmt::Channel::Alpha:
            return "Alpha";
        default:
            return "Unknown Channel";
        }
    }
}