//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TAND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TAND_HPP_INCLUDED

#include <boost/simd/arch/common/detail/scalar/trigo.hpp>
#include <boost/simd/function/restricted.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( tand_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_MAYBEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::degree_tag,tag::not_simd_type,tag::big_tag>::tana(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( tand_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_ < bd::unspecified_<A1> >
                          )
  {
    BOOST_MAYBEINLINE A0 operator() ( A0 a0,  A1 const &) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::degree_tag,tag::not_simd_type,A1>::tana(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( tand_
                          , (typename A0)
                          , bd::cpu_
                          , bs::restricted_tag
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_MAYBEINLINE A0 operator() (const restricted_tag &,  A0 a0) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::degree_tag,tag::not_simd_type,tag::clipped_pio4_tag>::tana(a0);
    }
  };
} } }


#endif
