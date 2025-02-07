#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "runway.h"

TEST_CASE("Must return opposite direction without suffix") {
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("36") == "18");
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("18") == "36");
}
TEST_CASE("Must accept zero-padded input and return zero-padded output") {
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("19") == "01");
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("01") == "19");

    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("02") == "20");
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("20") == "02");
}
TEST_CASE("Must change suffix when suffix is given in input") {
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("19C") == "01C");
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("19L") == "01R");
    REQUIRE(runway::transform_runway_identifier_to_opposite_direction("19R") == "01L");
}

TEST_CASE("Must throw exception when input is invalid") {
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("40C"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("-12"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("012"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("00"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("37"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("XX"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("1C"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("C"));
    REQUIRE_THROWS(runway::transform_runway_identifier_to_opposite_direction("C12"));
}