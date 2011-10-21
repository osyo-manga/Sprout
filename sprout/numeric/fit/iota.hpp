#ifndef SPROUT_NUMERIC_FIT_IOTA_HPP
#define SPROUT_NUMERIC_FIT_IOTA_HPP

#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/numeric/fixed/iota.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename Container, typename T>
			SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type iota_impl(
				Container const& cont,
				T const& value,
				typename sprout::fixed_container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_fixed(sprout::fixed::iota(cont, value)),
					offset,
					offset + sprout::size(cont)
					);
			}
		}	// namespace detail
		//
		// iota
		//
		template<typename Container, typename T>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type iota(
			Container const& cont,
			T const& value
			)
		{
			return sprout::fit::detail::iota_impl(cont, value, sprout::fixed_begin_offset(cont));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_NUMERIC_FIT_IOTA_HPP