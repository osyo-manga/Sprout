#ifndef SPROUT_OPERATION_FIXED_POP_FRONT_HPP
#define SPROUT_OPERATION_FIXED_POP_FRONT_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/index_tuple/metafunction.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/container/indexes.hpp>
#include <sprout/operation/fixed/erase.hpp>

namespace sprout {
	namespace fixed {
		namespace result_of {
			//
			// pop_front
			//
			template<typename Container>
			struct pop_front
				: public sprout::fixed::result_of::erase<Container>
			{};
		}	// namespace result_of

		//
		// pop_front
		//
		template<typename Container>
		inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::pop_front<Container>::type
		pop_front(Container const& cont) {
			return sprout::fixed::detail::erase_impl<typename sprout::fixed::result_of::pop_front<Container>::type>(
				cont,
				sprout::container_indexes<typename sprout::fixed::result_of::pop_front<Container>::type>::make(),
				sprout::internal_begin_offset(cont)
				);
		}
	}	// namespace fixed

	namespace result_of {
		using sprout::fixed::result_of::pop_front;
	}	// namespace result_of

	using sprout::fixed::pop_front;
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIXED_POP_FRONT_HPP
