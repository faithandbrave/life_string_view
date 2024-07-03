# life_string_view
C++ `string_view` extension with optional life.

`life_string_view` is a `string_view` extension that can be used to extend the life of the string view. This feature can also carry ownership of `string_view`.

This class is useful in many situations where string literals are used, but you want to use string objects in some cases.

## Requirements
- \>= C++17

## Build
- The library is header-only, so you can just include the header file in your project.

## Usage
```cpp example
#include <iostream>
#include "life_string_view.h"

life::life_string_view f(life::life_string_view sv)
{
    return sv.substr(6, 3);
}

life::life_string_view g() {
    std::string s = "Hello C++ World";
    return f(life::life_string_view::allocate(std::move(s)));
}

int main() {
    auto sv = g();
    std::cout << sv << std::endl; // outputs "C++"
}
```

## Run tests
- required CMake 3.24 or later

```sh
# update submodules
git submodule sync
git submodule update --init --recursive

# confugire at "build" directory
cmake -B build

# build tests
cmake --build build --config RelWithDebInfo --target tests

# run tests
./build/tests/tests
```

## Run examples
```sh
# update submodules
git submodule sync
git submodule update --init --recursive

# confugire at "build" directory
cmake -B build

# build tests
cmake --build build --config RelWithDebInfo --target example

# run tests
./build/example/example
```

## Code format
- clang-format version 18.1.8

```sh
sh apply_code_format.sh
```

## License
Boost Software License 1.0
