#include "stack.h"
#include <iostream>

MalformedExpression::MalformedExpression(string message) {
  msg = message;
}

string MalformedExpression::getMessage() {
  return msg;
}
