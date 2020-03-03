#pragma once

#if __has_include(<span>)
#include <span>

namespace gpufmt {
    template<class T, size_t Extent = std::dynamic_extent>
    using span = std::span<T, Extent>;
}
#else
#include <span.hpp>

namespace gpufmt {
    using namespace tcb;
}
#endif

// For glm::tvec3 used as Extent. If redefining gpufmt::Extent to another type, you can remove this include.
#include <glm/vec3.hpp> 

namespace gpufmt {
    using Extent = glm::tvec3<uint32_t>;
    using byte = std::byte;

    template<class T>
    gpufmt::span<const gpufmt::byte> asBytes(const T &value) {
        return gpufmt::span<const gpufmt::byte>{reinterpret_cast<const std::byte*>(&value), sizeof(T)};
    }

    template<class T>
    gpufmt::span<gpufmt::byte> asWritableBytes(T &value) {
        return gpufmt::span<gpufmt::byte>{reinterpret_cast<std::byte*>(&value), sizeof(T)};
    }

    template<class T, size_t Size>
    gpufmt::span<const gpufmt::byte> asBytes(const std::array<T, Size> &arr) {
        return gpufmt::span<const gpufmt::byte>(reinterpret_cast<const gpufmt::byte*>(arr.data()), arr.size() * sizeof(T));
    }

    template<class T, size_t Size>
    gpufmt::span<gpufmt::byte> asWritableBytes(std::array<T, Size> &arr) {
        return gpufmt::span<gpufmt::byte>(reinterpret_cast<gpufmt::byte*>(arr.data()), arr.size() * sizeof(T));
    }

    template<class T>
    gpufmt::span<const gpufmt::byte> asBytes(gpufmt::span<const T> arr) {
        return gpufmt::span<const gpufmt::byte>(reinterpret_cast<const gpufmt::byte*>(arr.data()), arr.size_bytes());
    }

    template<class T>
    gpufmt::span<gpufmt::byte> asWritableBytes(gpufmt::span<T> arr) {
        return gpufmt::span<gpufmt::byte>(reinterpret_cast<gpufmt::byte*>(arr.data()), arr.size_bytes());
    }
}

//#define GF_EXCLUDE_64BIT_FORMATS
//#define GF_EXCLUDE_SCALED_FORMATS
//#define GF_EXCLUDE_ASTC_COMPRESSED_FORMATS
//#define GF_EXCLUDE_BC_COMPRESSED_FORMATS
//#define GF_EXCLUDE_ETC_COMPRESSED_FORMATS
//#define GF_EXCLUDE_PVRTC_COMPRESSED_FORMATS
//#define GF_EXCLUDE_COMPRESSED_FORMATS