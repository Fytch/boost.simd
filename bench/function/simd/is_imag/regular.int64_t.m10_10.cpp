// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_imag in simd mode for std::int64_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/is_imag.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_is_imag, bs::is_imag);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_is_imag, std::int64_t>(-10, 10);
}
