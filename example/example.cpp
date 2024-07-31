#include <iostream>

#include "../life_string_view.h"

life::life_string_view f(life::life_string_view sv) { return sv.substr(6, 3); }

life::life_string_view g() {
    std::string s = "Hello C++ World";
    return f(life::life_string_view::allocate(std::move(s)));
}

life::life_string_view h() {
    try {
        throw std::runtime_error("my error");
    }
    catch (std::runtime_error& e) {
        // NOTE:
        // e.what() returns const char*, but const char* can't use for lifetime object
        // You should convert to std::string
        return life::life_string_view::allocate(std::string{e.what()});
    }
}

int main() {
    auto svg = g();
    std::cout << svg << std::endl;

    auto svh = h();
    std::cout << svh << std::endl;
}
