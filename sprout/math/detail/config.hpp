#ifndef SPROUT_MATH_DETAIL_CONFIG_HPP
#define SPROUT_MATH_DETAIL_CONFIG_HPP

#include <cfloat>
#include <sprout/config.hpp>
#if SPROUT_USE_BUILTIN_CMATH_FUNCTION
#	include <cmath>
#endif

#if SPROUT_USE_BUILTIN_CMATH_FUNCTION
#	define NS_SPROUT_MATH_DETAIL std
#else	// #ifndef SPROUT_USE_BUILTIN_CMATH_FUNCTION
#	define NS_SPROUT_MATH_DETAIL sprout::math::detail
#endif	// #ifndef SPROUT_USE_BUILTIN_CMATH_FUNCTION

#if (FLT_RADIX == 2)
#	define SPROUT_FLT_RADIX_IS_2 1
#else
#	define SPROUT_FLT_RADIX_IS_2 0
#endif

#if SPROUT_NOERROR_LARGE_FLOAT_ROUNDING
#	define SPROUT_MATH_THROW_LARGE_FLOAT_ROUNDING(e, x) (x)
#else
#	define SPROUT_MATH_THROW_LARGE_FLOAT_ROUNDING(e, x) throw (e)
#endif

#endif	// #ifndef SPROUT_MATH_DETAIL_CONFIG_HPP
