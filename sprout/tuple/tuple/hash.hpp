#ifndef SPROUT_TUPLE_TUPLE_HASH_HPP
#define SPROUT_TUPLE_TUPLE_HASH_HPP

#include <cstddef>
#include <functional>
#include <sprout/config.hpp>
#include <sprout/index_tuple/metafunction.hpp>
#include <sprout/functional/hash.hpp>
#include <sprout/tuple/tuple/tuple.hpp>
#include <sprout/tuple/tuple/get.hpp>

namespace sprout {
	namespace tuples {
		namespace detail {
			template<typename... Types, sprout::index_t... Indexes>
			inline SPROUT_CONSTEXPR std::size_t
			tuple_hash_value_impl(sprout::tuples::tuple<Types...> const& v, sprout::index_tuple<Indexes...>) {
				return sprout::hash_values(sprout::tuples::get<Indexes>(v)...);
			}
		}	// namespace detail
		//
		// hash_value
		//
		template<typename... Types>
		inline SPROUT_CONSTEXPR std::size_t
		hash_value(sprout::tuples::tuple<Types...> const& v) {
			return sprout::tuples::detail::tuple_hash_value_impl(
				v,
				sprout::make_index_tuple<sizeof...(Types)>::make()
				);
		}
	}	// namespace tuples
}	// namespace sprout

namespace std {
	//
	// hash
	//
	template<typename... Types>
	struct hash<sprout::tuples::tuple<Types...> >
		: public sprout::hash<sprout::tuples::tuple<Types...> >
	{};
}	// namespace std

#endif	// #ifndef SPROUT_TUPLE_TUPLE_HASH_HPP
