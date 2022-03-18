#include "Direction.hpp"
#include <string>
#include <vector>
namespace ariel{

    class Notebook{
        
        unsigned int pages, rows, cols;
        std::vector<std::vector<std::vector<char>>> notebook;
// Notebook
        public:
            // Constructors
            Notebook();
            Notebook(unsigned int pages, unsigned int rows, unsigned int cols);
            Notebook(unsigned int size);

            // Destructor
            ~Notebook();

            // This method will get page, row, column, direction and a message as parameters and write the message in the 
            // appropriate location and direction in this notebook
            int write(unsigned int page, unsigned int row, unsigned int col, Direction dir, std::string msg);

            // This method get row, column, direction and length of a message as parameters and returns the message in the 
            // appropriate location and direction in this notebook
            std::string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);

            //erase function- it will just write over the char '~'
            void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir,  unsigned int len);

            // This message will print out the entire message board
            void show(unsigned int page);

            // Returns number of rows and columns of this board
            unsigned int get_rows() const;
            unsigned int get_cols() const;
            unsigned int get_pages() const;            
    };
}   