#include <map>
#include <string>
#include "Direction.hpp"
#include "Page.hpp"

namespace ariel{
    class Notebook{
        private:
            const static int min_num = 0; // min number of page
            std::map<int,Page> book; // a map of page number and page object

        public:
            void write(int page, int row, int column, ariel::Direction direction, const std::string& text);
            std::string read(int page, int row, int column, ariel::Direction direction, int length);
            void erase(int page, int row, int column, ariel::Direction direction, int length);
            void show(int page);
    };
}