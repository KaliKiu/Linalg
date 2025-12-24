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
        virtual ~InvalidMatrix() noexcept = default;
        const char* what() const noexcept override{
            return message.c_str();
        }
    };
    class DimensionError : public InvalidMatrix {
    
        public:
        explicit DimensionError(std::string msg) : InvalidMatrix("Dimension Error: "+msg){}
        ~DimensionError() noexcept override = default;
    };
}
template<typename T,std::size_t Rows,std::size_t Cols>
class Matrix{
    private:
        T data[Rows][Cols];
        std::size_t rows;
        std::size_t cols;
    public: 

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
        if(arr.size() != rows || arr[0].size() != cols){
            throw MatrixError::DimensionError("Matrix.fill()");
        }
        for(std::size_t i = 0;i<rows; i++){
            for(std::size_t j = 0; j<cols; j++){
                data[i][j] = arr[i][j];
            }
        }
    }
    void print(){
        for(std::size_t i = 0; i<rows; i++){
            for(std::size_t j=0; j<cols; j++){
                std::cout <<data[i][j] << " ";
            }
        std::cout <<"\n";
        }
    }
    Matrix operator+(const Matrix matrix)const {
        if(rows != matrix.getCols() || cols != matrix.getRows){
            throw MatrixError::DimensionError("Matrix.operator+()");
        }
        //continue stuff
    }
    std::size_t getRows(){
        return rows;
    }
    std::size_t getCols(){
        return cols;
    }

    void setRows(std::size_t r){
        if(r>0) rows = r;
        
    }
    void setCols(std::size_t s){
        if(s>0) cols = s;
    }
    
};


#endif