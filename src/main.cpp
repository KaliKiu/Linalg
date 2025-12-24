#include <iostream>
#include "math/vector.h"



void printVec(Vector vec){
    for(double x : vec.components){
        std::cout <<x<<"\n";
    }
    std::cout <<"--------------\n";
}
int main(){
    try{
    

    }catch (const std::bad_alloc& e){
        std::cerr <<"Out of memory: "<<e.what()<<"\n";
        return EXIT_FAILURE;
    }catch ( const std::exception& e){
        std::cerr <<"Error "<<e.what() <<"\n";
        return EXIT_FAILURE;
    }

}
