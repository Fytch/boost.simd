// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor acosh in std mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/acosh.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;


struct acosh_bench
{
  template < class T >
  BOOST_FORCEINLINE std::complex<T> operator()(const std::complex<T> & a0)
    const BOOST_NOEXCEPT
  {
    return std::acosh(a0);
  }
};

DEFINE_BENCH_MAIN()
{
  using T = std::complex<float>;
  run<T>(acosh_bench(), nsbg::rand<T>(-10, 10, -10, 10));
}

