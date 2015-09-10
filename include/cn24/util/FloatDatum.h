#ifndef FLOATDATUM_H
#define FLOATDATUM_H

#include "Log.h"

#include <mpfr.h>
#include <ostream>
#include <exception>
#include <stdexcept>
#include <cstddef> // for size_t
#include <cstdint>
#include <type_traits>


namespace Conv {

template <mpfr_prec_t MA>
class FloatDatum {//: boost::operators<FloatDatum<I,F> >, boost::shiftable<FloatDatum<I,F> > {

public:
  FloatDatum() {
    mpfr_init2(data_, MA);
    mpfr_set_flt(data_, 0.0f, rounding_mode_);
  }
  
  // Conversion constructors
  FloatDatum(const int& iv) {
    mpfr_init2(data_, MA);
    mpfr_set_si(data_, iv, rounding_mode_);
  }
  
  // Destructor
  ~FloatDatum() {
    mpfr_clear(data_);
  }
  
  // Assignment operator
  FloatDatum& operator=(const FloatDatum& x) {
    mpfr_set(data_, x.data_, rounding_mode_);
    return *this;
  }
  
  // Arithmetic operators
  FloatDatum& operator+=(const FloatDatum& x) {
    mpfr_add(data_, data_, x.data_, rounding_mode_);
    return *this;
  }
  friend FloatDatum operator+(FloatDatum lhs, const FloatDatum& rhs) {
    lhs += rhs;
    return lhs;
  }
  
  FloatDatum& operator-=(const FloatDatum& x) {
    mpfr_sub(data_, data_, x.data_, rounding_mode_);
    return *this;
  }
  friend FloatDatum operator-(FloatDatum lhs, const FloatDatum& rhs) {
    lhs -= rhs;
    return lhs;
  }
  
  FloatDatum& operator*=(const FloatDatum& x) {
    mpfr_mul(data_, data_, x.data_, rounding_mode_);
    return *this;
  }
  friend FloatDatum operator*(FloatDatum lhs, const FloatDatum& rhs) {
    lhs *= rhs;
    return lhs;
  }
  
  // Conversion operators

private:
  mpfr_t data_;
  mpfr_rnd_t rounding_mode_ = MPFR_RNDN;


};
}

#endif