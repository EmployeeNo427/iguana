#pragma once
#include <type_traits>

namespace iguana {
template <class, class = void> struct is_container : std::false_type {};

template <class T>
struct is_container<
    T, std::void_t<decltype(std::declval<T>().size(), std::declval<T>().begin(),
                            std::declval<T>().end())>> : std::true_type {};

template <class, class = void> struct is_map_container : std::false_type {};

template <class T>
struct is_map_container<
    T, std::void_t<decltype(std::declval<typename T::mapped_type>())>>
    : public is_container<T> {};

} // namespace iguana
