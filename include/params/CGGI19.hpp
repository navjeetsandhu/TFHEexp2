#pragma once

#include <cstdint>
#include <cmath>

//Dummy
constexpr uint32_t DEF_tlvl22 = 0;
constexpr uint32_t DEF_basebitlvl22 = 0;

struct lvl0param {
    static constexpr std::uint32_t n = 630;
    static const inline double α = std::pow(2.0, -15);
    using T = uint32_t;
    static constexpr T μ = 1U << 29;
};

struct lvl1param {
    static constexpr std::uint32_t nbit = 10;
    static constexpr std::uint32_t n = 1<<nbit;
    static constexpr std::uint32_t l = 3;
    static constexpr std::uint32_t Bgbit = 6;
    static constexpr std::uint32_t Bg = 1<<Bgbit;
    static const inline double α = std::pow(2.0, -25);
    using T = uint32_t;
    static constexpr T μ = 1U << 29;
};

struct lvl2param {
    static const std::uint32_t nbit = 11;
    static constexpr std::uint32_t n = 1<<nbit;
    static constexpr std::uint32_t l = 4;
    static constexpr std::uint32_t Bgbit = 9;
    static constexpr std::uint32_t Bg = 1<<Bgbit;
    static const inline double α = std::pow(2.0, -44);
    using T = uint64_t;
    static constexpr T μ = 1ULL << 61;
};

struct lvl10param {
    static constexpr std::uint32_t t = 8;
    static constexpr std::uint32_t basebit = 2;
    static const inline double α = lvl0param::α;
    using domainP = lvl1param;
    using targetP = lvl0param;
};

struct lvl21param{
    static constexpr std::uint32_t t = 10;
    static constexpr std::uint32_t basebit = 3;
    static const inline double α = std::pow(2, -29);
    using domainP = lvl2param;
    using targetP = lvl1param;
};

//Dummy
struct lvl20param{
    static constexpr std::uint32_t t = 0; //number of addition in keyswitching
    static constexpr std::uint32_t basebit = 0; //how many bit should be encrypted in keyswitching key
    static const inline double α = lvl0param::α; //key noise
    using domainP = lvl2param;
    using targetP = lvl0param;

    bool operator==(const lvl20param& in) const{
        return (t==in.t)&(basebit==in.basebit)
        };
};

//Dummy
struct lvl22param{
    static constexpr std::uint32_t t = 0;
    static constexpr std::uint32_t basebit = 0;
    static const inline double α = lvl2param::α;
    using domainP = lvl2param;
    using targetP = lvl2param;
};