#include <iostream>
#include "math/vector.h"
#include "math/matrix.h"


void printVec(Vector vec){
    for(double x : vec.components){
        std::cout <<x<<"\n";
    }
    std::cout <<"--------------\n";
}
int main(){
    try{
    

    std::vector<std::vector<double>> mat2x3 = {{1,3,3},{2,4,5}};
    std::vector<std::vector<double>> mat3x2 = {{2,3},{1,2},{4,5}};

    Matrix<double,2,3> mat0;
    Matrix<double,3,2>mat1;

    mat0.fill(mat2x3);
    mat0.print();
    mat1.fill(mat3x2);
    mat1.print();

    auto d = mat0*mat1;
    d.print();

    
    }catch (const std::bad_alloc& e){
        std::cerr <<"Out of memory: "<<e.what()<<"\n";
        return EXIT_FAILURE;
    }catch(const MatrixError::InvalidMatrix& e){
        std::cerr<<"MatrixError: "<<e.what()<<"\n";;
    }catch ( const std::exception& e){
        std::cerr <<"Error "<<e.what() <<"\n";
        return EXIT_FAILURE;
    }

}
