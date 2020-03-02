# gpuformat

- [About](#about)
  - [Features](#features)
  - [Supported Platforms](#supported-platforms)
- [Examples](#examples)
  - [Format Traits](#format-traits)
  - [Translating Formats](#translating-formats)
  - [Iterating over Formats](#iterating-over-formats)
  - [Loading and Storing](#loading-and-storing)
  - [Sampling](#sampling)
  - [Decompressing](#decompressing)
- [Building](#building)
- [Format Name Standard](#format-name-standard)
- [TODO](#todo)
- [Thirdparty libraries](#thidparty-libraries)

## About

There are several different graphics api's out there helping to abstract the gpu, but all of them represent the gpu in slightly different ways. Formats to represent textures and buffers can be one of the hardest to keep straight. **gpuformat** aims to provide a clear, unified abstraction of gpu formats while also giving accurate and reliable translations to each graphics api.

### Features
- **Abstraction of most dxgi (DirectX), OpenGL, and Vulkan formats** - Most formats used for vertex buffers, textures, and general purpose buffers are accounted for. Video formats are not currently supported.
- **`constexpr` traits for each format** - Each format has a set of traits detailing the properties that define it. Those include the number of channels, channels used, a best fit sample type, block extents, block byte size, in which api they are supported, whether they are normalized, an integer, a float, signed, or srgb. Other properties try to help define the position and bit length of each component in the format.
- **Loading format data streams into common sample data types** - Almost every format (all except pvrtc) has a function to load a block of that formats data into a common sample type. Those sample types are four components (RGBA), 32 or 64 bits per component, with the data type being uint32_t, int32_t, float, uint64_t, int64_t, or double. Reading is available for all uncompressed and compressed formats.
- **Storing data as the specified format** - Most formats have a function to take a common sample type and store the data as the desired format. *ASTC, BC, ETC, EAC, and PVRTC compressed formats are not supported for writing.*
- **Support for compressed formats** - These formats include ASTC, BC, ETC, EAC and PVRTC compression schemes.

### Supported Platforms
- DirectX 11 (dxgi)
- DirectX 12 (dxgi)
- OpenGL
- OpenGL ES
- Vulkan

### Examples
#### Format Traits
Format traits are type safe, static constexpr traits of a specific format.
```
#include <gpuformat/traits.h>

// all values are for the example format R8G8B8A8_UNORM

// size of a single block of data in the texture
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::BlockByteSize; //4 bytes

// how many texels in each dimension for a single data block of the texture
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::BlockExtent; // 1, 1, 1

// number of texels in a single data block (BlockExtent.x * BlockExtent.y * BlockExtent.z)
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::BlockTexelCount; // 1

// number of components the format represents
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::ComponentCount; // 4

// data type for a single component when sampled
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::ValueType; // float

// data type for a single sample representing only the number of components available in the format
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::NarrowSampleType; // glm::vec4

// size of a single narrow sample
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::NarrowSampleByteSize; // 16 bytes

// size of all the narrow samples in a block
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::NarrowSampleBlockByteSize; // 16 bytes

// data type for a single sample representing the RGBA channels, even if the format does not have some of those channels
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::WideSampleType; // glm::vec4

// size of a single wide sample
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::WideSampleByteSize; // 16 bytes

// size of all the wide samples in a block
gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::WideSampleBlockByteSize; // 16 bytes
```

#### Format Info
Format info duplicates some of the type safe traits, but also adds a bunch of properties that are available at runtime.

There are two ways to access a format's gpuformat::FormatInfo object
1. Access the FormatInfo object directly from the FormatTraits template overload. This can be used for compile time constants.
```
    const gpuformat::FormatInfo &formatInfo = gpuformat::FormatTraits<gpuformat::Format::R8G8B8A8_UNORM>::info;
```
2. From the formatInfo function. This can be used for dynamic runtime information.
```
    gpuformat::Format someFormat;
    ...
    const gpuformat::FormatInfo &formatInfo = gpuformat::formatInfo(someFormat);
```

Here's all the values in FormatInfo:
```
formatInfo.blockByteSize;
formatInfo.blockExtent;
formatInfo.componentCount;
formatInfo.narrowSampleByteSize;
formatInfo.narrowSampleBlockByteSize;
formatInfo.wideSampleByteSize;
formatInfo.wideSampleBlockByteSize;
formatInfo.narrowIsWide;
formatInfo.isSigned;
formatInfo.normalized;
formatInfo.scaled
formatInfo.integer;
formatInfo.floatingPoint;
formatInfo.srgb;
formatInfo.packed;
formatInfo.depth;
formatInfo.stencil;
formatInfo.compression;
formatInfo.readable;
formatInfo.writable;
formatInfo.decompressible;
formatInfo.suppoertedApis;
formatInfo.channels;
formatInfo.redBitMask;
formatInfo.greenBitMask;
formatInfo.blueBitMask;
formatInfo.alphaBitMask;
formatInfo.redIndex;
formatInfo.greenIndex;
formatInfo.blueIndex;
formatInfo.alphaIndex;
```

#### Translating Formats
DirectX11 & DirectX12
```
#include <gpuformat/dxgi.h>

gpuformat::dxgi::FormatConversion dxgiConversion = gpuformat::dxgi::translateFormat(someGpuFormat_Format);

std::optional<gpuformat::Format> format = gpuformat::dxgi::translateFormat(someDXGIFormat);
```

OpenGL
```
#include <gpuformat/opengl.h>

gpuformat::gl::FormatConversion glConversion = gpuformat::gl::translateFormat(someGpuFormat_Format);

std::optional<gpuformat::Format> format = gpuformat::gl::translateFormat(openglInternalFormat, openglFormat, openglType);
```

Vulkan
```
#include <gpuformat/vulkan.h>

gpuformat::vulkan::FormatConversion vulkanConversion = gpuformat::vulkan::translateFormat(someGpuFormat_Format);

std::optional<gpuformat::Format> format = gpuformat::vulkan::translateFormat(someVkFormat);
```

#### Iterating over Formats
```
```

#### Loading and Storing
```
```

#### Sampling
```
```

#### Decompressing
```
```

### Supported Compilers
- Microsoft Visual C++ 2017
- Microsoft Visual C++ 2019

No other compilers have been tested, but there's no reason why they shouldn't work. I am more than happy integrate changes that provide compatibility for other compilers.

### Building
- If you **do not need** to read compressed formats (ASTC, BC, ETC, EAC, or PVRTC) formats
  **gpuformat** can be configured as a header only library. To do so, you need to do the following steps:
  1. Include all the headers except for `astc.h`, `bc.h`, `etc.h`, `pvrtc.h`.
  2. In `config.h`, uncomment `#define GF_EXCLUDE_COMPRESSED_FORMATS`
- If you **want** to read ASTC, BC, ETC, EAC, or PVRTC formats.
  1. Run [premake 5.0](https://premake.github.io/) in the gpuformat directory using the `premake5.lua` file targeting your desired toolset. ex. `premake5.exe vs2019`.
  2. Then build the static libraries with your desired environment.
  3. Include all of the files in `gpuformat/include` in your project.

### TODO
- Metal and Metal2 support
- Video format read support
- Support for legacy formats like luminance
- Utility functions for Vulkan
- Complete test coverage

### Thirdparty Libraries
- [astc_dec](https://github.com/richgel999/astc_dec) - ASTC format decompression.
- [DirectXTex](https://github.com/microsoft/DirectXTex) - BC format decompression and converting to and from half types.
- [glm](https://github.com/g-truc/glm) - Basic vector types and some packing and unpacking functions.
- [tcbrindle-span](https://github.com/tcbrindle/span) - std::span implementation for C++11 and later.
- [SwiftShader](https://github.com/google/swiftshader) - ETC and EAC format decompression.
- [PowerVR SDK](https://www.imgtec.com/developers/powervr-sdk-tools/powervr-sdk/) - PVRTC format decompression.
