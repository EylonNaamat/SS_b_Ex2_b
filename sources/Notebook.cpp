#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"


void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string& text){
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].write(row, column, direction, text);
}
std::string ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    return book[page].read(row, column, direction, length);
}
void ariel::Notebook::erase(int page, int row, int column, ariel::Direction direction, int length){
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].erase(row, column, direction, length);
}
void ariel::Notebook::show(int page){
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].show();
}

