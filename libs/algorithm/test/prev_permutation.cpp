#ifndef SPROUT_LIBS_ALGORITHM_TEST_PREV_PERMUTATION_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_PREV_PERMUTATION_CPP

#include <sprout/algorithm/prev_permutation.hpp>
#include <sprout/array.hpp>
#include <sprout/sub_array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_prev_permutation_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 5>{{5, 4, 3, 2, 1}};

			// ����
			{
				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::prev_permutation(
					arr1
					);
				TESTSPR_BOTH_ASSERT(testspr::equal(
					permutation.first,
					array<int, 5>{{5, 4, 3, 1, 2}}
					));
				TESTSPR_BOTH_ASSERT(permutation.second);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::fit::prev_permutation(
					arr1
					);
				TESTSPR_BOTH_ASSERT(testspr::equal(
					permutation.first,
					array<int, 5>{{5, 4, 3, 1, 2}}
					));
				TESTSPR_BOTH_ASSERT(permutation.second);
			}
			// ����
			// �͈͂̐؂�o��
			// !!!
//			{
//				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::prev_permutation(
//					sprout::sub(arr1, 2, 4)
//					);
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					permutation.first,
//					array<int, 3>{{4, 2, 3}}
//					));
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					sprout::get_internal(permutation.first),
//					array<int, 5>{{5, 4, 2, 3, 1}}
//					));
//				TESTSPR_BOTH_ASSERT(permutation.second);
//			}
//			{
//				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::fit::prev_permutation(
//					sprout::sub(arr1, 2, 4)
//					);
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					permutation.first,
//					array<int, 3>{{4, 2, 3}}
//					));
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					sprout::get_internal(permutation.first),
//					array<int, 5>{{5, 4, 2, 3, 1}}
//					));
//				TESTSPR_BOTH_ASSERT(permutation.second);
//			}
		}
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 5>{{5, 4, 3, 2, 1}};

			// ����
			{
				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::prev_permutation(
					arr1,
					testspr::less<int>()
					);
				TESTSPR_BOTH_ASSERT(testspr::equal(
					permutation.first,
					array<int, 5>{{5, 4, 3, 1, 2}}
					));
				TESTSPR_BOTH_ASSERT(permutation.second);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::fit::prev_permutation(
					arr1,
					testspr::less<int>()
					);
				TESTSPR_BOTH_ASSERT(testspr::equal(
					permutation.first,
					array<int, 5>{{5, 4, 3, 1, 2}}
					));
				TESTSPR_BOTH_ASSERT(permutation.second);
			}
			// ����
			// �͈͂̐؂�o��
			// !!!
//			{
//				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::prev_permutation(
//					sprout::sub(arr1, 2, 4),
//					testspr::less<int>()
//					);
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					permutation.first,
//					array<int, 3>{{4, 2, 3}}
//					));
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					sprout::get_internal(permutation.first),
//					array<int, 5>{{5, 4, 2, 3, 1}}
//					));
//				TESTSPR_BOTH_ASSERT(permutation.second);
//			}
//			{
//				SPROUT_STATIC_CONSTEXPR auto permutation = sprout::fit::prev_permutation(
//					sprout::sub(arr1, 2, 4),
//					testspr::less<int>()
//					);
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					permutation.first,
//					array<int, 3>{{4, 2, 3}}
//					));
//				TESTSPR_BOTH_ASSERT(testspr::equal(
//					sprout::get_internal(permutation.first),
//					array<int, 5>{{5, 4, 2, 3, 1}}
//					));
//				TESTSPR_BOTH_ASSERT(permutation.second);
//			}
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_prev_permutation_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_PREV_PERMUTATION_CPP
