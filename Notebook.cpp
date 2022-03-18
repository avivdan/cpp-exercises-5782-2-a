#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel
{   

    const int SIZE = 20;

    Notebook::Notebook(){
        this->pages = SIZE;
        this->rows = SIZE;
        this->cols = SIZE;
    }

    Notebook::~Notebook(){}

    int Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, std::string msg){
        return 0;
    }

    std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len){
        return "";
    }

    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir,  unsigned int len){}

    void Notebook::show(unsigned int page){}
}