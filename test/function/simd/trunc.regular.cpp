//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env>
void test(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a[i] = ((i%2) ? T(i*2) : T(-2*i))/T(3);
    b[i] = bs::trunc(a[i]) ;
  }

  p_t aa(&a[0], &a[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_IEEE_EQUAL(bs::trunc(aa), bb);
}

STF_CASE_TPL("Check trunc behavior on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL( "Check return type from trunc", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  STF_TYPE_IS(decltype(trunc(bs::pack<T>())), bs::pack<T>);
}

STF_CASE_TPL( "Check trunc behavior on limit cases", STF_NUMERIC_TYPES)
{
  using bs::trunc;
  using bs::Valmin;
  using bs::Valmax;

  STF_EQUAL(trunc(Valmin<bs::pack<T>>()), Valmin<bs::pack<T>>());
  STF_EQUAL(trunc(Valmax<bs::pack<T>>()), Valmax<bs::pack<T>>());
}

STF_CASE_TPL( "Check trunc behavior on IEEE limit cases", STF_IEEE_TYPES)
{
  using bs::trunc;
  using bs::Valmin;
  using bs::Valmax;
  using bs::Inf;
  using bs::Minf;
  using bs::Nan;
  using bs::Maxflint;

  STF_EQUAL(trunc(Inf<bs::pack<T>>())       , Inf<bs::pack<T>>()        );
  STF_EQUAL(trunc(Minf<bs::pack<T>>())      , Minf<bs::pack<T>>()       );
  STF_IEEE_EQUAL(trunc(Nan<bs::pack<T>>())  , Nan<bs::pack<T>>()        );
  STF_EQUAL(trunc(Maxflint<bs::pack<T>>()+1), Maxflint<bs::pack<T>>()+1 );
  STF_EQUAL(trunc(Maxflint<bs::pack<T>>()  ), Maxflint<bs::pack<T>>()   );
  STF_EQUAL(trunc(Maxflint<bs::pack<T>>()-1), Maxflint<bs::pack<T>>()-1 );
}
