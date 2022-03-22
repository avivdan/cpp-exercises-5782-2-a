#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
#include <vector>
namespace ariel
{   

    const int SIZE = 20;

    Notebook::Notebook(){
        this->pages = SIZE;
        this->rows = SIZE;
        this->cols = SIZE;
    }

    Notebook::~Notebook(){}

    int Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, const std::string &msg) const{
        return returnNull;
    }

    std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len){
        return returnNONE;
    }

    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir,  unsigned int len){}

    void Notebook::show(unsigned int page){}
}