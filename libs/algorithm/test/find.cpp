#ifndef SPROUT_LIBS_ALGORITHM_TEST_FIND_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_FIND_CPP

#include <sprout/algorithm/find.hpp>
#include <sprout/array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_find_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 10>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					sprout::begin(arr1),
					sprout::end(arr1),
					8
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					sprout::begin(arr1),
					sprout::end(arr1),
					11
					);
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					sprout::begin(arr1),
					sprout::begin(arr1) + 5,
					8
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					sprout::begin(arr1),
					sprout::begin(arr1) + 5,
					11
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::end(arr1)),
					8
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::end(arr1)),
					11
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::begin(arr1) + 5),
					8
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_input(sprout::begin(arr1)),
					testspr::reduct_input(sprout::begin(arr1) + 5),
					11
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}

#if defined(__clang__)
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::end(arr1)),
					8
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::end(arr1)),
					11
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::begin(arr1) + 5),
					8
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find(
					testspr::reduct_random_access(sprout::begin(arr1)),
					testspr::reduct_random_access(sprout::begin(arr1) + 5),
					11
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
#endif
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_find_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_FIND_CPP
