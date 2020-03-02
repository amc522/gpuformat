#include <gpufmt/internal/bit_packing.h>

#include <catch.hpp>
#include <glm/glm.hpp>
using namespace gpufmt::internal;

TEST_CASE("packBits") {
    CHECK(packBits<uint32_t, 1, 0>(1) == 0b1);
    CHECK(packBits<uint32_t, 1, 1>(1) == 0b10);
    CHECK(packBits<uint32_t, 1, 2>(1) == 0b100);
    CHECK(packBits<uint32_t, 1, 3>(1) == 0b1000);
    CHECK(packBits<uint32_t, 1, 4>(1) == 0b10000);
    CHECK(packBits<uint32_t, 1, 5>(1) == 0b100000);
    CHECK(packBits<uint32_t, 1, 6>(1) == 0b1000000);
    CHECK(packBits<uint32_t, 1, 7>(1) == 0b10000000);
    CHECK(packBits<uint32_t, 1, 8>(1) == 0b100000000);
    CHECK(packBits<uint32_t, 1, 9>(1) == 0b1000000000);
    CHECK(packBits<uint32_t, 1, 10>(1) == 0b10000000000);
    CHECK(packBits<uint32_t, 1, 11>(1) == 0b100000000000);
    CHECK(packBits<uint32_t, 1, 12>(1) == 0b1000000000000);
    CHECK(packBits<uint32_t, 1, 13>(1) == 0b10000000000000);
    CHECK(packBits<uint32_t, 1, 14>(1) == 0b100000000000000);
    CHECK(packBits<uint32_t, 1, 15>(1) == 0b1000000000000000);
    CHECK(packBits<uint32_t, 1, 16>(1) == 0b10000000000000000);
    CHECK(packBits<uint32_t, 1, 17>(1) == 0b100000000000000000);
    CHECK(packBits<uint32_t, 1, 18>(1) == 0b1000000000000000000);
    CHECK(packBits<uint32_t, 1, 19>(1) == 0b10000000000000000000);
    CHECK(packBits<uint32_t, 1, 20>(1) == 0b100000000000000000000);
    CHECK(packBits<uint32_t, 1, 21>(1) == 0b1000000000000000000000);
    CHECK(packBits<uint32_t, 1, 22>(1) == 0b10000000000000000000000);
    CHECK(packBits<uint32_t, 1, 23>(1) == 0b100000000000000000000000);
    CHECK(packBits<uint32_t, 1, 24>(1) == 0b1000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 25>(1) == 0b10000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 26>(1) == 0b100000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 27>(1) == 0b1000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 28>(1) == 0b10000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 29>(1) == 0b100000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 30>(1) == 0b1000000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 31>(1) == 0b10000000000000000000000000000000);
    
    CHECK(packBits<uint32_t, 1, 0>(std::numeric_limits<uint32_t>::max()) == 0b1);
    CHECK(packBits<uint32_t, 1, 1>(std::numeric_limits<uint32_t>::max()) == 0b10);
    CHECK(packBits<uint32_t, 1, 2>(std::numeric_limits<uint32_t>::max()) == 0b100);
    CHECK(packBits<uint32_t, 1, 3>(std::numeric_limits<uint32_t>::max()) == 0b1000);
    CHECK(packBits<uint32_t, 1, 4>(std::numeric_limits<uint32_t>::max()) == 0b10000);
    CHECK(packBits<uint32_t, 1, 5>(std::numeric_limits<uint32_t>::max()) == 0b100000);
    CHECK(packBits<uint32_t, 1, 6>(std::numeric_limits<uint32_t>::max()) == 0b1000000);
    CHECK(packBits<uint32_t, 1, 7>(std::numeric_limits<uint32_t>::max()) == 0b10000000);
    CHECK(packBits<uint32_t, 1, 8>(std::numeric_limits<uint32_t>::max()) == 0b100000000);
    CHECK(packBits<uint32_t, 1, 9>(std::numeric_limits<uint32_t>::max()) == 0b1000000000);
    CHECK(packBits<uint32_t, 1, 10>(std::numeric_limits<uint32_t>::max()) == 0b10000000000);
    CHECK(packBits<uint32_t, 1, 11>(std::numeric_limits<uint32_t>::max()) == 0b100000000000);
    CHECK(packBits<uint32_t, 1, 12>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000);
    CHECK(packBits<uint32_t, 1, 13>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000);
    CHECK(packBits<uint32_t, 1, 14>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000);
    CHECK(packBits<uint32_t, 1, 15>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000);
    CHECK(packBits<uint32_t, 1, 16>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000);
    CHECK(packBits<uint32_t, 1, 17>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000000);
    CHECK(packBits<uint32_t, 1, 18>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000000);
    CHECK(packBits<uint32_t, 1, 19>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000000);
    CHECK(packBits<uint32_t, 1, 20>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000000000);
    CHECK(packBits<uint32_t, 1, 21>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000000000);
    CHECK(packBits<uint32_t, 1, 22>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000000000);
    CHECK(packBits<uint32_t, 1, 23>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000000000000);
    CHECK(packBits<uint32_t, 1, 24>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 25>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 26>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 27>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 28>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 29>(std::numeric_limits<uint32_t>::max()) == 0b100000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 30>(std::numeric_limits<uint32_t>::max()) == 0b1000000000000000000000000000000);
    CHECK(packBits<uint32_t, 1, 31>(std::numeric_limits<uint32_t>::max()) == 0b10000000000000000000000000000000);
}