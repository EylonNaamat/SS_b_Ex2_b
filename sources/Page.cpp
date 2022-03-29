#include "Direction.hpp"
#include "Page.hpp"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>

/**
 * @brief write function. gets number of row, col, direction of writing and the text and writes it in the notebook
 * first we check if the input is good, if not throw excption
 * if the text size is bigger than 100  or col + text size is bigger than 100 and the direction is horizantal throw exception
 * than we check if the text inserted is good, if not throw exception
 * if the direction is horizantal we go to write_horizantal func
 * if the direction is vertical we go to write_vertical func
 * 
 * @param row 
 * @param col 
 * @param direction 
 * @param text 
 */
void ariel::Page::write(int row, int col, ariel::Direction direction, const std::string& text){
    if(row < min_num || col < min_num){
        throw std::invalid_argument("row or col number cant be less than 0!");
    }
    if(col >= row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(int(text.size()) > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant write more than 100");
    }

    if(col + (int)(text.size()) > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant write more than 100 chars");
    }

    for(int i = 0; i < (int)(text.size()); ++i){
        if(text[(uint)(i)] < char_min || text[(uint)(i)] > char_max){
            throw std::invalid_argument("cant write ~");
        }
    }

    if(direction == Direction::Horizontal){
        write_horizontal(row, col, text);
    }else{
        write_vertical(row, col, text);
    }
}

/**
 * @brief in this function we first check if the row already exsits in the map
 * if not, we create one and fill it with '_'
 * and then write the text in the notebook, and inserting the row to the map
 * if so, we check if we would write over something written, if so throw exception
 * if not, we write the text
 * 
 * @param row 
 * @param col 
 * @param text 
 */
void ariel::Page::write_horizontal(int row, int col, const std::string& text){
    int size = col + (int)(text.size());
    int j = 0;
    const char default_symbol = '_';
    if(pg.find(row) == pg.end()){
        std::vector<char> r(row_length, default_symbol); 

        for(int i = col; i < size; ++i, ++j){
            r[(uint)(i)] = text[(uint)(j)];
        }
        std::pair<int,std::vector<char>> p;
        p.first = row;
        p.second = r;
        pg.insert(p);
    }else{
        for(int i = col; i < size; ++i, ++j){
            if(pg[row][(uint)(i)] != '_'){
                throw std::invalid_argument("cant write over something written");
            }
        }

        j = 0; 
        
        for(int i = col; i < size; ++i, ++j){
                pg[row][(uint)(i)] = text[(uint)(j)];  
        }
    }
}

/**
 * @brief in this function we first check if in the exsisting rows theres something written in the place we want to write
 * if so throw exception
 * then we check if the row dont exist, if not we create a new one
 * then we write the text
 * 
 * @param row 
 * @param col 
 * @param text 
 */
void ariel::Page::write_vertical(int row, int col, const std::string& text){
    int size = row + (int)(text.size());
    int j = 0;
    const char default_symbol = '_';
    for(int i = row; i < size; ++i, ++j){
        if(pg.find(i) != pg.end()){
            if(pg[i][(uint)(col)] != '_'){
                throw std::invalid_argument("cant write over something written2");
            }
        }
    }

    j = 0;

    for(int i = row; i < size; ++i, ++j){
        if(pg.find(i) == pg.end()){
            std::vector<char> r(row_length, default_symbol);
            std::pair<int,std::vector<char>> p;
            p.first = i;
            p.second = r;
            pg.insert(p);
        }
        pg[i][(uint)(col)] = text[(uint)(j)];
    }
}

/**
 * @brief in this function we check the input first, if the row, col, and length are under 0 throw exception
 * if the col number bigger than 100, throw exception
 * if the driection is horizantal we check if the text length or the text length + col is bigger than 100
 * if so throw exception
 * if the direction is horizantal we go to read_horizantal
 * if the direction is verrtical we go to read_vertical
 * 
 * @param row 
 * @param col 
 * @param direction 
 * @param length 
 * @return std::string 
 */
std::string ariel::Page::read(int row, int col, ariel::Direction direction, int length){
    if(row < min_num || col < min_num || length < min_num){
        throw std::invalid_argument("row or col or length number cant be less than 0!");
    }
    if(col >= row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(length > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant read more than 100");
    }

    if(col + length > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant read more than 100 chars");
    }

    if(direction == Direction::Horizontal){
        return read_horizontal(row, col, length);
    }
    return read_vertical(row, col, length); 
}

/**
 * @brief in this function we check if the row exist if so we write it in ans
 * if not we insert ans '_' in the right length (we dont create a row if it not exist)
 * 
 * @param row 
 * @param col 
 * @param length 
 * @return std::string 
 */
std::string ariel::Page::read_horizontal(int row, int col, int length){
    std::string ans;
    if(pg.find(row) != pg.end()){
        for(int i = col; i < col+length; ++i){
            ans += pg[row][(uint)(i)];
        }
    }else{
        for(int i = 0; i < length; ++i){
            ans += '_';
        }
    }
    return ans;
}

/**
 * @brief in this function we check if the rows exist if so we write the char at the right location
 * into ans
 * if not, we insert ans '_'
 * 
 * @param row 
 * @param col 
 * @param length 
 * @return std::string 
 */
std::string ariel::Page::read_vertical(int row, int col, int length){
    std::string ans;
    for(int i = row; i < row+length; ++i){
        if(pg.find(i) != pg.end()){
            ans += pg[i][(uint)(col)];
        }else{
            ans += '_';
        }
    }
    return ans;
}

/**
 * @brief in this function we check the input first, if the row, col, and length are under 0 throw exception
 * if the col number bigger than 100, throw exception
 * if the driection is horizantal we check if the text length or the text length + col is bigger than 100
 * if so throw exception
 * if the direction is horizantal we go to erase_horizantal
 * if the direction is vertical we go to erase_vertical
 * 
 * @param row 
 * @param col 
 * @param direction 
 * @param length 
 */
void ariel::Page::erase(int row, int col, ariel::Direction direction, int length){
    if(row < min_num || col < min_num || length < min_num){
        throw std::invalid_argument("row or col or length number cant be less than 0!");
    }
    
    if(col >= row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(length > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant erase more than 100");
    }

    if(col + length > row_length && direction == ariel::Direction::Horizontal){
        throw std::invalid_argument("cant erase more than 100 chars");
    }

    if(direction == Direction::Horizontal){
        erase_horizontal(row, col, length);
    }else{
        erase_vertical(row, col, length);
    }
}

/**
 * @brief in this function we check if the row exist in the map, if not we create it
 * and then write '~' in the place needed
 * 
 * @param row 
 * @param col 
 * @param length 
 */
void ariel::Page::erase_horizontal(int row, int col, int length){
    if(pg.find(row) == pg.end()){
        std::vector<char> r(row_length, '_');
        std::pair<int,std::vector<char>> p;
        p.first = row;
        p.second = r;
        pg.insert(p);
    }
    for(int i = col; i < col+length; ++i){
        pg[row][(uint)(i)] = '~';
    }
}

/**
 * @brief in this function we check if the rows exist, if not we create new ones and inserting it to map
 * and then write '~' in the right place
 * 
 * @param row 
 * @param col 
 * @param length 
 */
void ariel::Page::erase_vertical(int row, int col, int length){
    for(int i = row; i < row+length; ++i){
        if(pg.find(i) == pg.end()){
            std::vector<char> r(row_length, '_');
            std::pair<int,std::vector<char>> p;
            p.first = i;
            p.second = r;
            pg.insert(p);
        }
        pg[i][(uint)(col)] = '~';
    }
}

/**
 * @brief in this function we show all the page, the format is number of row. text
 * we go throw all rows in map and printing it
 * 
 */
void ariel::Page::show(){
    for(auto itr = pg.begin(); itr != pg.end(); ++itr){
        int row_num = itr->first; 
        std::cout << row_num << ". ";
        for(int i = 0; i < row_length; ++i){
            std::cout << pg[row_num][(uint)(i)];
        }
        std::cout << std::endl;
    }
}