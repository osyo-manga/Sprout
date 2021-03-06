#ifndef SPROUT_WEED_DETAIL_C_STR_AS_STRING_HPP
#define SPROUT_WEED_DETAIL_C_STR_AS_STRING_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/string.hpp>
#include <sprout/type_traits/identity.hpp>

namespace sprout {
	namespace weed {
		namespace detail {
			template<typename T>
			struct c_str_as_string;
			template<typename T>
			struct c_str_as_string<T const>
				: public sprout::weed::detail::c_str_as_string<T>
			{};
			template<typename T>
			struct c_str_as_string<T volatile>
				: public sprout::weed::detail::c_str_as_string<T>
			{};
			template<typename T>
			struct c_str_as_string<T const volatile>
				: public sprout::weed::detail::c_str_as_string<T>
			{};
			template<typename T, std::size_t N>
			struct c_str_as_string<T[N]>
				: public sprout::identity<sprout::basic_string<T, N - 1> >
			{};
			template<typename T, std::size_t N>
			struct c_str_as_string<T const[N]>
				: public sprout::identity<sprout::basic_string<T, N - 1> >
			{};
			template<typename T, std::size_t N>
			struct c_str_as_string<T volatile[N]>
				: public sprout::identity<sprout::basic_string<T, N - 1> >
			{};
			template<typename T, std::size_t N>
			struct c_str_as_string<T const volatile[N]>
				: public sprout::identity<sprout::basic_string<T, N - 1> >
			{};
		}	// namespace detail
	}	// namespace weed
}	// namespace sprout

#endif	// #ifndef SPROUT_WEED_DETAIL_C_STR_AS_STRING_HPP
