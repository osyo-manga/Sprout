#ifndef SPROUT_TYPE_BOOST_MPL_VECTOR_C_HPP
#define SPROUT_TYPE_BOOST_MPL_VECTOR_C_HPP

#include <sprout/config.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/at.hpp>
#include <sprout/type/tuple.hpp>
#include <sprout/type/boost/mpl/v_iter.hpp>

namespace sprout {
	namespace types {
		//
		// begin
		//
		template<typename T, T... Values>
		struct begin<boost::mpl::vector_c<T, Values...> >
			: public boost::mpl::begin<boost::mpl::vector_c<T, Values...> >
		{};
		//
		// end
		//
		template<typename T, T... Values>
		struct end<boost::mpl::vector_c<T, Values...> >
			: public boost::mpl::end<boost::mpl::vector_c<T, Values...> >
		{};

		//
		// tuple_size
		//
		template<typename T, T... Values>
		struct tuple_size<boost::mpl::vector_c<T, Values...> >
			: public boost::mpl::size<boost::mpl::vector_c<T, Values...> >
		{};
		//
		// tuple_element
		//
		template<std::size_t I, typename T, T... Values>
		struct tuple_element<I, boost::mpl::vector_c<T, Values...> >
			: public boost::mpl::at_c<boost::mpl::vector_c<T, Values...>, I>
		{};
	}	// namespace types
}	// namespace sprout

#endif	// #ifndef SPROUT_TYPE_BOOST_MPL_VECTOR_C_HPP
