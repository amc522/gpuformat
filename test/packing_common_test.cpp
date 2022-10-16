#include <gpufmt/internal/packing_common.h>
#include <catch.hpp>

#include <array>
#include <bitset>
#include <charconv>

using namespace gpufmt::internal;

template<class T, size_t Bits>
class BitMaskTestCallable {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        BitMaskTestCallable<T, Bits - 1>()();

        std::bitset<Bits> bits;

        for(size_t i = 0; i < Bits; ++i) {
            bits.set(i);
        }

        CHECK(bitMask<T, Bits>() == bits.to_ullong());
    }
};

template<class T>
class BitMaskTestCallable<T, 0> {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        CHECK(bitMask<T, 0>() == 0u);
    }
};

template<class T>
class BitMaskTest {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        BitMaskTestCallable<T, sizeof(T) * 8u>()();
    }
};

TEST_CASE("bitMask<uint8_t, N>", "[bitMask]") {
    BitMaskTest<uint8_t>()();
}

TEST_CASE("bitMask<uint16_t, N>", "[bitMask]") {
    BitMaskTest<uint16_t>()();
}

TEST_CASE("bitMask<uint32_t, N>", "[bitMask]") {
    BitMaskTest<uint32_t>()();
}

TEST_CASE("bitMask<uint64_t, N>", "[packSignedInt]") {
    BitMaskTest<uint64_t>()();
}

TEST_CASE("signedMin<int8_t, N>", "[signedInt]") {
    CHECK(signedMin<int8_t, 1>() == -1);
    CHECK(signedMin<int8_t, 2>() == -2);
    CHECK(signedMin<int8_t, 3>() == -4);
    CHECK(signedMin<int8_t, 4>() == -8);
    CHECK(signedMin<int8_t, 5>() == -16);
    CHECK(signedMin<int8_t, 6>() == -32);
    CHECK(signedMin<int8_t, 7>() == -64);
    CHECK(signedMin<int8_t, 8>() == -128);
}

TEST_CASE("signedMin<int16_t, N>", "[signedInt]") {
    CHECK(signedMin<int16_t, 1>() == -1);
    CHECK(signedMin<int16_t, 2>() == -2);
    CHECK(signedMin<int16_t, 3>() == -4);
    CHECK(signedMin<int16_t, 4>() == -8);
    CHECK(signedMin<int16_t, 5>() == -16);
    CHECK(signedMin<int16_t, 6>() == -32);
    CHECK(signedMin<int16_t, 7>() == -64);
    CHECK(signedMin<int16_t, 8>() == -128);
    CHECK(signedMin<int16_t, 9>() == -256);
    CHECK(signedMin<int16_t, 10>() == -512);
    CHECK(signedMin<int16_t, 11>() == -1024);
    CHECK(signedMin<int16_t, 12>() == -2048);
    CHECK(signedMin<int16_t, 13>() == -4096);
    CHECK(signedMin<int16_t, 14>() == -8192);
    CHECK(signedMin<int16_t, 15>() == -16384);
    CHECK(signedMin<int16_t, 16>() == -32768);

}

TEST_CASE("signedMin<int32_t, N>", "[signedInt]") {
    CHECK(signedMin<int32_t, 1>() == -1);
    CHECK(signedMin<int32_t, 2>() == -2);
    CHECK(signedMin<int32_t, 3>() == -4);
    CHECK(signedMin<int32_t, 4>() == -8);
    CHECK(signedMin<int32_t, 5>() == -16);
    CHECK(signedMin<int32_t, 6>() == -32);
    CHECK(signedMin<int32_t, 7>() == -64);
    CHECK(signedMin<int32_t, 8>() == -128);
    CHECK(signedMin<int32_t, 9>() == -256);
    CHECK(signedMin<int32_t, 10>() == -512);
    CHECK(signedMin<int32_t, 11>() == -1024);
    CHECK(signedMin<int32_t, 12>() == -2048);
    CHECK(signedMin<int32_t, 13>() == -4096);
    CHECK(signedMin<int32_t, 14>() == -8192);
    CHECK(signedMin<int32_t, 15>() == -16384);
    CHECK(signedMin<int32_t, 16>() == -32768);
    CHECK(signedMin<int32_t, 17>() == -65536);
    CHECK(signedMin<int32_t, 18>() == -131072);
    CHECK(signedMin<int32_t, 19>() == -262144);
    CHECK(signedMin<int32_t, 20>() == -524288);
    CHECK(signedMin<int32_t, 21>() == -1048576);
    CHECK(signedMin<int32_t, 22>() == -2097152);
    CHECK(signedMin<int32_t, 23>() == -4194304);
    CHECK(signedMin<int32_t, 24>() == -8388608);
    CHECK(signedMin<int32_t, 25>() == -16777216);
    CHECK(signedMin<int32_t, 26>() == -33554432);
    CHECK(signedMin<int32_t, 27>() == -67108864);
    CHECK(signedMin<int32_t, 28>() == -134217728);
    CHECK(signedMin<int32_t, 29>() == -268435456);
    CHECK(signedMin<int32_t, 30>() == -536870912);
    CHECK(signedMin<int32_t, 31>() == -1073741824);
    CHECK(signedMin<int32_t, 32>() == -2147483648LL);
}

TEST_CASE("signedMin<int64_t, N>", "[signedInt]") {
    CHECK(signedMin<int64_t, 1>() == -1);
    CHECK(signedMin<int64_t, 2>() == -2);
    CHECK(signedMin<int64_t, 3>() == -4);
    CHECK(signedMin<int64_t, 4>() == -8);
    CHECK(signedMin<int64_t, 5>() == -16);
    CHECK(signedMin<int64_t, 6>() == -32);
    CHECK(signedMin<int64_t, 7>() == -64);
    CHECK(signedMin<int64_t, 8>() == -128);
    CHECK(signedMin<int64_t, 9>() == -256);
    CHECK(signedMin<int64_t, 10>() == -512);
    CHECK(signedMin<int64_t, 11>() == -1024);
    CHECK(signedMin<int64_t, 12>() == -2048);
    CHECK(signedMin<int64_t, 13>() == -4096);
    CHECK(signedMin<int64_t, 14>() == -8192);
    CHECK(signedMin<int64_t, 15>() == -16384);
    CHECK(signedMin<int64_t, 16>() == -32768);
    CHECK(signedMin<int64_t, 17>() == -65536);
    CHECK(signedMin<int64_t, 18>() == -131072);
    CHECK(signedMin<int64_t, 19>() == -262144);
    CHECK(signedMin<int64_t, 20>() == -524288);
    CHECK(signedMin<int64_t, 21>() == -1048576);
    CHECK(signedMin<int64_t, 22>() == -2097152);
    CHECK(signedMin<int64_t, 23>() == -4194304);
    CHECK(signedMin<int64_t, 24>() == -8388608);
    CHECK(signedMin<int64_t, 25>() == -16777216);
    CHECK(signedMin<int64_t, 26>() == -33554432);
    CHECK(signedMin<int64_t, 27>() == -67108864);
    CHECK(signedMin<int64_t, 28>() == -134217728);
    CHECK(signedMin<int64_t, 29>() == -268435456);
    CHECK(signedMin<int64_t, 30>() == -536870912);
    CHECK(signedMin<int64_t, 31>() == -1073741824);
    CHECK(signedMin<int64_t, 32>() == -2147483648LL);
    CHECK(signedMin<int64_t, 33>() == -4294967296LL);
    CHECK(signedMin<int64_t, 34>() == -8589934592LL);
    CHECK(signedMin<int64_t, 35>() == -17179869184LL);
    CHECK(signedMin<int64_t, 36>() == -34359738368LL);
    CHECK(signedMin<int64_t, 37>() == -68719476736LL);
    CHECK(signedMin<int64_t, 38>() == -137438953472LL);
    CHECK(signedMin<int64_t, 39>() == -274877906944LL);
    CHECK(signedMin<int64_t, 40>() == -549755813888LL);
    CHECK(signedMin<int64_t, 41>() == -1099511627776LL);
    CHECK(signedMin<int64_t, 42>() == -2199023255552LL);
    CHECK(signedMin<int64_t, 43>() == -4398046511104LL);
    CHECK(signedMin<int64_t, 44>() == -8796093022208LL);
    CHECK(signedMin<int64_t, 45>() == -17592186044416LL);
    CHECK(signedMin<int64_t, 46>() == -35184372088832LL);
    CHECK(signedMin<int64_t, 47>() == -70368744177664LL);
    CHECK(signedMin<int64_t, 48>() == -140737488355328LL);
    CHECK(signedMin<int64_t, 49>() == -281474976710656LL);
    CHECK(signedMin<int64_t, 50>() == -562949953421312LL);
    CHECK(signedMin<int64_t, 51>() == -1125899906842624LL);
    CHECK(signedMin<int64_t, 52>() == -2251799813685248LL);
    CHECK(signedMin<int64_t, 53>() == -4503599627370496LL);
    CHECK(signedMin<int64_t, 54>() == -9007199254740992LL);
    CHECK(signedMin<int64_t, 55>() == -18014398509481984LL);
    CHECK(signedMin<int64_t, 56>() == -36028797018963968LL);
    CHECK(signedMin<int64_t, 57>() == -72057594037927936LL);
    CHECK(signedMin<int64_t, 58>() == -144115188075855872LL);
    CHECK(signedMin<int64_t, 59>() == -288230376151711744LL);
    CHECK(signedMin<int64_t, 60>() == -576460752303423488LL);
    CHECK(signedMin<int64_t, 61>() == -1152921504606846976LL);
    CHECK(signedMin<int64_t, 62>() == -2305843009213693952LL);
    CHECK(signedMin<int64_t, 63>() == -4611686018427387904LL);
    CHECK(signedMin<int64_t, 64>() == -9223372036854775808LL);
}

TEST_CASE("signedMin<int8_t>", "[signedInt]") {
    CHECK(signedMin<int8_t>(1) == -1);
    CHECK(signedMin<int8_t>(2) == -2);
    CHECK(signedMin<int8_t>(3) == -4);
    CHECK(signedMin<int8_t>(4) == -8);
    CHECK(signedMin<int8_t>(5) == -16);
    CHECK(signedMin<int8_t>(6) == -32);
    CHECK(signedMin<int8_t>(7) == -64);
    CHECK(signedMin<int8_t>(8) == -128);
}

TEST_CASE("signedMin<int16_t>", "[signedInt]") {
    CHECK(signedMin<int16_t>(1) == -1);
    CHECK(signedMin<int16_t>(2) == -2);
    CHECK(signedMin<int16_t>(3) == -4);
    CHECK(signedMin<int16_t>(4) == -8);
    CHECK(signedMin<int16_t>(5) == -16);
    CHECK(signedMin<int16_t>(6) == -32);
    CHECK(signedMin<int16_t>(7) == -64);
    CHECK(signedMin<int16_t>(8) == -128);
    CHECK(signedMin<int16_t>(9) == -256);
    CHECK(signedMin<int16_t>(10) == -512);
    CHECK(signedMin<int16_t>(11) == -1024);
    CHECK(signedMin<int16_t>(12) == -2048);
    CHECK(signedMin<int16_t>(13) == -4096);
    CHECK(signedMin<int16_t>(14) == -8192);
    CHECK(signedMin<int16_t>(15) == -16384);
    CHECK(signedMin<int16_t>(16) == -32768);

}

TEST_CASE("signedMin<int32_t>", "[signedInt]") {
    CHECK(signedMin<int32_t>(1) == -1);
    CHECK(signedMin<int32_t>(2) == -2);
    CHECK(signedMin<int32_t>(3) == -4);
    CHECK(signedMin<int32_t>(4) == -8);
    CHECK(signedMin<int32_t>(5) == -16);
    CHECK(signedMin<int32_t>(6) == -32);
    CHECK(signedMin<int32_t>(7) == -64);
    CHECK(signedMin<int32_t>(8) == -128);
    CHECK(signedMin<int32_t>(9) == -256);
    CHECK(signedMin<int32_t>(10) == -512);
    CHECK(signedMin<int32_t>(11) == -1024);
    CHECK(signedMin<int32_t>(12) == -2048);
    CHECK(signedMin<int32_t>(13) == -4096);
    CHECK(signedMin<int32_t>(14) == -8192);
    CHECK(signedMin<int32_t>(15) == -16384);
    CHECK(signedMin<int32_t>(16) == -32768);
    CHECK(signedMin<int32_t>(17) == -65536);
    CHECK(signedMin<int32_t>(18) == -131072);
    CHECK(signedMin<int32_t>(19) == -262144);
    CHECK(signedMin<int32_t>(20) == -524288);
    CHECK(signedMin<int32_t>(21) == -1048576);
    CHECK(signedMin<int32_t>(22) == -2097152);
    CHECK(signedMin<int32_t>(23) == -4194304);
    CHECK(signedMin<int32_t>(24) == -8388608);
    CHECK(signedMin<int32_t>(25) == -16777216);
    CHECK(signedMin<int32_t>(26) == -33554432);
    CHECK(signedMin<int32_t>(27) == -67108864);
    CHECK(signedMin<int32_t>(28) == -134217728);
    CHECK(signedMin<int32_t>(29) == -268435456);
    CHECK(signedMin<int32_t>(30) == -536870912);
    CHECK(signedMin<int32_t>(31) == -1073741824);
    CHECK(signedMin<int32_t>(32) == -2147483648LL);
}

TEST_CASE("signedMin<int64_t>", "[signedInt]") {
    CHECK(signedMin<int64_t>(1) == -1);
    CHECK(signedMin<int64_t>(2) == -2);
    CHECK(signedMin<int64_t>(3) == -4);
    CHECK(signedMin<int64_t>(4) == -8);
    CHECK(signedMin<int64_t>(5) == -16);
    CHECK(signedMin<int64_t>(6) == -32);
    CHECK(signedMin<int64_t>(7) == -64);
    CHECK(signedMin<int64_t>(8) == -128);
    CHECK(signedMin<int64_t>(9) == -256);
    CHECK(signedMin<int64_t>(10) == -512);
    CHECK(signedMin<int64_t>(11) == -1024);
    CHECK(signedMin<int64_t>(12) == -2048);
    CHECK(signedMin<int64_t>(13) == -4096);
    CHECK(signedMin<int64_t>(14) == -8192);
    CHECK(signedMin<int64_t>(15) == -16384);
    CHECK(signedMin<int64_t>(16) == -32768);
    CHECK(signedMin<int64_t>(17) == -65536);
    CHECK(signedMin<int64_t>(18) == -131072);
    CHECK(signedMin<int64_t>(19) == -262144);
    CHECK(signedMin<int64_t>(20) == -524288);
    CHECK(signedMin<int64_t>(21) == -1048576);
    CHECK(signedMin<int64_t>(22) == -2097152);
    CHECK(signedMin<int64_t>(23) == -4194304);
    CHECK(signedMin<int64_t>(24) == -8388608);
    CHECK(signedMin<int64_t>(25) == -16777216);
    CHECK(signedMin<int64_t>(26) == -33554432);
    CHECK(signedMin<int64_t>(27) == -67108864);
    CHECK(signedMin<int64_t>(28) == -134217728);
    CHECK(signedMin<int64_t>(29) == -268435456);
    CHECK(signedMin<int64_t>(30) == -536870912);
    CHECK(signedMin<int64_t>(31) == -1073741824);
    CHECK(signedMin<int64_t>(32) == -2147483648LL);
    CHECK(signedMin<int64_t>(33) == -4294967296LL);
    CHECK(signedMin<int64_t>(34) == -8589934592LL);
    CHECK(signedMin<int64_t>(35) == -17179869184LL);
    CHECK(signedMin<int64_t>(36) == -34359738368LL);
    CHECK(signedMin<int64_t>(37) == -68719476736LL);
    CHECK(signedMin<int64_t>(38) == -137438953472LL);
    CHECK(signedMin<int64_t>(39) == -274877906944LL);
    CHECK(signedMin<int64_t>(40) == -549755813888LL);
    CHECK(signedMin<int64_t>(41) == -1099511627776LL);
    CHECK(signedMin<int64_t>(42) == -2199023255552LL);
    CHECK(signedMin<int64_t>(43) == -4398046511104LL);
    CHECK(signedMin<int64_t>(44) == -8796093022208LL);
    CHECK(signedMin<int64_t>(45) == -17592186044416LL);
    CHECK(signedMin<int64_t>(46) == -35184372088832LL);
    CHECK(signedMin<int64_t>(47) == -70368744177664LL);
    CHECK(signedMin<int64_t>(48) == -140737488355328LL);
    CHECK(signedMin<int64_t>(49) == -281474976710656LL);
    CHECK(signedMin<int64_t>(50) == -562949953421312LL);
    CHECK(signedMin<int64_t>(51) == -1125899906842624LL);
    CHECK(signedMin<int64_t>(52) == -2251799813685248LL);
    CHECK(signedMin<int64_t>(53) == -4503599627370496LL);
    CHECK(signedMin<int64_t>(54) == -9007199254740992LL);
    CHECK(signedMin<int64_t>(55) == -18014398509481984LL);
    CHECK(signedMin<int64_t>(56) == -36028797018963968LL);
    CHECK(signedMin<int64_t>(57) == -72057594037927936LL);
    CHECK(signedMin<int64_t>(58) == -144115188075855872LL);
    CHECK(signedMin<int64_t>(59) == -288230376151711744LL);
    CHECK(signedMin<int64_t>(60) == -576460752303423488LL);
    CHECK(signedMin<int64_t>(61) == -1152921504606846976LL);
    CHECK(signedMin<int64_t>(62) == -2305843009213693952LL);
    CHECK(signedMin<int64_t>(63) == -4611686018427387904LL);
    CHECK(signedMin<int64_t>(64) == -9223372036854775808LL);
}

TEST_CASE("signedMax<int8_t, N>", "[signedInt]") {
    CHECK(signedMax<int8_t, 1>() == 0);
    CHECK(signedMax<int8_t, 2>() == 1);
    CHECK(signedMax<int8_t, 3>() == 3);
    CHECK(signedMax<int8_t, 4>() == 7);
    CHECK(signedMax<int8_t, 5>() == 15);
    CHECK(signedMax<int8_t, 6>() == 31);
    CHECK(signedMax<int8_t, 7>() == 63);
    CHECK(signedMax<int8_t, 8>() == 127);
}

TEST_CASE("signedMax<int16_t, N>", "[signedInt]") {
    CHECK(signedMax<int16_t, 1>() == 0);
    CHECK(signedMax<int16_t, 2>() == 1);
    CHECK(signedMax<int16_t, 3>() == 3);
    CHECK(signedMax<int16_t, 4>() == 7);
    CHECK(signedMax<int16_t, 5>() == 15);
    CHECK(signedMax<int16_t, 6>() == 31);
    CHECK(signedMax<int16_t, 7>() == 63);
    CHECK(signedMax<int16_t, 8>() == 127);
    CHECK(signedMax<int16_t, 9>() == 255);
    CHECK(signedMax<int16_t, 10>() == 511);
    CHECK(signedMax<int16_t, 11>() == 1023);
    CHECK(signedMax<int16_t, 12>() == 2047);
    CHECK(signedMax<int16_t, 13>() == 4095);
    CHECK(signedMax<int16_t, 14>() == 8191);
    CHECK(signedMax<int16_t, 15>() == 16383);
    CHECK(signedMax<int16_t, 16>() == 32767);
}

TEST_CASE("signedMax<int32_t, N>", "[signedInt]") {
    CHECK(signedMax<int32_t, 1>() == 0);
    CHECK(signedMax<int32_t, 2>() == 1);
    CHECK(signedMax<int32_t, 3>() == 3);
    CHECK(signedMax<int32_t, 4>() == 7);
    CHECK(signedMax<int32_t, 5>() == 15);
    CHECK(signedMax<int32_t, 6>() == 31);
    CHECK(signedMax<int32_t, 7>() == 63);
    CHECK(signedMax<int32_t, 8>() == 127);
    CHECK(signedMax<int32_t, 9>() == 255);
    CHECK(signedMax<int32_t, 10>() == 511);
    CHECK(signedMax<int32_t, 11>() == 1023);
    CHECK(signedMax<int32_t, 12>() == 2047);
    CHECK(signedMax<int32_t, 13>() == 4095);
    CHECK(signedMax<int32_t, 14>() == 8191);
    CHECK(signedMax<int32_t, 15>() == 16383);
    CHECK(signedMax<int32_t, 16>() == 32767);
    CHECK(signedMax<int32_t, 17>() == 65535);
    CHECK(signedMax<int32_t, 18>() == 131071);
    CHECK(signedMax<int32_t, 19>() == 262143);
    CHECK(signedMax<int32_t, 20>() == 524287);
    CHECK(signedMax<int32_t, 21>() == 1048575);
    CHECK(signedMax<int32_t, 22>() == 2097151);
    CHECK(signedMax<int32_t, 23>() == 4194303);
    CHECK(signedMax<int32_t, 24>() == 8388607);
    CHECK(signedMax<int32_t, 25>() == 16777215);
    CHECK(signedMax<int32_t, 26>() == 33554431);
    CHECK(signedMax<int32_t, 27>() == 67108863);
    CHECK(signedMax<int32_t, 28>() == 134217727);
    CHECK(signedMax<int32_t, 29>() == 268435455);
    CHECK(signedMax<int32_t, 30>() == 536870911);
    CHECK(signedMax<int32_t, 31>() == 1073741823);
    CHECK(signedMax<int32_t, 32>() == 2147483647LL);
}

TEST_CASE("signedMax<int64_t, N>", "[signedInt]") {
    CHECK(signedMax<int64_t, 1>() == 0);
    CHECK(signedMax<int64_t, 2>() == 1);
    CHECK(signedMax<int64_t, 3>() == 3);
    CHECK(signedMax<int64_t, 4>() == 7);
    CHECK(signedMax<int64_t, 5>() == 15);
    CHECK(signedMax<int64_t, 6>() == 31);
    CHECK(signedMax<int64_t, 7>() == 63);
    CHECK(signedMax<int64_t, 8>() == 127);
    CHECK(signedMax<int64_t, 9>() == 255);
    CHECK(signedMax<int64_t, 10>() == 511);
    CHECK(signedMax<int64_t, 11>() == 1023);
    CHECK(signedMax<int64_t, 12>() == 2047);
    CHECK(signedMax<int64_t, 13>() == 4095);
    CHECK(signedMax<int64_t, 14>() == 8191);
    CHECK(signedMax<int64_t, 15>() == 16383);
    CHECK(signedMax<int64_t, 16>() == 32767);
    CHECK(signedMax<int64_t, 17>() == 65535);
    CHECK(signedMax<int64_t, 18>() == 131071);
    CHECK(signedMax<int64_t, 19>() == 262143);
    CHECK(signedMax<int64_t, 20>() == 524287);
    CHECK(signedMax<int64_t, 21>() == 1048575);
    CHECK(signedMax<int64_t, 22>() == 2097151);
    CHECK(signedMax<int64_t, 23>() == 4194303);
    CHECK(signedMax<int64_t, 24>() == 8388607);
    CHECK(signedMax<int64_t, 25>() == 16777215);
    CHECK(signedMax<int64_t, 26>() == 33554431);
    CHECK(signedMax<int64_t, 27>() == 67108863);
    CHECK(signedMax<int64_t, 28>() == 134217727);
    CHECK(signedMax<int64_t, 29>() == 268435455);
    CHECK(signedMax<int64_t, 30>() == 536870911);
    CHECK(signedMax<int64_t, 31>() == 1073741823);
    CHECK(signedMax<int64_t, 32>() == 2147483647LL);
    CHECK(signedMax<int64_t, 33>() == 4294967295LL);
    CHECK(signedMax<int64_t, 34>() == 8589934591LL);
    CHECK(signedMax<int64_t, 35>() == 17179869183LL);
    CHECK(signedMax<int64_t, 36>() == 34359738367LL);
    CHECK(signedMax<int64_t, 37>() == 68719476735LL);
    CHECK(signedMax<int64_t, 38>() == 137438953471LL);
    CHECK(signedMax<int64_t, 39>() == 274877906943LL);
    CHECK(signedMax<int64_t, 40>() == 549755813887LL);
    CHECK(signedMax<int64_t, 41>() == 1099511627775LL);
    CHECK(signedMax<int64_t, 42>() == 2199023255551LL);
    CHECK(signedMax<int64_t, 43>() == 4398046511103LL);
    CHECK(signedMax<int64_t, 44>() == 8796093022207LL);
    CHECK(signedMax<int64_t, 45>() == 17592186044415LL);
    CHECK(signedMax<int64_t, 46>() == 35184372088831LL);
    CHECK(signedMax<int64_t, 47>() == 70368744177663LL);
    CHECK(signedMax<int64_t, 48>() == 140737488355327LL);
    CHECK(signedMax<int64_t, 49>() == 281474976710655LL);
    CHECK(signedMax<int64_t, 50>() == 562949953421311LL);
    CHECK(signedMax<int64_t, 51>() == 1125899906842623LL);
    CHECK(signedMax<int64_t, 52>() == 2251799813685247LL);
    CHECK(signedMax<int64_t, 53>() == 4503599627370495LL);
    CHECK(signedMax<int64_t, 54>() == 9007199254740991LL);
    CHECK(signedMax<int64_t, 55>() == 18014398509481983LL);
    CHECK(signedMax<int64_t, 56>() == 36028797018963967LL);
    CHECK(signedMax<int64_t, 57>() == 72057594037927935LL);
    CHECK(signedMax<int64_t, 58>() == 144115188075855871LL);
    CHECK(signedMax<int64_t, 59>() == 288230376151711743LL);
    CHECK(signedMax<int64_t, 60>() == 576460752303423487LL);
    CHECK(signedMax<int64_t, 61>() == 1152921504606846975LL);
    CHECK(signedMax<int64_t, 62>() == 2305843009213693951LL);
    CHECK(signedMax<int64_t, 63>() == 4611686018427387903LL);
    CHECK(signedMax<int64_t, 64>() == 9223372036854775807LL);
}

TEST_CASE("signedMax<int8_t>", "[signedInt]") {
    CHECK(signedMax<int8_t>(1) == 0);
    CHECK(signedMax<int8_t>(2) == 1);
    CHECK(signedMax<int8_t>(3) == 3);
    CHECK(signedMax<int8_t>(4) == 7);
    CHECK(signedMax<int8_t>(5) == 15);
    CHECK(signedMax<int8_t>(6) == 31);
    CHECK(signedMax<int8_t>(7) == 63);
    CHECK(signedMax<int8_t>(8) == 127);
}

TEST_CASE("signedMax<int16_t>", "[signedInt]") {
    CHECK(signedMax<int16_t>(1) == 0);
    CHECK(signedMax<int16_t>(2) == 1);
    CHECK(signedMax<int16_t>(3) == 3);
    CHECK(signedMax<int16_t>(4) == 7);
    CHECK(signedMax<int16_t>(5) == 15);
    CHECK(signedMax<int16_t>(6) == 31);
    CHECK(signedMax<int16_t>(7) == 63);
    CHECK(signedMax<int16_t>(8) == 127);
    CHECK(signedMax<int16_t>(9) == 255);
    CHECK(signedMax<int16_t>(10) == 511);
    CHECK(signedMax<int16_t>(11) == 1023);
    CHECK(signedMax<int16_t>(12) == 2047);
    CHECK(signedMax<int16_t>(13) == 4095);
    CHECK(signedMax<int16_t>(14) == 8191);
    CHECK(signedMax<int16_t>(15) == 16383);
    CHECK(signedMax<int16_t>(16) == 32767);
}

TEST_CASE("signedMax<int32_t>", "[signedInt]") {
    CHECK(signedMax<int32_t>(1) == 0);
    CHECK(signedMax<int32_t>(2) == 1);
    CHECK(signedMax<int32_t>(3) == 3);
    CHECK(signedMax<int32_t>(4) == 7);
    CHECK(signedMax<int32_t>(5) == 15);
    CHECK(signedMax<int32_t>(6) == 31);
    CHECK(signedMax<int32_t>(7) == 63);
    CHECK(signedMax<int32_t>(8) == 127);
    CHECK(signedMax<int32_t>(9) == 255);
    CHECK(signedMax<int32_t>(10) == 511);
    CHECK(signedMax<int32_t>(11) == 1023);
    CHECK(signedMax<int32_t>(12) == 2047);
    CHECK(signedMax<int32_t>(13) == 4095);
    CHECK(signedMax<int32_t>(14) == 8191);
    CHECK(signedMax<int32_t>(15) == 16383);
    CHECK(signedMax<int32_t>(16) == 32767);
    CHECK(signedMax<int32_t>(17) == 65535);
    CHECK(signedMax<int32_t>(18) == 131071);
    CHECK(signedMax<int32_t>(19) == 262143);
    CHECK(signedMax<int32_t>(20) == 524287);
    CHECK(signedMax<int32_t>(21) == 1048575);
    CHECK(signedMax<int32_t>(22) == 2097151);
    CHECK(signedMax<int32_t>(23) == 4194303);
    CHECK(signedMax<int32_t>(24) == 8388607);
    CHECK(signedMax<int32_t>(25) == 16777215);
    CHECK(signedMax<int32_t>(26) == 33554431);
    CHECK(signedMax<int32_t>(27) == 67108863);
    CHECK(signedMax<int32_t>(28) == 134217727);
    CHECK(signedMax<int32_t>(29) == 268435455);
    CHECK(signedMax<int32_t>(30) == 536870911);
    CHECK(signedMax<int32_t>(31) == 1073741823);
    CHECK(signedMax<int32_t>(32) == 2147483647LL);
}

TEST_CASE("signedMax<int64_t>", "[signedInt]") {
    CHECK(signedMax<int64_t>(1) == 0);
    CHECK(signedMax<int64_t>(2) == 1);
    CHECK(signedMax<int64_t>(3) == 3);
    CHECK(signedMax<int64_t>(4) == 7);
    CHECK(signedMax<int64_t>(5) == 15);
    CHECK(signedMax<int64_t>(6) == 31);
    CHECK(signedMax<int64_t>(7) == 63);
    CHECK(signedMax<int64_t>(8) == 127);
    CHECK(signedMax<int64_t>(9) == 255);
    CHECK(signedMax<int64_t>(10) == 511);
    CHECK(signedMax<int64_t>(11) == 1023);
    CHECK(signedMax<int64_t>(12) == 2047);
    CHECK(signedMax<int64_t>(13) == 4095);
    CHECK(signedMax<int64_t>(14) == 8191);
    CHECK(signedMax<int64_t>(15) == 16383);
    CHECK(signedMax<int64_t>(16) == 32767);
    CHECK(signedMax<int64_t>(17) == 65535);
    CHECK(signedMax<int64_t>(18) == 131071);
    CHECK(signedMax<int64_t>(19) == 262143);
    CHECK(signedMax<int64_t>(20) == 524287);
    CHECK(signedMax<int64_t>(21) == 1048575);
    CHECK(signedMax<int64_t>(22) == 2097151);
    CHECK(signedMax<int64_t>(23) == 4194303);
    CHECK(signedMax<int64_t>(24) == 8388607);
    CHECK(signedMax<int64_t>(25) == 16777215);
    CHECK(signedMax<int64_t>(26) == 33554431);
    CHECK(signedMax<int64_t>(27) == 67108863);
    CHECK(signedMax<int64_t>(28) == 134217727);
    CHECK(signedMax<int64_t>(29) == 268435455);
    CHECK(signedMax<int64_t>(30) == 536870911);
    CHECK(signedMax<int64_t>(31) == 1073741823);
    CHECK(signedMax<int64_t>(32) == 2147483647LL);
    CHECK(signedMax<int64_t>(33) == 4294967295LL);
    CHECK(signedMax<int64_t>(34) == 8589934591LL);
    CHECK(signedMax<int64_t>(35) == 17179869183LL);
    CHECK(signedMax<int64_t>(36) == 34359738367LL);
    CHECK(signedMax<int64_t>(37) == 68719476735LL);
    CHECK(signedMax<int64_t>(38) == 137438953471LL);
    CHECK(signedMax<int64_t>(39) == 274877906943LL);
    CHECK(signedMax<int64_t>(40) == 549755813887LL);
    CHECK(signedMax<int64_t>(41) == 1099511627775LL);
    CHECK(signedMax<int64_t>(42) == 2199023255551LL);
    CHECK(signedMax<int64_t>(43) == 4398046511103LL);
    CHECK(signedMax<int64_t>(44) == 8796093022207LL);
    CHECK(signedMax<int64_t>(45) == 17592186044415LL);
    CHECK(signedMax<int64_t>(46) == 35184372088831LL);
    CHECK(signedMax<int64_t>(47) == 70368744177663LL);
    CHECK(signedMax<int64_t>(48) == 140737488355327LL);
    CHECK(signedMax<int64_t>(49) == 281474976710655LL);
    CHECK(signedMax<int64_t>(50) == 562949953421311LL);
    CHECK(signedMax<int64_t>(51) == 1125899906842623LL);
    CHECK(signedMax<int64_t>(52) == 2251799813685247LL);
    CHECK(signedMax<int64_t>(53) == 4503599627370495LL);
    CHECK(signedMax<int64_t>(54) == 9007199254740991LL);
    CHECK(signedMax<int64_t>(55) == 18014398509481983LL);
    CHECK(signedMax<int64_t>(56) == 36028797018963967LL);
    CHECK(signedMax<int64_t>(57) == 72057594037927935LL);
    CHECK(signedMax<int64_t>(58) == 144115188075855871LL);
    CHECK(signedMax<int64_t>(59) == 288230376151711743LL);
    CHECK(signedMax<int64_t>(60) == 576460752303423487LL);
    CHECK(signedMax<int64_t>(61) == 1152921504606846975LL);
    CHECK(signedMax<int64_t>(62) == 2305843009213693951LL);
    CHECK(signedMax<int64_t>(63) == 4611686018427387903LL);
    CHECK(signedMax<int64_t>(64) == 9223372036854775807LL);
}

TEST_CASE("unsignedMax<uint8_t>", "[unsignedInt]") {
    CHECK(unsignedMax<uint8_t>(1) == 1);
    CHECK(unsignedMax<uint8_t>(2) == 3);
    CHECK(unsignedMax<uint8_t>(3) == 7);
    CHECK(unsignedMax<uint8_t>(4) == 15);
    CHECK(unsignedMax<uint8_t>(5) == 31);
    CHECK(unsignedMax<uint8_t>(6) == 63);
    CHECK(unsignedMax<uint8_t>(7) == 127);
    CHECK(unsignedMax<uint8_t>(8) == 255);
}

TEST_CASE("unsignedMax<uint16_t>", "[unsignedInt]") {
    CHECK(unsignedMax<uint16_t>(1) == 1);
    CHECK(unsignedMax<uint16_t>(2) == 3);
    CHECK(unsignedMax<uint16_t>(3) == 7);
    CHECK(unsignedMax<uint16_t>(4) == 15);
    CHECK(unsignedMax<uint16_t>(5) == 31);
    CHECK(unsignedMax<uint16_t>(6) == 63);
    CHECK(unsignedMax<uint16_t>(7) == 127);
    CHECK(unsignedMax<uint16_t>(8) == 255);
    CHECK(unsignedMax<uint16_t>(9) == 511);
    CHECK(unsignedMax<uint16_t>(10) == 1023);
    CHECK(unsignedMax<uint16_t>(11) == 2047);
    CHECK(unsignedMax<uint16_t>(12) == 4095);
    CHECK(unsignedMax<uint16_t>(13) == 8191);
    CHECK(unsignedMax<uint16_t>(14) == 16383);
    CHECK(unsignedMax<uint16_t>(15) == 32767);
    CHECK(unsignedMax<uint16_t>(16) == 65535);
}

TEST_CASE("unsignedMax<uint32_t>", "[unsignedInt]") {
    CHECK(unsignedMax<uint32_t>(1) == 1);
    CHECK(unsignedMax<uint32_t>(2) == 3);
    CHECK(unsignedMax<uint32_t>(3) == 7);
    CHECK(unsignedMax<uint32_t>(4) == 15);
    CHECK(unsignedMax<uint32_t>(5) == 31);
    CHECK(unsignedMax<uint32_t>(6) == 63);
    CHECK(unsignedMax<uint32_t>(7) == 127);
    CHECK(unsignedMax<uint32_t>(8) == 255);
    CHECK(unsignedMax<uint32_t>(9) == 511);
    CHECK(unsignedMax<uint32_t>(10) == 1023);
    CHECK(unsignedMax<uint32_t>(11) == 2047);
    CHECK(unsignedMax<uint32_t>(12) == 4095);
    CHECK(unsignedMax<uint32_t>(13) == 8191);
    CHECK(unsignedMax<uint32_t>(14) == 16383);
    CHECK(unsignedMax<uint32_t>(15) == 32767);
    CHECK(unsignedMax<uint32_t>(16) == 65535);
    CHECK(unsignedMax<uint32_t>(17) == 131071);
    CHECK(unsignedMax<uint32_t>(18) == 262143);
    CHECK(unsignedMax<uint32_t>(19) == 524287);
    CHECK(unsignedMax<uint32_t>(20) == 1048575);
    CHECK(unsignedMax<uint32_t>(21) == 2097151);
    CHECK(unsignedMax<uint32_t>(22) == 4194303);
    CHECK(unsignedMax<uint32_t>(23) == 8388607);
    CHECK(unsignedMax<uint32_t>(24) == 16777215);
    CHECK(unsignedMax<uint32_t>(25) == 33554431);
    CHECK(unsignedMax<uint32_t>(26) == 67108863);
    CHECK(unsignedMax<uint32_t>(27) == 134217727);
    CHECK(unsignedMax<uint32_t>(28) == 268435455);
    CHECK(unsignedMax<uint32_t>(29) == 536870911);
    CHECK(unsignedMax<uint32_t>(30) == 1073741823);
    CHECK(unsignedMax<uint32_t>(31) == 2147483647LL);
    CHECK(unsignedMax<uint32_t>(32) == 4294967295LL);
}

TEST_CASE("unsignedMax<uint64_t>", "[unsignedInt]") {
    CHECK(unsignedMax<uint64_t>(1) == 1);
    CHECK(unsignedMax<uint64_t>(2) == 3);
    CHECK(unsignedMax<uint64_t>(3) == 7);
    CHECK(unsignedMax<uint64_t>(4) == 15);
    CHECK(unsignedMax<uint64_t>(5) == 31);
    CHECK(unsignedMax<uint64_t>(6) == 63);
    CHECK(unsignedMax<uint64_t>(7) == 127);
    CHECK(unsignedMax<uint64_t>(8) == 255);
    CHECK(unsignedMax<uint64_t>(9) == 511);
    CHECK(unsignedMax<uint64_t>(10) == 1023);
    CHECK(unsignedMax<uint64_t>(11) == 2047);
    CHECK(unsignedMax<uint64_t>(12) == 4095);
    CHECK(unsignedMax<uint64_t>(13) == 8191);
    CHECK(unsignedMax<uint64_t>(14) == 16383);
    CHECK(unsignedMax<uint64_t>(15) == 32767);
    CHECK(unsignedMax<uint64_t>(16) == 65535);
    CHECK(unsignedMax<uint64_t>(17) == 131071);
    CHECK(unsignedMax<uint64_t>(18) == 262143);
    CHECK(unsignedMax<uint64_t>(19) == 524287);
    CHECK(unsignedMax<uint64_t>(20) == 1048575);
    CHECK(unsignedMax<uint64_t>(21) == 2097151);
    CHECK(unsignedMax<uint64_t>(22) == 4194303);
    CHECK(unsignedMax<uint64_t>(23) == 8388607);
    CHECK(unsignedMax<uint64_t>(24) == 16777215);
    CHECK(unsignedMax<uint64_t>(25) == 33554431);
    CHECK(unsignedMax<uint64_t>(26) == 67108863);
    CHECK(unsignedMax<uint64_t>(27) == 134217727);
    CHECK(unsignedMax<uint64_t>(28) == 268435455);
    CHECK(unsignedMax<uint64_t>(29) == 536870911);
    CHECK(unsignedMax<uint64_t>(30) == 1073741823);
    CHECK(unsignedMax<uint64_t>(31) == 2147483647LL);
    CHECK(unsignedMax<uint64_t>(32) == 4294967295LL);
    CHECK(unsignedMax<uint64_t>(33) == 8589934591LL);
    CHECK(unsignedMax<uint64_t>(34) == 17179869183LL);
    CHECK(unsignedMax<uint64_t>(35) == 34359738367LL);
    CHECK(unsignedMax<uint64_t>(36) == 68719476735LL);
    CHECK(unsignedMax<uint64_t>(37) == 137438953471LL);
    CHECK(unsignedMax<uint64_t>(38) == 274877906943LL);
    CHECK(unsignedMax<uint64_t>(39) == 549755813887LL);
    CHECK(unsignedMax<uint64_t>(40) == 1099511627775LL);
    CHECK(unsignedMax<uint64_t>(41) == 2199023255551LL);
    CHECK(unsignedMax<uint64_t>(42) == 4398046511103LL);
    CHECK(unsignedMax<uint64_t>(43) == 8796093022207LL);
    CHECK(unsignedMax<uint64_t>(44) == 17592186044415LL);
    CHECK(unsignedMax<uint64_t>(45) == 35184372088831LL);
    CHECK(unsignedMax<uint64_t>(46) == 70368744177663LL);
    CHECK(unsignedMax<uint64_t>(47) == 140737488355327LL);
    CHECK(unsignedMax<uint64_t>(48) == 281474976710655LL);
    CHECK(unsignedMax<uint64_t>(49) == 562949953421311LL);
    CHECK(unsignedMax<uint64_t>(50) == 1125899906842623LL);
    CHECK(unsignedMax<uint64_t>(51) == 2251799813685247LL);
    CHECK(unsignedMax<uint64_t>(52) == 4503599627370495LL);
    CHECK(unsignedMax<uint64_t>(53) == 9007199254740991LL);
    CHECK(unsignedMax<uint64_t>(54) == 18014398509481983LL);
    CHECK(unsignedMax<uint64_t>(55) == 36028797018963967LL);
    CHECK(unsignedMax<uint64_t>(56) == 72057594037927935LL);
    CHECK(unsignedMax<uint64_t>(57) == 144115188075855871LL);
    CHECK(unsignedMax<uint64_t>(58) == 288230376151711743LL);
    CHECK(unsignedMax<uint64_t>(59) == 576460752303423487LL);
    CHECK(unsignedMax<uint64_t>(60) == 1152921504606846975LL);
    CHECK(unsignedMax<uint64_t>(61) == 2305843009213693951LL);
    CHECK(unsignedMax<uint64_t>(62) == 4611686018427387903LL);
    CHECK(unsignedMax<uint64_t>(63) == 9223372036854775807LL);
    CHECK(unsignedMax<uint64_t>(64) == 18446744073709551615LL);
}

template<class T, size_t Bits>
class PackSignedIntTestCallable {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        if constexpr(Bits > 1) {
            PackSignedIntTestCallable<T, Bits - 1>()();
        }

        for(T i = 0; i < signedMax<T, Bits>(); ++i) {
            T expected = std::clamp(i, signedMin<T, Bits>(), signedMax<T, Bits>());
            REQUIRE(packSignedInt<T, Bits>(i) == std::make_unsigned_t<T>(expected));
        }

        std::make_unsigned_t<T> expected(signedMax<T, Bits>());
        expected += 2;
        for(T i = signedMin<T, Bits>() + 1; i < 0; ++i) {
            REQUIRE(packSignedInt<T, Bits>(i) == expected);
            ++expected;
        }

        REQUIRE(packSignedInt<T, Bits>(signedMax<T, Bits>()) == std::make_unsigned_t<T>(signedMax<T, Bits>()));
        REQUIRE(packSignedInt<T, Bits>(std::numeric_limits<T>::min()) == std::make_unsigned_t<T>(signedMax<T, Bits>()) + 1);
        REQUIRE(packSignedInt<T, Bits>(std::numeric_limits<T>::max()) == std::make_unsigned_t<T>(signedMax<T, Bits>()));
    }
};

template<class T>
class PackSignedIntTest {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        PackSignedIntTestCallable<T, sizeof(T) * 8u>()();
    }
};

TEST_CASE("packSignedInt<int8_t, N>", "[signedInt]") {
    PackSignedIntTest<int8_t>()();
}

TEST_CASE("packSignedInt<int16_t, N>", "[signedInt]") {
    PackSignedIntTest<int16_t>()();
}

TEST_CASE("packSignedInt<int32_t, N>", "[signedInt][!hide]") {
    PackSignedIntTest<int32_t>()();
}

TEST_CASE("packSignedInt<int64_t, N>", "[signedInt][!hide]") {
    PackSignedIntTest<int64_t>()();
}

template<class T, size_t Bits>
class UnpackSignedIntTestCallable {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        if constexpr(Bits > 1) {
            UnpackSignedIntTestCallable<T, Bits - 1>()();
        }

        for(T i = signedMin<T, Bits>(); i < signedMax<T, Bits>(); ++i) {
            T expected = i;
            auto packed = packSignedInt<T, Bits>(i);
            auto unpacked = unpackSignedInt<decltype(packed), Bits>(packed);
            CHECK(unpacked == expected);
        }
        
        {
            T expected = signedMax<T, Bits>();
            auto packed = packSignedInt<T, Bits>(expected);
            auto unpacked = unpackSignedInt<decltype(packed), Bits>(packed);
            CHECK(unpacked == expected);
        }

        {
            auto packed = packSignedInt<T, Bits>(std::numeric_limits<T>::min());
            auto unpacked = unpackSignedInt<decltype(packed), Bits>(packed);
            CHECK(unpacked == signedMin<T, Bits>());
        }

        {
            auto packed = packSignedInt<T, Bits>(std::numeric_limits<T>::max());
            auto unpacked = unpackSignedInt<decltype(packed), Bits>(packed);
            CHECK(unpacked == signedMax<T, Bits>());
        }
    }
};

template<class T>
class UnpackSignedIntTest {
public:
    [[nodiscard]]
    constexpr void operator()() noexcept {
        UnpackSignedIntTestCallable<T, sizeof(T) * 8u>()();
    }
};

TEST_CASE("unpackSignedInt<int8_t, N>", "[signedInt]") {
    UnpackSignedIntTest<int8_t>()();
}

TEST_CASE("unpackSignedInt<int16_t, N>", "[signedInt]") {
    UnpackSignedIntTest<int16_t>()();
}

TEST_CASE("unpackSignedInt<int32_t, N>", "[signedInt][!hide]") {
    UnpackSignedIntTest<int32_t>()();
}

TEST_CASE("unpackSignedInt<int64_t, N>", "[signedInt][!hide]") {
    UnpackSignedIntTest<int64_t>()();
}

TEST_CASE("scaleFactorUNorm", "[scaleFactor]") {
    CHECK(scaleFactorUNorm<1>() == 1.0f);
    CHECK(scaleFactorUNorm<2>() == 3.0f);
    CHECK(scaleFactorUNorm<3>() == 7.0f);
    CHECK(scaleFactorUNorm<4>() == 15.0f);
    CHECK(scaleFactorUNorm<5>() == 31.0f);
    CHECK(scaleFactorUNorm<6>() == 63.0f);
    CHECK(scaleFactorUNorm<7>() == 127.0f);
    CHECK(scaleFactorUNorm<8>() == 255.0f);
    CHECK(scaleFactorUNorm<9>() == 511.0f);
    CHECK(scaleFactorUNorm<10>() == 1023.0f);
    CHECK(scaleFactorUNorm<11>() == 2047.0f);
    CHECK(scaleFactorUNorm<12>() == 4095.0f);
    CHECK(scaleFactorUNorm<13>() == 8191.0f);
    CHECK(scaleFactorUNorm<14>() == 16383.0f);
    CHECK(scaleFactorUNorm<15>() == 32767.0f);
    CHECK(scaleFactorUNorm<16>() == 65535.0f);
}

TEST_CASE("scaleFactorSNorm", "[scaleFactor]") {
    CHECK(scaleFactorSNorm<1>() == 0.0f);
    CHECK(scaleFactorSNorm<2>() == 1.0f);
    CHECK(scaleFactorSNorm<3>() == 3.0f);
    CHECK(scaleFactorSNorm<4>() == 7.0f);
    CHECK(scaleFactorSNorm<5>() == 15.0f);
    CHECK(scaleFactorSNorm<6>() == 31.0f);
    CHECK(scaleFactorSNorm<7>() == 63.0f);
    CHECK(scaleFactorSNorm<8>() == 127.0f);
    CHECK(scaleFactorSNorm<9>() == 255.0f);
    CHECK(scaleFactorSNorm<10>() == 511.0f);
    CHECK(scaleFactorSNorm<11>() == 1023.0f);
    CHECK(scaleFactorSNorm<12>() == 2047.0f);
    CHECK(scaleFactorSNorm<13>() == 4095.0f);
    CHECK(scaleFactorSNorm<14>() == 8191.0f);
    CHECK(scaleFactorSNorm<15>() == 16383.0f);
    CHECK(scaleFactorSNorm<16>() == 32767.0f);
}

TEST_CASE("uscaledMax", "[scaled]") {
    CHECK(uscaledMax<1>() == 1.0f);
    CHECK(uscaledMax<2>() == 3.0f);
    CHECK(uscaledMax<3>() == 7.0f);
    CHECK(uscaledMax<4>() == 15.0f);
    CHECK(uscaledMax<5>() == 31.0f);
    CHECK(uscaledMax<6>() == 63.0f);
    CHECK(uscaledMax<7>() == 127.0f);
    CHECK(uscaledMax<8>() == 255.0f);
    CHECK(uscaledMax<9>() == 511.0f);
    CHECK(uscaledMax<10>() == 1023.0f);
    CHECK(uscaledMax<11>() == 2047.0f);
    CHECK(uscaledMax<12>() == 4095.0f);
    CHECK(uscaledMax<13>() == 8191.0f);
    CHECK(uscaledMax<14>() == 16383.0f);
    CHECK(uscaledMax<15>() == 32767.0f);
    CHECK(uscaledMax<16>() == 65535.0f);
    CHECK(uscaledMax<17>() == 131071.0f);
    CHECK(uscaledMax<18>() == 262143.0f);
    CHECK(uscaledMax<19>() == 524287.0f);
    CHECK(uscaledMax<20>() == 1048575.0f);
    CHECK(uscaledMax<21>() == 2097151.0f);
    CHECK(uscaledMax<22>() == 4194303.0f);
    CHECK(uscaledMax<23>() == 8388607.0f);
    CHECK(uscaledMax<24>() == 16777215.0f);
    CHECK(uscaledMax<25>() == 33554431.0f);
    CHECK(uscaledMax<26>() == 67108863.0f);
    CHECK(uscaledMax<27>() == 134217727.0f);
    CHECK(uscaledMax<28>() == 268435455.0f);
    CHECK(uscaledMax<29>() == 536870911.0f);
    CHECK(uscaledMax<30>() == 1073741823.0f);
    CHECK(uscaledMax<31>() == 2147483647.0f);
    CHECK(uscaledMax<32>() == 4294967295.0f);
    CHECK(uscaledMax<33>() == 8589934591.0f);
    CHECK(uscaledMax<34>() == 17179869183.0f);
    CHECK(uscaledMax<35>() == 34359738367.0f);
    CHECK(uscaledMax<36>() == 68719476735.0f);
    CHECK(uscaledMax<37>() == 137438953471.0f);
    CHECK(uscaledMax<38>() == 274877906943.0f);
    CHECK(uscaledMax<39>() == 549755813887.0f);
    CHECK(uscaledMax<40>() == 1099511627775.0f);
    CHECK(uscaledMax<41>() == 2199023255551.0f);
    CHECK(uscaledMax<42>() == 4398046511103.0f);
    CHECK(uscaledMax<43>() == 8796093022207.0f);
    CHECK(uscaledMax<44>() == 17592186044415.0f);
    CHECK(uscaledMax<45>() == 35184372088831.0f);
    CHECK(uscaledMax<46>() == 70368744177663.0f);
    CHECK(uscaledMax<47>() == 140737488355327.0f);
    CHECK(uscaledMax<48>() == 281474976710655.0f);
    CHECK(uscaledMax<49>() == 562949953421311.0f);
    CHECK(uscaledMax<50>() == 1125899906842623.0f);
    CHECK(uscaledMax<51>() == 2251799813685247.0f);
    CHECK(uscaledMax<52>() == 4503599627370495.0f);
    CHECK(uscaledMax<53>() == 9007199254740991.0f);
    CHECK(uscaledMax<54>() == 18014398509481983.0f);
    CHECK(uscaledMax<55>() == 36028797018963967.0f);
    CHECK(uscaledMax<56>() == 72057594037927935.0f);
    CHECK(uscaledMax<57>() == 144115188075855871.0f);
    CHECK(uscaledMax<58>() == 288230376151711743.0f);
    CHECK(uscaledMax<59>() == 576460752303423487.0f);
    CHECK(uscaledMax<60>() == 1152921504606846975.0f);
    CHECK(uscaledMax<61>() == 2305843009213693951.0f);
    CHECK(uscaledMax<62>() == 4611686018427387903.0f);
    CHECK(uscaledMax<63>() == 9223372036854775807.0f);
    CHECK(uscaledMax<64>() == 18446744073709551615.0f);
}