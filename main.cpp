#include "Direction.hpp"
#include "Page.hpp"

int main(){
    ariel::Page* page = new ariel::Page();
    page->write(0,0,ariel::Direction::Horizontal, "eylon");
    
}