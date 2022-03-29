#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"


/**
 * @brief in this function we check if the page number is under 0, if so throw exception
 * if not we check if the page exists in the map
 * if not we create it and then call write function of page with the proper arguments
 * 
 * @param page 
 * @param row 
 * @param column 
 * @param direction 
 * @param text 
 */
void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string& text){
    if(page < min_num){
        throw std::invalid_argument("page number cant be less than 0!");
    }
    
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].write(row, column, direction, text);
}

/**
 * @brief in this function we check if the page number is under 0 if so throw exception
 * if not we check if the page exists if not we create it and call the read function of page with the right arguments
 * 
 * @param page 
 * @param row 
 * @param column 
 * @param direction 
 * @param length 
 * @return std::string 
 */
std::string ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    if(page < min_num){
        throw std::invalid_argument("page number cant be less than 0!");
    }
    
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    return book[page].read(row, column, direction, length);
}

/**
 * @brief in this function we check if the page number is under 0, if so throw exception
 * if not we check if the page exists in the map
 * if not we create it and then call erase function of page with the proper arguments 
 * 
 * @param page 
 * @param row 
 * @param column 
 * @param direction 
 * @param length 
 */
void ariel::Notebook::erase(int page, int row, int column, ariel::Direction direction, int length){
    if(page < min_num){
        throw std::invalid_argument("page number cant be less than 0!");
    }
    
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].erase(row, column, direction, length);
}

/**
 * @brief in this function we check if the page number is under 0, if so throw exception
 * if not we check if the page exists in the map
 * if not we create it and then call show function of page with the proper arguments 
 * 
 * @param page 
 */
void ariel::Notebook::show(int page){
    if(page < min_num){
        throw std::invalid_argument("page number cant be less than 0!");
    }
    
    if(book.find(page) == book.end()){
        Page p;
        std::pair<int, Page> pr;
        pr.first = page;
        pr.second = p;
        book.insert(pr);
    }
    book[page].show();
}

