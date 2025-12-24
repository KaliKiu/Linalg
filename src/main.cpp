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
    
    Matrix<double,2,3> mat2;
    Matrix<double,2,3> mat0;
    mat2.fill(mat2x3);
    mat2.print();
    mat0.fill(mat2x3);

    auto c = mat2+mat0;
    c.print();

    
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
