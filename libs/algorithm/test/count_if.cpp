#ifndef SPROUT_LIBS_ALGORITHM_TEST_COUNT_IF_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_COUNT_IF_CPP

#include <sprout/algorithm/count_if.hpp>
#include <sprout/array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_count_if_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 10>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					sprout::begin(arr1),
					sprout::end(arr1),
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					sprout::begin(arr1),
					sprout::end(arr1),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					sprout::begin(arr1),
					sprout::begin(arr1) + 5,
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 3);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::begin(arr1) + 5),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::end(arr1)),
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::end(arr1)),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::begin(arr1) + 5),
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 3);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::begin(arr1) + 5),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}

#if defined(__clang__)
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::end(arr1)),
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::end(arr1)),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::begin(arr1) + 5),
					testspr::is_odd<int>()
					);
				TESTSPR_BOTH_ASSERT(result == 3);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::count_if(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::begin(arr1) + 5),
					testspr::less_than<int>(8)
					);
				TESTSPR_BOTH_ASSERT(result == 5);
			}
#endif
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_count_if_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_COUNT_IF_CPP
