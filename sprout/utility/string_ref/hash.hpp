#ifndef SPROUT_UTILITY_STRING_REF_HASH_HPP
#define SPROUT_UTILITY_STRING_REF_HASH_HPP

#include <cstddef>
#include <functional>
#include <sprout/config.hpp>
#include <sprout/utility/string_ref/string_ref.hpp>
#include <sprout/functional/hash.hpp>

namespace sprout {
	//
	// hash_value
	//
	template<typename T, typename Traits>
	inline SPROUT_CONSTEXPR std::size_t
	hash_value(sprout::basic_string_ref<T, Traits> const& v) {
		return sprout::hash_range(v);
	}
}	// namespace sprout

namespace std {
	//
	// hash
	//
	template<typename T, typename Traits>
	struct hash<sprout::basic_string_ref<T, Traits> >
		: public sprout::hash<sprout::basic_string_ref<T, Traits> >
	{};
}	// namespace std

#endif	// #ifndef SPROUT_UTILITY_STRING_REF_HASH_HPP
