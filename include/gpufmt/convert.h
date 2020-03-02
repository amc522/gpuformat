#pragma once

#include <gpufmt/traits.h>
#include <gpufmt/sample.h>

namespace gpufmt {
    template<Format From, Format To>
    class ConverterT {
    public:
        typename FormatTraits<To>::BlockType operator()(typename FormatTraits<From>::BlockType fromValue) noexcept {
            auto narrowFromSample = FormatTraits<From>::loadBlock(fromValue);
            auto wideFromSample = internal::expandSampleType(narrowFromSample[0]);
            auto wideToSample = internal::sampleCast<FormatTraits<From>::ValueType, FormatTraits<To>::ValueType>(wideFromSample);
            auto narrowToSample = internal::SampleTruncator<FormatTraits<To>::ValueType, FormatTraits<To>::ComponentCount>()(wideToSample);
            return FormatTraits<To>::storeBlock({ narrowToSample });
        };

    private:
        FormatTraits<From> mFromTraits;
        FormatTraits<To> mToTraits;
    };
}