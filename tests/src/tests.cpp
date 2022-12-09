#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("get_duration"){
    Duration d1;
    Duration d2 = Duration(6);
    Duration d3 = Duration(15);

    REQUIRE(d1.get_duration() == 0);
    REQUIRE(d2.get_duration() == 6);
    REQUIRE(d3.get_duration() == 15); 
}

TEST_CASE("tick"){
    Duration d1;
    Duration d2;
    Duration d3;

    d1.tick();
    d2.tick(4);
    d3.tick(8);

    REQUIRE(d1.get_duration() == 1);
    REQUIRE(d2.get_duration() == 4);
    REQUIRE(d3.get_duration() == 8);
}
TEST_CASE("set_alarm"){
    Duration d1;
    Duration d2;
    Duration d3;
    Duration d4;
    d1.set_alarm(2);
    d2.set_alarm(3);
    d3.set_alarm(5);
    d4.set_alarm(7);

    
    REQUIRE_FALSE(d1.tick());
    REQUIRE_FALSE(d2.tick());
    REQUIRE_FALSE(d3.tick());
    REQUIRE_FALSE(d4.tick());
    
    REQUIRE(d1.tick());
    REQUIRE_FALSE(d2.tick());
    REQUIRE_FALSE(d3.tick());
    REQUIRE_FALSE(d4.tick());

    REQUIRE_FALSE(d1.tick());
    REQUIRE(d2.tick());
    REQUIRE_FALSE(d3.tick());
    REQUIRE_FALSE(d4.tick());

    //Check that it also returns true when you overshoot the alarm time with tick.
    REQUIRE(d3.tick(10));

    //It should only return true once.
    REQUIRE_FALSE(d3.tick());

}