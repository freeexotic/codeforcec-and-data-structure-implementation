#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>
#include <rational/rational.hpp>

Rational::Rational(int64_t num, int64_t den) : num_(num), den_(den) {
  if (den_ == 0) {
    throw std::runtime_error("Rational devision by zero");
  }
  else if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }

  simplifying();
}

Rational& Rational::operator=(const Rational& rhs) {
  num_ = rhs.num_;
  den_ = rhs.den_;
  return *this;
}
Rational& Rational::operator+=(const Rational& rhs) {
  int64_t tmp = gcd(den_, rhs.den_);
  num_ = num_ * (rhs.den_ / tmp) + rhs.num_ * (den_ / tmp);
  den_ = den_ / tmp * rhs.den_;
  
  simplifying();
  return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
  int64_t tmp = gcd(den_, rhs.den_);
  num_ = num_ * (rhs.den_ / tmp) - rhs.num_ * (den_ / tmp);
  den_ = den_ / tmp * rhs.den_;

  simplifying();
  return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
  num_ *= rhs.num_;
  den_ *= rhs.den_;

  simplifying();
  return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0)
    throw std::runtime_error("Rational division by zero");

  num_ *= rhs.den_;
  den_ *= rhs.num_;

  simplifying();
  return *this;
}
Rational& Rational::operator+=(const int64_t& rhs) {
  *this += Rational(rhs);
  return *this;
}
Rational& Rational::operator-=(const int64_t& rhs) {
  *this -= Rational(rhs);
  return *this;
}
Rational& Rational::operator*=(const int64_t& rhs) {
  *this *= Rational(rhs);
  return *this;
}
Rational& Rational::operator/=(const int64_t& rhs) {
  *this /= Rational(rhs);
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational ans(lhs);
  ans += rhs;
  return ans;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational ans(lhs);
  ans -= rhs;
  return ans;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational ans(lhs);
  ans *= rhs;
  return ans;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational ans(lhs);
  ans /= rhs;
  return ans;
}
Rational operator+(const Rational& lhs, const int64_t rhs) {
  return lhs + Rational(rhs);
}
Rational operator-(const Rational& lhs, const int64_t rhs) {
  return lhs - Rational(rhs);
}
Rational operator*(const Rational& lhs, const int64_t rhs) {
  return lhs * Rational(rhs);
}
Rational operator/(const Rational& lhs, const int64_t rhs) {
  return lhs / Rational(rhs);
}
Rational operator+(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) + rhs;
}
Rational operator-(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) - rhs;
}
Rational operator*(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) * rhs;
}
Rational operator/(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) / rhs;
}

bool Rational::operator<(const Rational& rhs) const {
  if (num_ == 0)
    return rhs.num() > 0;
  else if (rhs.num() == 0)
    return num_ < 0;
  else if (std::numeric_limits<int64_t>::max() / num_ < rhs.den() || 
           std::numeric_limits<int64_t>::max() / rhs.num() < den_)
    return (num_ / static_cast<long double>(den_) - rhs.num() / static_cast<long double>(rhs.den())) 
              < -2 * std::numeric_limits<long double>::epsilon();
  else
    return num_ * rhs.den() < den_ * rhs.num();
}
bool Rational::operator<=(const Rational& rhs) const
{
  return *this < rhs || *this == rhs;
}
bool Rational::operator==(const Rational& rhs) const
{
  return !(*this < rhs) && !(rhs < *this);
}
bool Rational::operator!=(const Rational& rhs) const
{
  return !(*this == rhs);
}
bool Rational::operator>=(const Rational& rhs) const
{
  return !(*this < rhs);
}
bool Rational::operator>(const Rational& rhs) const
{
  return !(*this <= rhs);
}
bool operator<(const Rational& lhs, const int64_t rhs) {
  return lhs < Rational(rhs);
}
bool operator<=(const Rational& lhs, const int64_t rhs)
{
  return lhs <= Rational(rhs);
}
bool operator==(const Rational& lhs, const int64_t rhs)
{
  return lhs == Rational(rhs);
}
bool operator!=(const Rational& lhs, const int64_t rhs)
{
  return lhs != Rational(rhs);
}
bool operator>=(const Rational& lhs, const int64_t rhs)
{
  return lhs >= Rational(rhs);
}
bool operator>(const Rational& lhs, const int64_t rhs)
{
  return lhs > Rational(rhs);
}
bool operator<(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs)<rhs;
}
bool operator<=(const int64_t lhs, const Rational& rhs)
{
  return Rational(lhs) <= rhs;
}
bool operator==(const int64_t lhs, const Rational& rhs)
{
  return Rational(lhs) == rhs;
}
bool operator!=(const int64_t lhs, const Rational& rhs)
{
  return Rational(lhs) != rhs;
}
bool operator>=(const int64_t lhs, const Rational& rhs)
{
  return Rational(lhs) >= rhs;
}
bool operator>(const int64_t lhs, const Rational& rhs)
{
  return Rational(lhs) > rhs;
}

std::ostream& Rational::WriteTo(std::ostream& stream) const {
  stream << num_ << Rational::separator_ << den_;
  return stream;
}
std::istream& Rational::ReadFrom(std::istream& stream) {
  int64_t num = 0;
  int64_t den = 1;
  char split_ch = '\0';
  stream >> num;
  stream.get(split_ch);
  char tmp = stream.peek();
  stream >> den;

  if (stream.good() || stream.eof()) {
    if (split_ch == Rational::separator_ && den > 0 && '0' <= tmp && tmp <= '9') {
      num_ = num;
      den_ = den;
      simplifying();
    }
    else {
      stream.setstate(std::ios_base::failbit);
    }
  }

  return stream;
}

std::istream& operator>>(std::istream& stream, Rational& rhs) {
  return rhs.ReadFrom(stream);
}
std::ostream& operator<<(std::ostream& stream, const Rational rhs) {
  return rhs.WriteTo(stream);
}