#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;
using ariel::Direction;

//54 + 7 = 61



TEST_CASE("Write function"){ // 7 tests
    Notebook empty_notebook;
    empty_notebook.write(100, 97, 53, Direction::Horizontal, "mnop");                             //___mnop_
    empty_notebook.write(100, 98, 52, Direction::Horizontal, "ijkl");                             //__ijkl__
    empty_notebook.write(100, 99, 51, Direction::Horizontal, "efgh");                             //_efgh___
    empty_notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");//abcd____

    CHECK(empty_notebook.read(100, 97, 53, Direction::Vertical, 4) == "mjgd"); 
    CHECK(empty_notebook.read(100, 97, 52, Direction::Vertical, 4) == "_ifc"); 
    CHECK(empty_notebook.read(100, 97, 50, Direction::Horizontal, 4) == "___m"); 
    CHECK(empty_notebook.read(100, 99, 50, Direction::Horizontal, 4) == "_efg"); 

    CHECK_FALSE(empty_notebook.read(100, 97, 53, Direction::Vertical, 4) == "mjgd__");
    CHECK_FALSE(empty_notebook.read(100, 100, 50, Direction::Horizontal, 4) == "abcd___");
    CHECK_FALSE(empty_notebook.read(99, 100, 50, Direction::Horizontal, 4) == "abcd");

}    

TEST_CASE("Erase function"){ // 54 tests
    const unsigned int pageNumber = 100;
    Notebook empty_notebook;
    empty_notebook.write(pageNumber, 97, 53, Direction::Horizontal, "mnop");                             //___mnop
    empty_notebook.write(pageNumber, 98, 52, Direction::Horizontal, "ijkl");                             //__ijkl_
    empty_notebook.write(pageNumber, 99, 51, Direction::Horizontal, "efgh");                             //_efgh__
    empty_notebook.write(/*page=*/pageNumber, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");//abcd___
    empty_notebook.erase(pageNumber, 97, 53, Direction::Vertical, 2);//~~gd
    empty_notebook.erase(pageNumber, 97, 54, Direction::Vertical, 4);//nkh_ -> ~~~~
    empty_notebook.erase(pageNumber, 100, 50, Direction::Horizontal, 3);//abcd -> ~~~d
    //___~~op
    //__i~~l_
    //_efg~__
    //~~~d~__  page 100 now

    CHECK(empty_notebook.read(pageNumber, 97, 53, Direction::Vertical, 4) == "~~gd"); 
    CHECK(empty_notebook.read(pageNumber, 97, 52, Direction::Vertical, 4) == "_jfc"); 
    CHECK(empty_notebook.read(pageNumber, 97, 50, Direction::Horizontal, 4) == "___~"); 
    CHECK(empty_notebook.read(pageNumber, 99, 50, Direction::Horizontal, 5) == "_efg~"); 

    empty_notebook.erase(pageNumber, 97, 50, Direction::Horizontal, 7);
    empty_notebook.erase(pageNumber, 98, 50, Direction::Horizontal, 7);
    empty_notebook.erase(pageNumber, 99, 50, Direction::Horizontal, 7);
    empty_notebook.erase(pageNumber, 100, 50, Direction::Horizontal, 7);
    //~~~~~~~
    //~~~~~~~
    //~~~~~~~
    //~~~~~~~

    //about 25 tests
    const unsigned int colNumber = 97;
    const unsigned int rowNumber = 50;
    for (unsigned int i = 0; i < 5; i++){
        for(unsigned int j = 0; j< 5; j++){
            CHECK(empty_notebook.read(pageNumber, colNumber+i, rowNumber+j, Direction::Horizontal, 2) == "~~");
            CHECK(empty_notebook.read(pageNumber, colNumber+i, rowNumber+j, Direction::Vertical, 2) == "~~");
        }
    }
    
    empty_notebook.write(pageNumber, 97, 53, Direction::Horizontal, "a~b~c~d");                             //a~b~c~d
    empty_notebook.write(pageNumber, 98, 52, Direction::Horizontal, "~e~f~g~");                             //~e~f~g~
    empty_notebook.write(pageNumber, 99, 51, Direction::Horizontal, "h~i~j~k");                             //h~i~j~k
    empty_notebook.write(/*page=*/pageNumber, /*row=*/100, /*column=*/50, Direction::Horizontal, "~l~m~n~");//~l~m~n~

    //more 25 tests
    for (unsigned int i = 0; i < 5; i++){
        for(unsigned int j = 0; j< 5; j++){
            string hori = empty_notebook.read(pageNumber, colNumber+i, rowNumber+j, Direction::Horizontal, 2);
            string verti = empty_notebook.read(pageNumber, colNumber+i, rowNumber+j, Direction::Vertical, 2);
            long h = std::count(hori.begin(), hori.end(), '~');
            long v = std::count(verti.begin(), verti.end(), '~');
            CHECK(v == 1);
            CHECK(h == 1);
        }
    }
}