#ifndef SPROUT_OPERATION_FIT_INSERT_HPP
#define SPROUT_OPERATION_FIT_INSERT_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/operation/fixed/insert.hpp>
#include <sprout/sub_array/sub_array.hpp>
#include <sprout/sub_array/sub.hpp>

namespace sprout {
	namespace fit {
		namespace result_of {
			//
			// insert
			//
			template<typename Container, typename T, typename... Values>
			struct insert {
			public:
				typedef sprout::sub_array<
					typename sprout::container_traits<
						typename sprout::fixed::result_of::insert<Container, T, Values...>::type
					>::internal_type
				> type;
			};
		}	// namespace result_of

		//
		// insert
		//
		template<typename Container, typename T, typename... Values>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::insert<Container, T, Values...>::type
		insert(
			Container const& cont, typename sprout::container_traits<Container>::const_iterator pos,
			T const& v, Values const&... values
			)
		{
			return sprout::sub_copy(
				sprout::get_internal(sprout::fixed::insert(cont, pos, v, values...)),
				sprout::internal_begin_offset(cont),
				sprout::internal_end_offset(cont) + 1 + sizeof...(Values)
				);
		}
		template<typename Container, typename T, typename... Values>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::insert<Container, T, Values...>::type
		insert(
			Container const& cont, typename sprout::container_traits<Container>::difference_type pos,
			T const& v, Values const&... values
			)
		{
			return sprout::sub_copy(
				sprout::get_internal(sprout::fixed::insert(cont, pos, v, values...)),
				sprout::internal_begin_offset(cont),
				sprout::internal_end_offset(cont) + 1 + sizeof...(Values)
				);
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIT_INSERT_HPP
