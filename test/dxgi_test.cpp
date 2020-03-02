#include <gpufmt/dxgi.h>
#include <gpufmt/string.h>
#include <gpufmt/traits.h>
#include <gpufmt/utility.h>
#include <catch.hpp>

TEST_CASE("DXGI_FORMAT exact match symmetric conversion") {
    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        gpufmt::dxgi::FormatConversion dxgiFormatConversion = gpufmt::dxgi::translateFormat(format);

        if(!dxgiFormatConversion.exact) {
            continue;
        }

        std::optional<gpufmt::Format> retranslatedFormat = gpufmt::dxgi::translateFormat(dxgiFormatConversion.exact.value());

        if(retranslatedFormat.has_value()) {
            CHECK(format == retranslatedFormat.value());
        } else {
            FAIL_CHECK("gpufmt::Format: " << format << " DXGI_FORMAT: " << dxgiFormatConversion.exact.value());
        }
    }
}

TEST_CASE("DXGI_FORMAT closest match is valid") {
    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        gpufmt::dxgi::FormatConversion dxgiFormatConversion = gpufmt::dxgi::translateFormat(format);

        if(!dxgiFormatConversion.closest) {
            continue;
        }

        std::optional<gpufmt::Format> closestFormat = gpufmt::dxgi::translateFormat(dxgiFormatConversion.closest.value());

        if(!closestFormat) {
            FAIL_CHECK(format << " closest match was " << dxgiFormatConversion.closest.value() << ", which cannot be represented by gpufmt::Format.");
        }
    }
}

TEST_CASE("DXGI_FORMAT no match") {
    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        gpufmt::dxgi::FormatConversion dxgiFormatConversion = gpufmt::dxgi::translateFormat(format);

        if(dxgiFormatConversion) {
            continue;
        }

        for(DXGI_FORMAT dxgiFormat = static_cast<DXGI_FORMAT>(0); dxgiFormat <= DXGI_FORMAT_V408; dxgiFormat = static_cast<DXGI_FORMAT>(static_cast<uint32_t>(dxgiFormat) + 1)) {
            std::optional<gpufmt::Format> gpuFormat = gpufmt::dxgi::translateFormat(dxgiFormat);

            CHECK(format != gpuFormat);
        }
    }
}

TEST_CASE("FormatTraits<> with DirectX11/12 must have gpufmt::Format that translates to DXGI_FORMAT") {
    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        const gpufmt::FormatInfo &info = gpufmt::formatInfo(format);

        if((info.supportedApis & gpufmt::GraphicsApi::DirectX11) != gpufmt::GraphicsApi::None ||
            (info.supportedApis & gpufmt::GraphicsApi::DirectX12) != gpufmt::GraphicsApi::None)
        {
            gpufmt::dxgi::FormatConversion conversion = gpufmt::dxgi::translateFormat(format);

            if(!conversion.exact) {
                FAIL_CHECK("gpufmt::Format::" << format << " has DirectX11 or DirectX12 as a supported api, bit there is no exact translation from " << format << " to a DXGI_FORMAT.");
            }
        }
    }
}

TEST_CASE("DXGI_FORMAT with matching gpufmt::Format is in supportedApis of the corresponding FormatTraits<>") {
    for(DXGI_FORMAT dxgiFormat = static_cast<DXGI_FORMAT>(0); dxgiFormat <= DXGI_FORMAT_V408; dxgiFormat = static_cast<DXGI_FORMAT>(static_cast<uint32_t>(dxgiFormat) + 1)) {
        std::optional<gpufmt::Format> gpuFormat = gpufmt::dxgi::translateFormat(dxgiFormat);

        if(!gpuFormat) {
            continue;
        }

        const gpufmt::FormatInfo &info = gpufmt::formatInfo(gpuFormat.value());

        if((info.supportedApis & gpufmt::GraphicsApi::DirectX11) == gpufmt::GraphicsApi::None ||
            (info.supportedApis & gpufmt::GraphicsApi::DirectX12) == gpufmt::GraphicsApi::None)
        {
            FAIL_CHECK(dxgiFormat << " translates to gpufmt::Format::" << gpuFormat.value() << " which does not list DirectX11 or DirectX12 as a supported api in FormatTraits.");
        }
    }
}