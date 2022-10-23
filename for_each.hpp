#include <type_traits>
namespace smm
{
struct ToAny
{
    template<class To> operator To&&(); 
};

template <class T>
 concept aggregate = std::is_aggregate_v<std::remove_cvref_t<T>>;

template<aggregate T>
consteval auto arity(auto... args)
{
    if constexpr(requires{ T{{args}..., {ToAny{}}}; })
        return arity<T>(args..., ToAny{});
    else
        return sizeof...(args);
}

#define FWD_SMM(x) static_cast<decltype(x)&&>(x)
constexpr decltype(auto) for_all_members(aggregate auto&& to_introspect, auto && function)
{
    using T = std::remove_cvref_t<decltype(to_introspect)>;
    constexpr auto N = arity<T>();
    static_assert(N < 50);
    
    if constexpr(N == 0)
    {}
    else if constexpr (N == 1)
    {
        auto&& [m1] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1));
    }
    else if constexpr (N == 2)
    {
        auto&& [m1, m2] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2));
    }
    else if constexpr (N == 3)
    {
        auto&& [m1, m2, m3] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3));
    }
    else if constexpr (N == 4)
    {
        auto&& [m1, m2, m3, m4] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4));
    }
    else if constexpr (N == 5)
    {
        auto&& [m1, m2, m3, m4, m5] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5));
    }
    else if constexpr (N == 6)
    {
        auto&& [m1, m2, m3, m4, m5, m6] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6));
    }
    else if constexpr (N == 7)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7));
    }
    else if constexpr (N == 8)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8));
    }
    else if constexpr (N == 9)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9));
    }
    else if constexpr (N == 10)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10));
    }
    else if constexpr (N == 11)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11));
    }
    else if constexpr (N == 12)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12));
    }
    else if constexpr (N == 13)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13));
    }
    else if constexpr (N == 14)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14));
    }
    else if constexpr (N == 15)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15));
    }
    else if constexpr (N == 16)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16));
    }
    else if constexpr (N == 17)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17));
    }
    else if constexpr (N == 18)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18));
    }
    else if constexpr (N == 19)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19));
    }
    else if constexpr (N == 20)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20));
    }
    else if constexpr (N == 21)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21));
    }
    else if constexpr (N == 22)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22));
    }
    else if constexpr (N == 23)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23));
    }
    else if constexpr (N == 24)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24));
    }
    else if constexpr (N == 25)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25));
    }
    else if constexpr (N == 26)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26));
    }
    else if constexpr (N == 27)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27));
    }
    else if constexpr (N == 28)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28));
    }
    else if constexpr (N == 29)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29));
    }
    else if constexpr (N == 30)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30));
    }
    else if constexpr (N == 31)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31));
    }
    else if constexpr (N == 32)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32));
    }
    else if constexpr (N == 33)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33));
    }
    else if constexpr (N == 34)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34));
    }
    else if constexpr (N == 35)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35));
    }
    else if constexpr (N == 36)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36));
    }
    else if constexpr (N == 37)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37));
    }
    else if constexpr (N == 38)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38));
    }
    else if constexpr (N == 39)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39));
    }
    else if constexpr (N == 40)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40));
    }
    else if constexpr (N == 41)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41));
    }
    else if constexpr (N == 42)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42));
    }
    else if constexpr (N == 43)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43));
    }
    else if constexpr (N == 44)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44));
    }
    else if constexpr (N == 45)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44, m45] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44), FWD_SMM(m45));
    }
    else if constexpr (N == 46)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44, m45, m46] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44), FWD_SMM(m45), FWD_SMM(m46));
    }
    else if constexpr (N == 47)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44, m45, m46, m47] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44), FWD_SMM(m45), FWD_SMM(m46), FWD_SMM(m47));
    }
    else if constexpr (N == 48)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44, m45, m46, m47, m48] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44), FWD_SMM(m45), FWD_SMM(m46), FWD_SMM(m47), FWD_SMM(m48));
    }
    else if constexpr (N == 49)
    {
        auto&& [m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, m41, m42, m43, m44, m45, m46, m47, m48, m49] = FWD_SMM(to_introspect);
        return FWD_SMM(function)(FWD_SMM(m1), FWD_SMM(m2), FWD_SMM(m3), FWD_SMM(m4), FWD_SMM(m5), FWD_SMM(m6), FWD_SMM(m7), FWD_SMM(m8), FWD_SMM(m9), FWD_SMM(m10), FWD_SMM(m11), FWD_SMM(m12), FWD_SMM(m13), FWD_SMM(m14), FWD_SMM(m15), FWD_SMM(m16), FWD_SMM(m17), FWD_SMM(m18), FWD_SMM(m19), FWD_SMM(m20), FWD_SMM(m21), FWD_SMM(m22), FWD_SMM(m23), FWD_SMM(m24), FWD_SMM(m25), FWD_SMM(m26), FWD_SMM(m27), FWD_SMM(m28), FWD_SMM(m29), FWD_SMM(m30), FWD_SMM(m31), FWD_SMM(m32), FWD_SMM(m33), FWD_SMM(m34), FWD_SMM(m35), FWD_SMM(m36), FWD_SMM(m37), FWD_SMM(m38), FWD_SMM(m39), FWD_SMM(m40), FWD_SMM(m41), FWD_SMM(m42), FWD_SMM(m43), FWD_SMM(m44), FWD_SMM(m45), FWD_SMM(m46), FWD_SMM(m47), FWD_SMM(m48), FWD_SMM(m49));
    }
}
constexpr void for_each_members(aggregate auto&& to_introspect, auto && function)
{
    auto apply_unpacked = [&function](auto&&...m){ (function(m), ...); };
    for_all_members(FWD_SMM(to_introspect), apply_unpacked);
}
#undef FWD_SMM
}
