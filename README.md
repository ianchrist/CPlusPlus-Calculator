# CPlusPlus-Calculator
A simple reverse polish notation calculator written using c++.  It includes support for fractions and variable storage.

To use fractions, you write them as (numerator/denominator).

To store numbers within variables, you write it as follows: NumberToStore S Variable.

To recall this variable, you type R Variable

##Sample
####Here is a sample of what may be done with the calculator.

RPN Calculator

Enter an Expression: (5/6) (2/3) +

Answer: 3/2

Enter an Expression: 5 S A R it +

Answer: 6.5

Enter an Expression: it

Not a Number

Malformed Expression

Enter an Expression: R it

Answer: 13/2

Enter an Expression: (5/6) 3.2 +

Answer: 4.03333
