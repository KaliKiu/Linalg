#ifndef MATRIX
#define MATRIX

#include <stdlib.h>
#include <vector>
template<typename T,std::size_t Rows,std::size_t Cols>
class Matrix{
    public: 
    T data[Rows][Cols];
    std::size_t rows;
    std::size_t cols;

    explicit Matrix(){
        for(std::size_t i = 0; i<Rows; i++){
            for(std::size_t j = 0; j<Cols;j++){
                data[i][j]= T{};
            }
        }
    }
    void fill(const std::vector<std::vector<T>>& arr){
        for(std::size_t i = 0;i<rows; i++){
            for(std::size_t j = 0; j<cols;j++){
                data[i][j] = arr[i][j];
            }
        }
    }
    
};

#endif