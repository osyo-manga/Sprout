#ifndef SPROUT_RANDOM_ADDITIVE_COMBINE_HPP
#define SPROUT_RANDOM_ADDITIVE_COMBINE_HPP

#include <cstdint>
#include <ios>
#include <istream>
#include <sprout/config.hpp>
#include <sprout/random/random_result.hpp>
#include <sprout/random/linear_congruential.hpp>

namespace sprout {
	namespace random {
		//
		// additive_combine_engine
		//
		template<typename MLCG1, typename MLCG2>
		class additive_combine_engine {
		public:
			typedef MLCG1 base1_type;
			typedef MLCG2 base2_type;
			typedef base1_type first_base;
			typedef base2_type second_base;
			typedef typename base1_type::result_type result_type;
		private:
			static SPROUT_CONSTEXPR result_type static_min() SPROUT_NOEXCEPT {
				return 1;
			}
			static SPROUT_CONSTEXPR result_type static_max() SPROUT_NOEXCEPT {
				return base1_type::modulus - 1;
			}
		public:
			struct private_constructor_tag {};
		private:
			base1_type mlcg1_;
			base2_type mlcg2_;
		private:
			SPROUT_CONSTEXPR additive_combine_engine(
				base1_type const& mlcg1,
				base2_type const& mlcg2,
				private_constructor_tag
				)
				: mlcg1_(mlcg1)
				, mlcg2_(mlcg2)
			{}
			template<typename Random1, typename Random2>
			SPROUT_CONSTEXPR sprout::random::random_result<additive_combine_engine> generate(Random1 const& rnd1, Random2 const& rnd2) const {
				return sprout::random::random_result<additive_combine_engine>(
					rnd2.result() < rnd1.result()
						? rnd1.result() - rnd2.result()
						: rnd1.result() - rnd2.result() + base1_type::modulus - 1
						,
					additive_combine_engine(
						rnd1.engine(),
						rnd2.engine(),
						private_constructor_tag()
						)
					);
			}
		public:
			SPROUT_CONSTEXPR additive_combine_engine()
				: mlcg1_()
				, mlcg2_()
			{}
			explicit SPROUT_CONSTEXPR additive_combine_engine(result_type const& seed)
				: mlcg1_(seed)
				, mlcg2_(seed)
			{}
			SPROUT_CONSTEXPR additive_combine_engine(typename MLCG1::result_type seed1, typename MLCG2::result_type seed2)
				: mlcg1_(seed1)
				, mlcg2_(seed2)
			{}
			SPROUT_CONSTEXPR result_type min() const SPROUT_NOEXCEPT {
				return 1;
			}
			SPROUT_CONSTEXPR result_type max() const SPROUT_NOEXCEPT {
				return base1_type::modulus - 1;
			}
			SPROUT_CONSTEXPR sprout::random::random_result<additive_combine_engine> operator()() const {
				return generate(mlcg1_(), mlcg2_());
			}
			SPROUT_CONSTEXPR base1_type const& base1() const SPROUT_NOEXCEPT {
				return mlcg1_;
			}
			SPROUT_CONSTEXPR base2_type const& base2() const SPROUT_NOEXCEPT {
				return mlcg2_;
			}
			friend SPROUT_CONSTEXPR bool operator==(additive_combine_engine const& lhs, additive_combine_engine const& rhs) SPROUT_NOEXCEPT {
				return lhs.mlcg1_ == rhs.mlcg1_ && lhs.mlcg2_ == rhs.mlcg2_;
			}
			friend SPROUT_CONSTEXPR bool operator!=(additive_combine_engine const& lhs, additive_combine_engine const& rhs) SPROUT_NOEXCEPT {
				return !(lhs == rhs);
			}
			template<typename Elem, typename Traits>
			friend std::basic_istream<Elem, Traits>& operator>>(
				std::basic_istream<Elem, Traits>& lhs,
				additive_combine_engine& rhs
				)
			{
				return lhs >> rhs.mlcg1_ >> std::ws >> rhs.mlcg2_;
			}
			template<typename Elem, typename Traits>
			friend std::basic_ostream<Elem, Traits>& operator<<(
				std::basic_ostream<Elem, Traits>& lhs,
				additive_combine_engine const& rhs
				)
			{
				return lhs << rhs.mlcg1_ << ' ' << rhs.mlcg2_;
			}
		};

		//
		// ecuyer1988
		//
		typedef sprout::random::additive_combine_engine<
			sprout::random::linear_congruential_engine<std::uint32_t, 40014, 0, 2147483563>,
			sprout::random::linear_congruential_engine<std::uint32_t, 40692, 0, 2147483399>
		> ecuyer1988;
	}	// namespace random

	using sprout::random::additive_combine_engine;
	using sprout::random::ecuyer1988;
}	// namespace sprout

#endif	// #ifndef SPROUT_RANDOM_ADDITIVE_COMBINE_HPP
