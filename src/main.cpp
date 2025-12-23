#include <iostream>
#include "math/vector.h"


int main(){
    try{
    Vector vec1{1.0,2.0,3.0};
    Vector vec2{2.0,1.0,0.5};
    int scalar= 3;
    Vector results = vec1+vec2;
    results = scalar*results;
    for(double x : results.components){
        std::cout <<x<<"\n";
    }
    }catch (const std::bad_alloc& e){
        std::cerr <<"Out of memory: "<<e.what()<<"\n";
        return EXIT_FAILURE;
    }catch ( const std::exception& e){
        std::cerr <<"Error "<<e.what() <<"\n";
        return EXIT_FAILURE;
    }

}