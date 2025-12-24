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
    Vector vec({1,2,3});
    printVec(vec);

    std::vector<std::vector<double>> vecc = {{1,3,3},{2,4,5}};
    Matrix<double,1,3> mat;
    mat.fill(vecc);
    

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
