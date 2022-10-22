#include <type_traits>
namespace mta
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

decltype(auto) for_all_members(aggregate auto&& to_introspect, auto && function)
{
    using T = std::remove_cvref_t<decltype(to_introspect)>;
    constexpr auto N = arity<T>();

    if constexpr(N == 0)
    {}
    else if constexpr(N == 1)
    {
        auto&&[m1] = to_introspect;
        return function(m1);
    }
    else if constexpr(N == 2)
    {
        auto&&[m1, m2] = to_introspect;
        return function(m1, m2);
    }
    else if constexpr(N == 3)
    {
        auto&&[m1, m2, m3] = to_introspect;
        return function(m1, m2, m3);
    }
}
}
