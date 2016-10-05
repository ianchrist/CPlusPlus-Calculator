#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include "fraction.h"
#include "stack.h"


using namespace std;

int main(int argc, char* argv[]) {
  bool dd;
  char delimiter, token;
  double real;
  Fraction answer, valOne,valTwo;
  int num,den;
  map<string, Fraction> memory;
  Stack <Fraction> stack;
  string s,key;


  cout << "RPN Calculator" << endl;
  cout << "Enter an Expression: ";
  getline(cin, s);

  try{

  while (s!="") {
    istringstream sin(s + " ");
    sin >> token;
 
      while (!sin.eof()) {
     
        switch (token) {
                 case '+':
                   valOne = stack.pop();
                   valTwo = stack.pop();
                   answer = valOne + valTwo;
                   stack.push(answer);
                 break;

                 case '-':
                   valOne = stack.pop();
                   valTwo = stack.pop();
                   answer = valOne - valTwo;
                   stack.push(answer);
                 break;

                 case '*':
                   valOne = stack.pop();
                   valTwo = stack.pop();
                   answer = valOne * valTwo;
                   stack.push(answer);
                 break;

                 case '/':
                   valOne = stack.pop();
                   valTwo = stack.pop();
                   answer = valTwo / valOne;
                   stack.push(answer);
                 break;

                 case 'S':
                   sin >> key;
                   memory[key] = stack.top();
                 
                 break;

                 case 'R':
                   sin >> key;
                   stack.push(memory[key]);
                 break;

                 case '(':
                   sin >> num;
                   sin >> delimiter;
                   sin >> den;
                   sin >> delimiter;
                   stack.push(Fraction(num,den));
                 break;

                 default:
                   sin.putback(token);
                   sin >> real;
                   dd = false;

                   if (sin.fail()) {
                      cout << "Not a Number" << endl;
                      throw "Malformed Number";
                   }

                   den = 1;
                   while (abs((int)real - real) > 0.000000000000001) {
                      real = real * 10;
                      den = den * 10;
                   }

                   stack.push(Fraction((int) real, den));
                   dd = true;
                 break;
               }
   
      sin >> token;
      }
    answer = stack.pop();
    if (dd != true) {
     memory["it"] = answer;
     cout << "The answer is: " << answer << endl;
    }
    else if (dd == true) {
      memory["it"] = answer.asDouble();
      cout << "The answer is: " << answer.asDouble() << endl;
      dd = false;
    } 
    cout << "Enter an Expression: ";
    getline(cin, s);
  }
 
 }catch(...) {
    cerr << "Malformed Expression" << endl;
    cout << "Enter an Expression: ";
    getline(cin, s);
 } 
 
  return 0;
}
