#include <iostream>

#include "../life_string_view.h"

life::life_string_view f(life::life_string_view sv) { return sv.substr(6, 3); }

life::life_string_view g() {
  std::string s = "Hello C++ World";
  return f(life::life_string_view::allocate(std::move(s)));
}

int main() {
  auto sv = g();
  std::cout << sv << std::endl;
}
