#ifndef SPROUT_OPERATION_FIXED_ERASE_N_HPP
#define SPROUT_OPERATION_FIXED_ERASE_N_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/index_tuple/metafunction.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/container/indexes.hpp>
#include <sprout/iterator/operation.hpp>

namespace sprout {
	namespace fixed {
		namespace result_of {
			//
			// erase_n
			//
			template<std::size_t N, typename Container>
			struct erase_n
				: public sprout::container_transform_traits<
					Container
				>::template rebind_size<
					sprout::container_traits<Container>::static_size - N
				>
			{
				static_assert(sprout::container_traits<Container>::static_size >= N, "static_size >= N");
			};
		}	// namespace result_of

		namespace detail {
			template<std::size_t N, typename Result, typename Container, sprout::index_t... Indexes>
			inline SPROUT_CONSTEXPR Result
			erase_n_impl(
				Container const& cont, sprout::index_tuple<Indexes...>,
				typename sprout::container_traits<Container>::difference_type pos
				)
			{
				return sprout::remake<Result>(
					cont,
					sprout::size(cont) - N,
					(Indexes < sprout::container_traits<Container>::static_size - N
						? (Indexes < pos
							? *sprout::next(sprout::internal_begin(cont), Indexes)
							: *sprout::next(sprout::internal_begin(cont), Indexes + N)
							)
						: typename sprout::container_traits<Result>::value_type()
						)...
					);
			}
		}	// namespace detail
		//
		// erase_n
		//
		template<std::size_t N, typename Container>
		inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::erase_n<N, Container>::type
		erase_n(Container const& cont, typename sprout::container_traits<Container>::const_iterator pos) {
			return sprout::fixed::detail::erase_n_impl<N, typename sprout::fixed::result_of::erase_n<N, Container>::type>(
				cont,
				sprout::container_indexes<typename sprout::fixed::result_of::erase_n<N, Container>::type>::make(),
				sprout::distance(sprout::internal_begin(cont), pos)
				);
		}
		template<std::size_t N, typename Container>
		inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::erase_n<N, Container>::type
		erase_n(Container const& cont, typename sprout::container_traits<Container>::difference_type pos) {
			return sprout::fixed::detail::erase_n_impl<N, typename sprout::fixed::result_of::erase_n<N, Container>::type>(
				cont,
				sprout::container_indexes<typename sprout::fixed::result_of::erase_n<N, Container>::type>::make(),
				sprout::distance(sprout::internal_begin(cont), sprout::next(sprout::begin(cont), pos))
				);
		}
	}	// namespace fixed

	namespace result_of {
		using sprout::fixed::result_of::erase_n;
	}	// namespace result_of

	using sprout::fixed::erase_n;
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIXED_ERASE_N_HPP
