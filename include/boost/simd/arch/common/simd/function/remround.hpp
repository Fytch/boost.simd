//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REMROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REMROUND_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/div.hpp>
#include <boost/simd/function/simd/round.hpp>
#include <boost/simd/function/simd/fnms.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/if_minus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(rem_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::tag::round_
                          , bs::pack_<bd::int_<A0>, X>
                          , bs::pack_<bd::int_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(bd::functor<bs::tag::round_> const&
                                     , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return if_minus(is_nez(a1), a0, div(round,a0,a1)*a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD(rem_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::tag::round_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(bd::functor<bs::tag::round_> const&
                                     , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        auto is_eqza1 = is_eqz(a1);
        return if_nan_else(logical_or(is_invalid(a1), is_eqza1),
                           if_minus(logical_notand(is_eqza1, is_nez(a0)), a0, div(round, a0,a1)*a1));
      }
   };

   BOOST_DISPATCH_OVERLOAD(rem_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::fast_tag
                          , bs::tag::round_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()(const fast_tag &
                                     , bd::functor<bs::tag::round_> const&
                                     , const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return fnms(div(round, a0,a1), a1, a0);
      }
   };
} } }

#endif
