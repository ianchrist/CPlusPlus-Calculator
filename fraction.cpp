#include "fraction.h"

int gcd(int x, int y) {
  if (y==0) 
    return x;

  return gcd(y, x%y);
}

Fraction::Fraction() {
  top = 0; 
  bottom = 1;
}

Fraction::Fraction(int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(int numerator, int denominator) {
 
  gcd(numerator, denominator);
  
  top = numerator/ gcd(numerator, denominator);
  bottom = denominator / gcd(numerator, denominator);
}

int Fraction::numerator() const{
  return top;
}

int Fraction::denominator() const{
  return bottom;
}

double Fraction::asDouble() const{
  return ((double)top)/((double)bottom);
}

Fraction Fraction::add(const Fraction& other) const{
  int aTop = numerator();
  int aBottom = denominator();   
  int bTop = other.numerator();
  int bBottom = other.denominator();
  int num = aTop*bBottom+bTop*aBottom;
  int den = aBottom*bBottom;
  return  Fraction(num, den);
}

Fraction Fraction::subtract(const Fraction& other) const{
  int aTop = numerator();
  int aBottom = denominator();   
  int bTop = other.numerator();
  int bBottom = other.denominator();
  int num = bTop*aBottom-aTop*bBottom;
  int den = aBottom*bBottom;
  return Fraction(num, den);
}

Fraction Fraction::divide(const Fraction& other) const{
  int aTop = numerator();
  int aBottom = denominator();   
  int bTop = other.numerator();
  int bBottom = other.denominator();
  int num = aTop*bBottom;
  int den = aBottom*bTop;
  return Fraction(num, den);
}

Fraction Fraction::multiply(const Fraction& other) const{
  int aTop = numerator();
  int aBottom = denominator();   
  int bTop = other.numerator();
  int bBottom = other.denominator();
  int num = aTop*bTop;
  int den = aBottom*bBottom;
  return Fraction(num, den);
}

Fraction operator+(const Fraction& a, const Fraction& b) {
  return a.add(b);
}


Fraction operator-(const Fraction& a, const Fraction& b) {
  return a.subtract(b);
}

Fraction operator*(const Fraction& a, const Fraction& b) {
  return a.multiply(b);
}

Fraction operator/(const Fraction& a, const Fraction& b) {
   return a.divide(b);
}

ostream& operator<<(ostream& stream, const Fraction& f) {
  stream << f.numerator() << '/' << f.denominator();

  return stream;  
}