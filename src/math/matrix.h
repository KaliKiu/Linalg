#ifndef MATRIX
#define MATRIX

#include <vector.h>
#include <stdlib.h>
template<typename T,std::size_t Rows,std::size_t Cols>
class Matrix{
    public: 
    T data[Rows][Cols];
    std::size_t rows;
    std::size_t cols;

    explicit Matrix(){
        for(std::size_t i = 0; i<Rows; i++){
            for(std::size_t j = 0; j<Cols){
                data[i][j]= T{};
            }
            validate()
        }
    }
    void fill(T arr[rows][cols]){
        for(std::size_t i = 0;i<rows; i++){
            for(std::size_t j = 0; j<cols){
                data[i][j] = arr[i][j];
            }
        }
    }
    private:
    bool validate()
};

#endif