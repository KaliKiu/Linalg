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
    Vector vec1{1.0,2.0,3.0};
    Vector vec2{2.0,1.0,0.5};
    int scalar= 3;
    Vector results = vec1+vec2;
    printVec(results);
    results = scalar*results;
    printVec(results);
    results = results*scalar;
    printVec(results);
    
    }catch (const std::bad_alloc& e){
        std::cerr <<"Out of memory: "<<e.what()<<"\n";
        return EXIT_FAILURE;
    }catch ( const std::exception& e){
        std::cerr <<"Error "<<e.what() <<"\n";
        return EXIT_FAILURE;
    }

}
