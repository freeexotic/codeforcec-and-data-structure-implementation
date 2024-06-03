#ifndef RATIONAL_RATIONAL_HPP
#define RATIONAL_RATIONAL_HPP

#include <iosfwd>
#include <cstdint>
#include <cmath>
#include <limits>

class Rational {
public:
  Rational() : num_(0), den_(1) {};
  Rational(const Rational&) = default;
  Rational(const int64_t num, const int64_t den);
  explicit Rational(const int64_t num) : Rational(num, 1) {}
  ~Rational() = default;

  Rational operator-() const noexcept { return { -num_, den_ }; }
  Rational& operator= (const Rational& rhs);
  Rational& operator+=(const Rational& rhs);
  Rational& operator-=(const Rational& rhs);
  Rational& operator*=(const Rational& rhs);
  Rational& operator/=(const Rational& rhs);
  Rational& operator+=(const int64_t& rhs);
  Rational& operator-=(const int64_t& rhs);
  Rational& operator*=(const int64_t& rhs);
  Rational& operator/=(const int64_t& rhs);

  std::ostream& WriteTo(std::ostream& stream) const;
  std::istream& ReadFrom(std::istream& stream);

  int64_t num() const { return num_; }
  int64_t den() const { return den_; }

  static char get_separator() { return separator_; }
  bool operator<(const Rational& rhs) const;
  bool operator<=(const Rational& rhs) const;
  bool operator==(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
private:
  int64_t gcd(int64_t lhs, int64_t rhs) {
    return lhs == 0 ? rhs : gcd(rhs % lhs, lhs);
  }
  void simplifying() {
    int64_t common_mult = gcd(std::abs(num_), den_);
    num_ /= common_mult;
    den_ /= common_mult;
  }

  int64_t num_ = 0;
  int64_t den_ = 1;

  static const char separator_ = '/';
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int64_t rhs);
Rational operator-(const Rational& lhs, const int64_t rhs);
Rational operator*(const Rational& lhs, const int64_t rhs);
Rational operator/(const Rational& lhs, const int64_t rhs);
Rational operator+(const int64_t lhs, const Rational& rhs);
Rational operator-(const int64_t lhs, const Rational& rhs);
Rational operator*(const int64_t lhs, const Rational& rhs);
Rational operator/(const int64_t lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const int64_t rhs);
bool operator<=(const Rational& lhs, const int64_t rhs);
bool operator==(const Rational& lhs, const int64_t rhs);
bool operator!=(const Rational& lhs, const int64_t rhs);
bool operator>=(const Rational& lhs, const int64_t rhs);
bool operator>(const Rational& lhs, const int64_t rhs);
bool operator<(const int64_t lhs, const Rational& rhs);
bool operator<=(const int64_t lhs, const Rational& rhs);
bool operator==(const int64_t lhs, const Rational& rhs);
bool operator!=(const int64_t lhs, const Rational& rhs);
bool operator>=(const int64_t lhs, const Rational& rhs);
bool operator>(const int64_t lhs, const Rational& rhs);

std::istream& operator>>(std::istream& stream, Rational& rhs);
std::ostream& operator<<(std::ostream& stream, const Rational rhs);
#endif