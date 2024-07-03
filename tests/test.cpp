#include <catch2/catch_test_macros.hpp>

#include "../life_string_view.h"

TEST_CASE("life_string_view", "[basic]") {
  life::life_string_view view{"Hello, World!"};
  REQUIRE(view.size() == 13);
  REQUIRE(view[0] == 'H');
  REQUIRE(view[12] == '!');
  REQUIRE(view.substr(0, 5) == "Hello");
  REQUIRE(view.substr(7, 5) == "World");
}
