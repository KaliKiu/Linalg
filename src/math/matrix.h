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
        std::size_t rows;
        std::size_t cols;
    public: 
    T data[Rows][Cols];
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
        std::cout <<"--------------\n";
    }
    template<typename U>
    //fu() const -> this to const object, cant modify object
    Matrix<decltype(T{}+U{}), Rows, Cols> operator+(const Matrix<U,Rows,Cols>& matrix)const {
        using R = decltype(T{}+U{});
        if(rows != matrix.getRows() || cols != matrix.getCols()){
            throw MatrixError::DimensionError("Matrix.operator+()");
        }
        Matrix<R,Rows,Cols> results;
        std::vector<std::vector<R>> resultsComponents;
        std::vector<R> defaultRow;

        //fill new Matrix with default Val;
        for(size_t l = 0; l<cols; l++){
            defaultRow.push_back(R{});
        }
        for(size_t k = 0; k<rows; k++){
            resultsComponents.push_back(defaultRow);
        }

        for(size_t i = 0; i<rows; i++){
            for(size_t j = 0; j<cols; j++){
                resultsComponents[i][j]=(data[i][j]+matrix.data[i][j]);
            }
        }

        results.fill(resultsComponents);
        return results;
    }
    template<typename U,size_t otherCols>
    
    Matrix<decltype(T{}+U{}), Rows, otherCols> operator*(const Matrix<U,Cols,otherCols>& matrix)const{
        using R = decltype(T{}+U{});
        Matrix<R,Rows, otherCols> results;
        std::vector<std::vector<R>> resultsComponents;
        std::vector<R> defaultRow;

        for(size_t l = 0; l<matrix.getCols();l++){
            defaultRow.push_back(R{});
        }
        for(size_t k = 0; k<rows; k++){
            resultsComponents.push_back(defaultRow);
        }
        for(size_t i = 0; i<rows;i++){
            for(size_t j = 0; j<matrix.getCols();j++){
                R component{};
                for(size_t l = 0; l<matrix.getRows();l++){
                    component += (data[i][l]*matrix.data[l][j]);
                }
                resultsComponents[i][j]=component;
            }
        }
        results.fill(resultsComponents);
        return results;
    }
    //getters/setters
    std::size_t getRows() const {
        return rows;
    }
    std::size_t getCols() const {
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