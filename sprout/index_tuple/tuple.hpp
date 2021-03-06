#ifndef SPROUT_INDEX_TUPLE_TUPLE_HPP
#define SPROUT_INDEX_TUPLE_TUPLE_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/index_tuple/integer_seq.hpp>
#include <sprout/index_tuple/index_tuple.hpp>
#include <sprout/utility/pack.hpp>

namespace std {
#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wmismatched-tags"
#endif
	//
	// tuple_size
	//
	template<typename T, T... Is>
	struct tuple_size<sprout::integer_seq<T, Is...> >
		: public std::integral_constant<std::size_t, sizeof...(Is)>
	{};
	//
	// tuple_element
	//
	template<std::size_t I, typename T, T... Is>
	struct tuple_element<I, sprout::integer_seq<T, Is...> > {
		static_assert(I < sizeof...(Is), "tuple_element<>: index out of range");
	public:
		typedef typename sprout::tppack_c_at<I, T, Is...>::type type;
	};

	//
	// tuple_size
	//
	template<sprout::index_t... Indexes>
	struct tuple_size<sprout::index_tuple<Indexes...> >
		: public std::tuple_size<sprout::integer_seq<sprout::index_t, Indexes...> >
	{};
	//
	// tuple_element
	//
	template<std::size_t I, sprout::index_t... Indexes>
	struct tuple_element<I, sprout::index_tuple<Indexes...> >
		: public std::tuple_element<I, sprout::integer_seq<sprout::index_t, Indexes...> >
	{};

	//
	// tuple_size
	//
	template<sprout::uindex_t... Indexes>
	struct tuple_size<sprout::uindex_tuple<Indexes...> >
		: public std::tuple_size<sprout::integer_seq<sprout::uindex_t, Indexes...> >
	{};
	//
	// tuple_element
	//
	template<std::size_t I, sprout::uindex_t... Indexes>
	struct tuple_element<I, sprout::uindex_tuple<Indexes...> >
		: public std::tuple_element<I, sprout::integer_seq<sprout::uindex_t, Indexes...> >
	{};
#if defined(__clang__)
#	pragma clang diagnostic pop
#endif
}	// namespace std

namespace sprout {
	//
	// tuple_get
	//
	template<std::size_t I, typename T, T... Is>
	inline SPROUT_CONSTEXPR typename std::tuple_element<I, sprout::integer_seq<T, Is...> >::type
	tuple_get(sprout::integer_seq<T, Is...>) SPROUT_NOEXCEPT {
		static_assert(I < sizeof...(Is), "tuple_get: index out of range");
		typedef typename std::tuple_element<I, sprout::integer_seq<T, Is...> >::type type;
		return type();
	}

	//
	// tuple_get
	//
	template<std::size_t I, sprout::index_t... Indexes>
	inline SPROUT_CONSTEXPR typename std::tuple_element<I, sprout::index_tuple<Indexes...> >::type
	tuple_get(sprout::index_tuple<Indexes...>) SPROUT_NOEXCEPT {
		static_assert(I < sizeof...(Indexes), "tuple_get: index out of range");
		typedef typename std::tuple_element<I, sprout::index_tuple<Indexes...> >::type type;
		return type();
	}

	//
	// tuple_get
	//
	template<std::size_t I, sprout::uindex_t... Indexes>
	inline SPROUT_CONSTEXPR typename std::tuple_element<I, sprout::uindex_tuple<Indexes...> >::type
	tuple_get(sprout::uindex_tuple<Indexes...>) SPROUT_NOEXCEPT {
		static_assert(I < sizeof...(Indexes), "tuple_get: index out of range");
		typedef typename std::tuple_element<I, sprout::uindex_tuple<Indexes...> >::type type;
		return type();
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_INDEX_TUPLE_TUPLE_HPP
