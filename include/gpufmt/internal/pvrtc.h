#pragma once

#include <gpufmt/config.h>
#include <gpufmt/definitions.h>

#if !defined(GF_EXCLUDE_COMPRESSED_FORMATS) && !defined(GF_EXCLUDE_PVRTC_COMPRESSED_FORMATS)

#include <glm/vec4.hpp>
#include <glm/gtc/type_precision.hpp>

#include <cstdint>

namespace gpufmt::internal {
    bool decompressPVRTCBlock_2BPP(const gpufmt::Surface<const uint64_t> &compressedBlocks, const gpufmt::Surface<glm::u8vec4> decompressedTexels) noexcept;

    bool decompressPVRTCBlock_4BPP(const gpufmt::Surface<const uint64_t> &compressedBlocks, const gpufmt::Surface<glm::u8vec4> decompressedTexels) noexcept;

}

#endif