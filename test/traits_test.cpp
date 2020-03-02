#include <gpufmt/traits.h>
#include <gpufmt/string.h>
#include <gpufmt/utility.h>

#include <catch.hpp>

template<gpufmt::Format FormatV>
class ComponentCountTester {
public:

    void operator()() const {
        if constexpr(FormatV != gpufmt::Format::UNDEFINED) {
            CHECK(gpufmt::FormatTraits<FormatV>::ComponentCount > 0);
            CHECK(gpufmt::FormatTraits<FormatV>::ComponentCount <= 4);
            CHECK(gpufmt::FormatTraits<FormatV>::info.componentCount > 0);
            CHECK(gpufmt::FormatTraits<FormatV>::info.componentCount <= 4);
        }
    }
};

TEST_CASE("Component count is valid") {
    for(gpufmt::Format format : gpufmt::FormatEnumerator()) {
        DYNAMIC_SECTION("gpufmt::Format::" << to_string(format)) {
            gpufmt::visitFormat<ComponentCountTester>(format);
        }
    }
}