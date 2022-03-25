#include "Direction.hpp"
#include "Page.hpp"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>


void ariel::Page::write(int row, int col, ariel::Direction direction, const std::string& text){
    if(col > row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(int(text.size()) > row_length){
        throw std::invalid_argument("cant write more than 100");
    }

    if(col + (int)(text.size()) > row_length){
        throw std::invalid_argument("cant write more than 100 chars");
    }

    for(int i = 0; i < (int)(text.size()); ++i){
        if(text[i] == '~'){
            throw std::invalid_argument("cant write ~");
        }
    }

    if(direction == Direction::Horizontal){
        write_horizontal(row, col, text);
    }else{
        write_vertical(row, col, text);
    }
}

void ariel::Page::write_horizontal(int row, int col, const std::string& text){
    int size = col + (int)(text.size());
    int j = 0;
    const char default_symbol = '_';
    if(pg.find(row) == pg.end()){
        std::vector<char> r(row_length, default_symbol); 

        for(int i = col; i < size; ++i, ++j){
            r[i] = text[j];
        }
        std::pair<int,std::vector<char>> p;
        p.first = row;
        p.second = r;
        pg.insert(p);
    }else{
        for(int i = col; i < size; ++i, ++j){
            if(text[j] != '_'){
                throw std::invalid_argument("cant write over something written");
            }
        }

        for(int i = col; i < size; ++i, ++j){
                pg[row][i] = text[j];   
        }
    }
}

void ariel::Page::write_vertical(int row, int col, const std::string& text){
    int size = row + (int)(text.size());
    int j = 0;
    const char default_symbol = '_';
    for(int i = row; i < size; ++i, ++j){
        if(pg.find(i) != pg.end()){
            if(pg[i][col] != '_'){
                throw std::invalid_argument("cant write over something written2");
            }
        }
    }
    for(int i = row; i < size; ++i, ++j){
        if(pg.find(i) == pg.end()){
            std::vector<char> r(row_length, default_symbol);
            std::pair<int,std::vector<char>> p;
            p.first = i;
            p.second = r;
            pg.insert(p);
        }
        pg[i][col] = text[j];
        
    }
}

std::string ariel::Page::read(int row, int col, ariel::Direction direction, int length){
    if(col > row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(length > row_length){
        throw std::invalid_argument("cant read more than 100");
    }

    if(col + length > row_length){
        throw std::invalid_argument("cant read more than 100 chars");
    }

    if(direction == Direction::Horizontal){
        return read_horizontal(row, col, length);
    }
    return read_vertical(row, col, length); 
}

std::string ariel::Page::read_horizontal(int row, int col, int length){
    std::string ans;
    if(pg.find(row) != pg.end()){
        for(int i = col; i < col+length; ++i){
            ans += pg[row][i];
        }
    }else{
        for(int i = 0; i < length; ++i){
            ans += '_';
        }
    }
    return ans;
}

std::string ariel::Page::read_vertical(int row, int col, int length){
    std::string ans;
    for(int i = row; i < length; ++i){
        if(pg.find(i) != pg.end()){
            ans += pg[i][col];
        }else{
            ans += '_';
        }
    }
    return ans;
}

void ariel::Page::erase(int row, int col, ariel::Direction direction, int length){
    if(col > row_length){
        throw std::invalid_argument("col number should be less than 100");
    }

    if(length > row_length){
        throw std::invalid_argument("cant erase more than 100");
    }

    if(col + length > row_length){
        throw std::invalid_argument("cant erase more than 100 chars");
    }

    if(direction == Direction::Horizontal){
        erase_horizontal(row, col, length);
    }else{
        erase_vertical(row, col, length);
    }
}

void ariel::Page::erase_horizontal(int row, int col, int length){
    if(pg.find(row) == pg.end()){
        std::vector<char> r(row_length, '_');
        std::pair<int,std::vector<char>> p;
        p.first = row;
        p.second = r;
        pg.insert(p);
    }
    for(int i = col; i < length; ++i){
        pg[row][i] = '~';
    }
}

void ariel::Page::erase_vertical(int row, int col, int length){
    for(int i = row; i < length; ++i){
        if(pg.find(i) == pg.end()){
            std::vector<char> r(row_length, '_');
            std::pair<int,std::vector<char>> p;
            p.first = i;
            p.second = r;
            pg.insert(p);
        }
        pg[i][col] = '~';
    }
}

void ariel::Page::show(){
    for(auto itr = pg.begin(); itr != pg.end(); ++itr){
        int row_num = itr->first; 
        std::cout << row_num << ". ";
        for(int i = 0; i < row_length; ++i){
            std::cout << pg[row_num][i];
        }
        std::cout << std::endl;
    }
}