// Copyright 2022 Andrich Maria

#define is_operator(c1)(c1 == '+' || c1 == '-' || c1 == '/' || \
  c1 == '*' || c1 == '!' || c1 == '%' || c1 == '=')
#define is_function(c1)(c1 >= 'A' && c1 <= 'Z')
#define is_ident(c1)((c1 >= '0' && c1 <= '9') || (c1 >= 'a' && c1 <= 'z'))

#include <string>

#include "../include/SortFacility.h"

int Sort::op_preced(const char c1) {
  switch (c1) {
  case '!':
    return 4;
  case '*':
  case '/':
  case '%':
    return 3;
  case '+':
  case '-':
    return 2;
  case '=':
    return 1;
  }
  return 0;
}

bool Sort::op_left_assoc(const char c1) {
  switch (c1) {
  case '*':
  case '/':
  case '%':
  case '+':
  case '-':
  case '=':
    return true;
  case '!':
    return false;
  }
  return false;
}

unsigned int Sort::op_arg_count(const char c1) {
  switch (c1) {
  case '*':
  case '/':
  case '%':
  case '+':
  case '-':
  case '=':
    return 2;
  case '!':
    return 1;
  default:
    return c1 - 'A';
  }
  return 0;
}

bool Sort::shunting_yard(const char * input, char * output) {
  const char * strpos = input,
    * strend = input + strlen(input);
  char stack[32], sc, * outpos = output;
  unsigned int sl = 0;
  while (strpos < strend) {
    char c1 = * strpos;
    if (c1 != ' ') {
      if (is_ident(c1)) {
        * outpos = c1;
        ++outpos;
      } else if (is_function(c1)) {
        stack[sl] = c1;
        ++sl;
      } else if (c1 == ',') {
        bool pe = false;
        while (sl > 0) {
          sc = stack[sl - 1];
          if (sc == '(') {
            pe = true;
            break;
          } else {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
        if (!pe) {
          throw("Error: separator or parentheses mismatched\n");
          return false;
        }
      } else if (is_operator(c1)) {
        while (sl > 0) {
          sc = stack[sl - 1];
          if (is_operator(sc) &&
            ((op_left_assoc(c1) &&
                (op_preced(c1) <= op_preced(sc))) ||
              (!op_left_assoc(c1) &&
                (op_preced(c1) < op_preced(sc))))) {
            * outpos = sc;
            ++outpos;
            sl--;
          } else {
            break;
          }
        }
        stack[sl] = c1;
        ++sl;
      } else if (c1 == '(') {
        stack[sl] = c1;
        ++sl;
      } else if (c1 == ')') {
        bool pe = false;

        while (sl > 0) {
          sc = stack[sl - 1];
          if (sc == '(') {
            pe = true;
            break;
          } else {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
        if (!pe) {
          throw("Error: parentheses mismatched\n");
          return false;
        }
        sl--;
        if (sl > 0) {
          sc = stack[sl - 1];
          if (is_function(sc)) {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
      } else {
        throw("Unknown token %c\n", c1);
        return false;
      }
    }
    ++strpos;
  }

  while (sl > 0) {
    sc = stack[sl - 1];
    if (sc == '(' || sc == ')') {
      throw("Error: parentheses mismatched\n");
      return false;
    }
    * outpos = sc;
    ++outpos;
    --sl;
  }
  * outpos = 0;
  return true;
}
