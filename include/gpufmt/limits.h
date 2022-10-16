#pragma once

#include <gpufmt/definitions.h>
#include <gpufmt/format.h>
#include <gpufmt/traits.h>
#include <gpufmt/visit.h>

namespace gpufmt {
template<Format FormatV>
class FormatLimits {
public:
    using Traits = FormatTraits<FormatV>;

    [[nodiscard]]
    static constexpr typename Traits::ValueType lowest(Channel channel) noexcept {
        if(!testChannelInMask(Traits::info.channels, channel)) {
            return Traits::ValueType(0);
        }

        if constexpr(!Traits::info.isSigned) {
            return Traits::ValueType(0);
        }
        else if constexpr(Traits::info.normalized) {
            return -1.0f;
        }
        else if constexpr(Traits::info.floatingPoint && (Traits::BlockByteSize / Traits::ComponentCount) == 2u) {
            // half
            return -65504.0f;
        }
#ifndef GF_EXCLUDE_SCALED_FORMATS
        else if constexpr(Traits::info.scaled) {
            return internal::sscaledMin(Traits::info.channelBitMask(channel).width);
        }
#endif // GF_EXCLUDE_SCALED_FORMATS
        else if constexpr(Traits::info.integer) {
            return internal::signedMin<Traits::ValueType>(Traits::info.channelBitMask(channel).width);
        }
        else {
            return std::numeric_limits<Traits::ValueType>::lowest();
        }
    }

    [[nodiscard]]
    static constexpr typename Traits::ValueType max(Channel channel) noexcept {
        if constexpr(Traits::info.normalized) {
            return 1.0f;
        }
        else if constexpr(Traits::info.floatingPoint && (sizeof(Traits::BlockType) / Traits::ComponentCount) == 2u) {
            // half
            return 65504.0f;
        }
#ifndef GF_EXCLUDE_SCALED_FORMATS
        else if constexpr(Traits::info.scaled) {
            if constexpr(Traits::info.isSigned) {
                return internal::sscaledMax(Traits::info.channelBitMask(channel).width);
            } else {
                return internal::uscaledMax(Traits::info.channelBitMask(channel).width);
            }
        }
#endif // GF_EXCLUDE_SCALED_FORMATS
        else if constexpr(Traits::info.integer) {
            if constexpr(Traits::info.isSigned) {
                return internal::signedMax<Traits::ValueType>(Traits::info.channelBitMask(channel).width);
            }
            else {
                return internal::unsignedMax<Traits::ValueType>(Traits::info.channelBitMask(channel).width);
            }
        }
        else {
            return std::numeric_limits<Traits::ValueType>::max();
        }
    }
};

template<>
class FormatLimits<gpufmt::Format::UNDEFINED> {
public:
    [[nodiscard]]
    static constexpr float lowest(Channel) noexcept {
        return 0.0f;
    }

    [[nodiscard]]
    static constexpr float max(Channel) noexcept {
        return 0.0f;
    }
};

template<>
class FormatLimits<gpufmt::Format::E5B9G9R9_UFLOAT_PACK32> {
public:
    using Traits = FormatTraits<gpufmt::Format::E5B9G9R9_UFLOAT_PACK32>;

    [[nodiscard]]
    static constexpr Traits::ValueType lowest(Channel) noexcept {
        return 0.0f;
    }

    [[nodiscard]]
    static constexpr Traits::ValueType max(Channel) noexcept {
        return 65408.0f;
    }
};

namespace internal {
template<Format FormatValue>
class ClampToLimitsHelper {
public:
    using Traits = FormatTraits<FormatValue>;
    using Limits = FormatLimits<FormatValue>;

    template<class T>
    [[nodiscard]]
    static constexpr T clamp(Channel channel, T value) noexcept {
        if constexpr(std::is_same_v<Traits::ValueType, void>) {
            return T(0);
        } else {
            const auto castValue = static_cast<Traits::ValueType>(value);

            if(castValue > Limits::max(channel)) {
                if constexpr(sizeof(T) >= sizeof(Traits::ValueType)) {
                    return static_cast<T>(Limits::max(channel));
                } else {
                    return static_cast<T>(std::min(Limits::max(channel), static_cast<Traits::ValueType>(std::numeric_limits<T>::max())));
                }
            } else if(castValue < Limits::lowest(channel)) {
                if constexpr(sizeof(T) >= sizeof(Traits::ValueType)) {
                    return static_cast<T>(Limits::lowest(channel));
                } else {
                    return static_cast<T>(std::max(Limits::lowest(channel), static_cast<Traits::ValueType>(std::numeric_limits<T>::lowest())));
                }
            } else {
                return value;
            }
        }
    }

    [[nodiscard]]
    constexpr float operator()(Channel channel, float value) const noexcept {
        return clamp(channel, value);
    }

    [[nodiscard]]
    constexpr uint32_t operator()(Channel channel, uint32_t value) const noexcept {
        return clamp(channel, value);
    }

    [[nodiscard]]
    constexpr int32_t operator()(Channel channel, int32_t value) const noexcept {
        return clamp(channel, value);
    }

#ifndef GF_EXCLUDE_64BIT_FORMATS
    [[nodiscard]]
    constexpr double operator()(Channel channel, double value) const noexcept {
        return clamp(channel, value);
    }

    [[nodiscard]]
    constexpr uint64_t operator()(Channel channel, uint64_t value) const noexcept {
        return clamp(channel, value);
    }

    [[nodiscard]]
    constexpr int64_t operator()(Channel channel, int64_t value) const noexcept {
        return clamp(channel, value);
    }
#endif
};
} // namespace internal

[[nodiscard]]
constexpr float clampToFormatLimits(Format format, Channel channel, float value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}

[[nodiscard]]
constexpr int32_t clampToFormatLimits(Format format, Channel channel, int32_t value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}

[[nodiscard]]
constexpr uint32_t clampToFormatLimits(Format format, Channel channel, uint32_t value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}

#ifndef GF_EXCLUDE_64BIT_FORMATS
[[nodiscard]]
constexpr double clampToFormatLimits(Format format, Channel channel, double value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}

[[nodiscard]]
constexpr int64_t clampToFormatLimits(Format format, Channel channel, int64_t value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}

[[nodiscard]]
constexpr uint64_t clampToFormatLimits(Format format, Channel channel, uint64_t value) noexcept {
    return visitFormat<internal::ClampToLimitsHelper>(format, channel, value);
}
#endif // GF_EXCLUDE_64BIT_FORMATS
} // namespace gpufmt