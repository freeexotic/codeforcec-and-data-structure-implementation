#ifndef COMPLEX_H_20240210
#define COMPLEX_H_20240210

#include <iosfwd>


struct Complex {
 
  [[nodiscard]] Complex() = default;

  [[nodiscard]] Complex(const Complex&) = default;

  Complex(Complex&&) = default;




  [[nodiscard]] explicit Complex(const double real) : re(real) { }


  [[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

  Complex& operator=(const Complex&) = default;

    Complex& operator=(Complex&&) = default;


  ~Complex() = default;



  [[nodiscard]] Complex operator-() const noexcept;

  
  [[nodiscard]] bool operator==(const Complex& rhs) const noexcept;

  [[nodiscard]] bool operator!=(const Complex& rhs) const noexcept;

  Complex& operator+=(const Complex& rhs) noexcept;
  Complex& operator+=(const double rhs) noexcept;
  Complex& operator-=(const Complex& rhs) noexcept;
  Complex& operator-=(const double rhs) noexcept;
  Complex& operator*=(const Complex& rhs) noexcept;
  Complex& operator*=(const double rhs) noexcept;
  Complex& operator/=(const Complex& rhs);

  Complex& operator/=(const double rhs);

  [[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  [[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

  double re{ 0.0 }; 
  double im{ 0.0 }; 

  static const char leftBrace{ '{' };   
  static const char separator{ ',' };   
  static const char rightBrace{ '}' };  
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;

[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;

[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;

[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);

[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);

[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}

#endif