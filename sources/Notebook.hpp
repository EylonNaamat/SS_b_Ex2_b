#include <map>
#include <string>
#include "Direction.hpp"
#include "Page.hpp"

namespace ariel{
    class Notebook{
        private:
            std::map<int,Page> book;

        public:
            void write(int page, int row, int column, ariel::Direction direction, const std::string& text);
            std::string read(int page, int row, int column, ariel::Direction direction, int length);
            void erase(int page, int row, int column, ariel::Direction direction, int length);
            void show(int page);
    };
}