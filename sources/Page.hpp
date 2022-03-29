#include "Direction.hpp"
#include <map>
#include <vector>
#include <string>

namespace ariel{
    class Page{
        private:
        const static int row_length = 100; // number of max line length
        const static int min_num = 0;   // number of min row, col, length
        const static int char_min = 32; // number of min char possible
        const static int char_max = 125; // number of max char possible
        std::map<int, std::vector<char>> pg; // a map of number of row and vector of line


        public:
        Page(){}
        void write(int row, int col, ariel::Direction direction, const std::string& text);
        std::string read(int row, int col, ariel::Direction direction, int length);
        void erase(int row, int col, ariel::Direction direction, int length);
        void show();
        void write_horizontal(int row, int col, const std::string& text);
        void write_vertical(int row, int col, const std::string& text);
        std::string read_horizontal(int row, int col, int length);
        std::string read_vertical(int row, int col, int length);
        void erase_horizontal(int row, int col, int length);
        void erase_vertical(int row, int col, int length);
        
    };
}