#ifndef SPROUT_OPERATION_FIT_APPEND_HPP
#define SPROUT_OPERATION_FIT_APPEND_HPP

#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/operation/fixed/append.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace result_of {
			//
			// append
			//
			template<typename Container, typename Input>
			struct append {
			public:
				typedef sprout::sub_array<
					typename sprout::fixed_container_traits<
						typename sprout::fixed::result_of::append<Container, Input>::type
					>::internal_type
				> type;
			};
		}	// namespace result_of

		//
		// append
		//
		template<typename Container, typename Input>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::append<Container, Input>::type append(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::const_iterator pos,
			Input const& input
			)
		{
			return sprout::sub_copy(
				sprout::get_fixed(sprout::fixed::append(cont, pos, input)),
				sprout::fixed_begin_offset(cont),
				sprout::fixed_end_offset(cont) + sprout::size(input)
				);
		}
		//
		// append
		//
		template<typename Container, typename Input>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::append<Container, Input>::type append(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::difference_type pos,
			Input const& input
			)
		{
			return sprout::sub_copy(
				sprout::get_fixed(sprout::fixed::append(cont, pos, input)),
				sprout::fixed_begin_offset(cont),
				sprout::fixed_end_offset(cont) + sprout::size(input)
				);
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIT_APPEND_HPP
