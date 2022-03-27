// #include "Page.hpp"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>


int main(){

    // ariel::Page* p = new ariel::Page();
    // p->write(1,0,ariel::Direction::Horizontal, "eylon");
    // p->write(1,6,ariel::Direction::Horizontal, "eylon naamat");
    // p->show();
    // std::string ans = p->read(1,0,ariel::Direction::Horizontal, 80);
    // std::cout << ans << std::endl;

    // p->erase(1,0,ariel::Direction::Horizontal, 8);
    // p->show();
    // ans = p->read(1,0,ariel::Direction::Horizontal, 80);
    // std::cout << ans << std::endl;

    // p->erase(2,0,ariel::Direction::Horizontal, 8);
    // p->show();
    // ans = p->read(2,0,ariel::Direction::Horizontal, 80);
    // std::cout << ans << std::endl;

    // ariel::Notebook* book = new ariel::Notebook();


    // ariel::Notebook book;
    // book.write(3, 5, 5, ariel::Direction::Horizontal, "my name is eylon");
    // book.write(3, 4, 5, ariel::Direction::Horizontal, "my name is noam");
    // book.erase(3, 4, 5, ariel::Direction::Horizontal, 16);
    // book.show(3);
    // std::cout << (book.read(3, 5, 5, ariel::Direction::Horizontal, 16) == "my name is eylon") << std::endl;
    // book.erase(3,5,5,ariel::Direction::Horizontal,16);
    // std::cout << (book.read(3, 5, 5, ariel::Direction::Horizontal, 16) == "~~~~~~~~~~~~~~~~") << std::endl;

    // book.write(1,5,5,ariel::Direction::Vertical, "eylon");
    // std::cout << (book.read(1, 5, 5, ariel::Direction::Vertical, 5) == "eylon") << std::endl;
    // book.erase(1,5,5,ariel::Direction::Vertical,5);
    // std::cout << (book.read(1, 5, 5, ariel::Direction::Vertical, 5) == "~~~~~") << std::endl;
    
    // book.write(2,5,5,ariel::Direction::Vertical, "naamat");
    // std::cout << (book.read(2, 5, 5, ariel::Direction::Vertical, 6) == "naamat") << std::endl;
    // book.erase(2,5,5,ariel::Direction::Vertical,6);
    // std::cout << (book.read(2, 5, 5, ariel::Direction::Vertical, 6) == "~~~~~~") << std::endl;

    // book.write(4, 5, 5, ariel::Direction::Horizontal, "cpp");
    // std::cout << (book.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "cpp") << std::endl;
    // book.erase(4,5,5,ariel::Direction::Horizontal,3);
    // std::cout << (book.read(4, 5, 5, ariel::Direction::Horizontal, 3) == "~~~") << std::endl;

    // book.write(102,5,5,ariel::Direction::Vertical, "computer science");
    // std::cout << (book.read(102, 5, 5, ariel::Direction::Vertical, 16) == "computer science") << std::endl;
    // book.erase(102,5,5,ariel::Direction::Vertical,16);
    // std::cout << (book.read(102, 5, 5, ariel::Direction::Vertical, 16) == "~~~~~~~~~~~~~~~~") << std::endl;

    // std::cout << (book.read(100,0,0,ariel::Direction::Vertical, 5) == "_____") << std::endl;
    // std::cout << (book.read(101,0,0,ariel::Direction::Horizontal, 6) == "______") << std::endl;
    // book.write(101, 0,0,ariel::Direction::Horizontal, "");
    // std::cout << (book.read(101,0,0,ariel::Direction::Vertical, 1) == "_") << std::endl;



    // ariel::Notebook book;
    // book.write(1, 0, 0, ariel::Direction::Horizontal, "my name is eylon");
    // (book.write(1,0,0,ariel::Direction::Horizontal, "my name is"));
    // book.erase(1, 0, 0, ariel::Direction::Horizontal, 16);
    // (book.write(1,0,0,ariel::Direction::Horizontal, "my name is"));

    // (book.erase(2,0,0,ariel::Direction::Horizontal, 5));

    // book.erase(1,0,0,ariel::Direction::Horizontal, 16);
    // (book.erase(1,0,0,ariel::Direction::Horizontal, 5));

    // (book.write(2,0,99,ariel::Direction::Horizontal, "eylon"));

    // (book.read(3,0,99,ariel::Direction::Horizontal, 2));

    // book.write(5,0,0,ariel::Direction::Horizontal, "naamat");
    // (book.write(5,0,0,ariel::Direction::Vertical, "naamat"));

    // (book.write(6,0,101,ariel::Direction::Horizontal, "cpp"));

    // book.write(7,1,0,ariel::Direction::Horizontal, "eylon");
    // (book.write(7,0,0,ariel::Direction::Vertical, "cpp"));

    // book.write(8,0,0,ariel::Direction::Horizontal, "computer_science");
    // (book.write(8,0,8, ariel::Direction::Vertical, "cpp"));

    // (book.read(9,0,101, ariel::Direction::Horizontal, 5));


        for ( int i=100; i<200;i++){
        ariel::Notebook note;
        
        
        note.write(1,i-100,0,ariel::Direction::Vertical,"Look at me");
        note.write(1,i-100,2,ariel::Direction::Horizontal,"I'm Mr. meeseeks");
        
        }

    return 0;
}