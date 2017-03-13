//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/atanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex atanh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::cmplx::atanh(c1), bs::complex<T>(0, 1.1071487177940905030170654601785), 0.5);
  STF_ULP_EQUAL( bs::cmplx::atanh(c2), bs::complex<T>(- 0.11750090731143388841273425778709, 1.4099210495965755225306193844604), 0.5);
  STF_ULP_EQUAL( bs::cmplx::atanh(c3), bs::complex<T>(0.40235947810852509365018983330655,  1.0172219678978513677227889615505), 0.5);
}


STF_CASE_TPL( "Complex atanh complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1(0, -0.11750090731143388841273425778709, 0.40235947810852509365018983330655, 0.54930614433405484569762261846126),
      i1(1.1071487177940905030170654601785, 1.4099210495965755225306193844604, 1.0172219678978513677227889615505, 1.5707963267948966192313216916398);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::cmplx::atanh(c1), c2, 1.0);
}

// [ 1.1071487177940905030170654601785i, - 0.11750090731143388841273425778709 + 1.4099210495965755225306193844604i, 0.40235947810852509365018983330655 + 1.0172219678978513677227889615505i, 0.54930614433405484569762261846126 - 1.5707963267948966192313216916398i]


// ans =

// [ 0, -0.11750090731143388841273425778709, 0.40235947810852509365018983330655, 0.54930614433405484569762261846126]


// ans =

// [ 1.1071487177940905030170654601785, 1.4099210495965755225306193844604, 1.0172219678978513677227889615505, -1.5707963267948966192313216916398]


