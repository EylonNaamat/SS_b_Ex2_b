#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"

#include <string>
using namespace std;


TEST_CASE("Good input"){
    ariel::Notebook book;
    book.write(3, 5, 5, ariel::Direction::Horizontal, "my name is eylon");
    CHECK(book.read(3, 5, 5, ariel::Direction::Horizontal, 16) == "my name is eylon");
    book.erase(3,5,5,ariel::Direction::Horizontal,16);
    CHECK(book.read(3, 5, 5, ariel::Direction::Horizontal, 16) == "~~~~~~~~~~~~~~~~");

    book.write(1,5,5,ariel::Direction::Vertical, "eylon");
    CHECK(book.read(1, 5, 5, ariel::Direction::Vertical, 5) == "eylon");
    book.erase(1,5,5,ariel::Direction::Vertical,5);
    CHECK(book.read(1, 5, 5, ariel::Direction::Vertical, 5) == "~~~~~");
    
    book.write(2,5,5,ariel::Direction::Vertical, "naamat");
    CHECK(book.read(2, 5, 5, ariel::Direction::Vertical, 6) == "naamat");
    book.erase(2,5,5,ariel::Direction::Vertical,6);
    CHECK(book.read(2, 5, 5, ariel::Direction::Vertical, 6) == "~~~~~~");

    book.write(4, 5, 5, ariel::Direction::Horizontal, "cpp");
    CHECK(book.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "cpp");
    book.erase(4,5,5,ariel::Direction::Horizontal,3);
    CHECK(book.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "~~~");

    book.write(102,5,5,ariel::Direction::Vertical, "computer science");
    CHECK(book.read(102, 5, 5, ariel::Direction::Vertical, 16) == "computer science");
    book.erase(102,5,5,ariel::Direction::Vertical,16);
    CHECK(book.read(102, 5, 5, ariel::Direction::Vertical, 16) == "~~~~~~~~~~~~~~~~");

    CHECK(book.read(100,0,0,ariel::Direction::Vertical, 5) == "_____");
    CHECK(book.read(101,0,0,ariel::Direction::Horizontal, 6) == "______");
    book.write(101, 0,0,ariel::Direction::Horizontal, "");
    CHECK(book.read(101,0,0,ariel::Direction::Vertical, 1) == "_");


}
TEST_CASE("Bad input"){
    ariel::Notebook book;
    book.write(1, 0, 0, ariel::Direction::Horizontal, "my name is eylon");
    CHECK_THROWS(book.write(1,0,0,ariel::Direction::Horizontal, "my name is"));
    book.erase(1, 0, 0, ariel::Direction::Horizontal, 16);
    CHECK_THROWS(book.write(1,0,0,ariel::Direction::Horizontal, "my name is"));

    CHECK_THROWS(book.erase(2,0,0,ariel::Direction::Horizontal, 5));

    book.erase(1,0,0,ariel::Direction::Horizontal, 16);
    CHECK_THROWS(book.erase(1,0,0,ariel::Direction::Horizontal, 5));

    CHECK_THROWS(book.write(2,0,99,ariel::Direction::Horizontal, "eylon"));

    CHECK_THROWS(book.read(3,0,99,ariel::Direction::Horizontal, 8));

    book.write(5,0,0,ariel::Direction::Horizontal, "naamat");
    CHECK_THROWS(book.write(5,0,0,ariel::Direction::Vertical, "naamat"));

    CHECK_THROWS(book.write(6,0,101,ariel::Direction::Horizontal, "cpp"));

    book.write(7,1,0,ariel::Direction::Horizontal, "eylon");
    CHECK_THROWS(book.write(7,0,0,ariel::Direction::Vertical, "cpp"));

    book.write(8,0,0,ariel::Direction::Horizontal, "computer science");
    CHECK_THROWS(book.write(8,0,3, ariel::Direction::Vertical, "cpp"));

    CHECK_THROWS(book.read(9,0,101, ariel::Direction::Horizontal, 5));

    CHECK_THROWS(book.write(-1,0,0,ariel::Direction::Horizontal,"cpp"));
    CHECK_THROWS(book.write(1,-1,0,ariel::Direction::Horizontal,"cpp"));
    CHECK_THROWS(book.write(1,0,-1,ariel::Direction::Horizontal,"cpp"));
    CHECK_THROWS(book.read(1,0,0,ariel::Direction::Horizontal,-1));

}