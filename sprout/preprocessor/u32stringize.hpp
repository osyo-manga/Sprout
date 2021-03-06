#ifndef SPROUT_PREPROCESSOR_U32STRINGIZE_HPP
#define SPROUT_PREPROCESSOR_U32STRINGIZE_HPP

#include <sprout/config.hpp>

//
// SPROUT_PP_U32STRINGIZE
//
#define SPROUT_PP_U32STRINGIZE(text) SPROUT_PP_U32STRINGIZE_I(text)
#define SPROUT_PP_U32STRINGIZE_I(text) SPROUT_PP_U32STRINGIZE_II(#text)
#define SPROUT_PP_U32STRINGIZE_II(str) U ## str

#endif	// #ifndef SPROUT_PREPROCESSOR_U32STRINGIZE_HPP
