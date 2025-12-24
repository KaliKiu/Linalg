#ifndef MATRIX
#define MATRIX

#include <stdlib.h>
#include <vector>
#include <iostream>

namespace MatrixError{
    class InvalidMatrix : public std::exception {
        protected:
        std::string message;
        public: 
        explicit InvalidMatrix(std::string msg) : message(std::move(msg)){};
        const char* what() const noexcept override{
            return message.c_str();
        }
    };
}
template<typename T,std::size_t Rows,std::size_t Cols>
class Matrix{
    public: 
    T data[Rows][Cols];
    std::size_t rows;
    std::size_t cols;

    explicit Matrix(): rows{Rows}, cols{Cols}{
        if(rows == 0){
            throw MatrixError::InvalidMatrix("Invalid Matrix: ROWS == 0\n");
        }else if(cols ==0){
            throw MatrixError::InvalidMatrix("Invalid Matrix: COLS == 0\n");
        }
        for(std::size_t i = 0; i<Rows; i++){
            for(std::size_t j = 0; j<Cols; j++){
                data[i][j]= T{};
            }
        }
    }
    void fill(const std::vector<std::vector<T>>& arr){
        for(std::size_t i = 0;i<rows; i++){
            for(std::size_t j = 0; j<cols; j++){
                data[i][j] = arr[i][j];
            }
        }
    }
    void addVector(const Vector vector){
        for(std::size_t i = 0; i<cols; i++){
            data[rows+1][i] = vector.components[i];
        }
        rows += 1;
    }
    void print(){
        for(std::size_t i = 0; i<rows; i++){
            for(std::size_t j=0; j<cols; j++){
                std::cout <<data[i][j] << " ";
            }
        std::cout <<"\n";
        }
    }
    
};


#endif