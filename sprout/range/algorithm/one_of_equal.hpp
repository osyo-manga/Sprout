#ifndef SPROUT_RANGE_ALGORITHM_ONE_OF_EQUAL_HPP
#define SPROUT_RANGE_ALGORITHM_ONE_OF_EQUAL_HPP

#include <sprout/config.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/one_of_equal.hpp>

namespace sprout {
	namespace range {
		//
		// one_of_equal
		//
		template<typename Range, typename T>
		inline SPROUT_CONSTEXPR bool
		one_of_equal(Range const& range, T const& value) {
			return sprout::one_of_equal(sprout::begin(range), sprout::end(range), value);
		}
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_ONE_OF_EQUAL_HPP
