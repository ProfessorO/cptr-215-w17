#include "doctest.h"
#include "mytime.h"
#include <sstream>

TEST_CASE("Time::Time")
{
    CHECK(Time().toString() == "00:00");
    CHECK(Time() == Time(0, 0));
    CHECK(Time(3, 45).toString() == "03:45");
    CHECK(Time(23, 59).toString() == "23:59");
    CHECK(Time(55, 47).toString() == "55:47"); // elapsed time, not TOD
    CHECK(Time(123, 0).toString() == "123:00"); // hours > 99 "overflow" field
    CHECK(Time(-5, 15).toString() == "-05:15");
    CHECK(Time(0, -1).toString() == "-00:01");
    CHECK(Time(3, 75) == Time(4, 15));
    CHECK(Time(3, -5) == Time(2, 55));
    CHECK(Time(17) == Time(0, 17));
    CHECK(Time(99) == Time(1, 39));
    CHECK(Time("4:56") == Time(4, 56));
    CHECK(Time("02:34") == Time(2, 34));
    CHECK(Time("-0:5") == Time(0, -5));
}

TEST_CASE("Time::operator+")
{
    CHECK((Time() + 15).toString() == "00:15");
    CHECK((Time(1, 23) + 90).toString() == "02:53");
    CHECK(Time(3, 5) + (-30) == Time(2, 35));
    CHECK(Time("1:20") + Time("2:30") == Time("3:50"));
    CHECK(Time("1:23") + Time("4:56") == Time("6:19"));
    CHECK(Time("1:00") + Time("-0:01") == Time("0:59"));
}

TEST_CASE("Time::operator-")
{
    CHECK(Time("12:00") - 60 == Time("11:00"));
    CHECK(Time("12:00") - 15 == Time("11:45"));
    CHECK(Time("12:00") - 99 == Time("10:21"));
    CHECK(Time("12:00") - Time("1:30") == Time("10:30"));
    CHECK(Time("0:00") - 1 == Time(0, -1));
    CHECK(Time("0:23") - 90 == Time(-1, 7));
    CHECK(Time("12:00") - Time("13:00") == Time("-1:00"));
    CHECK(Time("-0:10") - Time("1:20") == Time("-1:30"));
}

TEST_CASE("Time comparison")
{
    // TODO: check for <, <=, ==, >=, >, !=
}

TEST_CASE("Time input")
{
    std::stringstream fakeCin("12:00\n3:45");
    Time time;

    fakeCin >> time;
    CHECK(time == Time(12, 0));
    fakeCin >> time;
    CHECK(time == Time(3, 45));
    // TODO: Add more assertions
}

TEST_CASE("Time output")
{
    std::stringstream fakeCout;
    Time time;

    fakeCout << time;
    CHECK(fakeCout.str() == "00:00");
    // TODO: Add more assertions
}
