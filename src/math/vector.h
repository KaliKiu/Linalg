#ifndef VECTOR
#define VECTOR

#include <vector>
#include <stdlib.h>
#include <stdexcept>
struct Vector{
    std::vector<double> components;
    
    Vector(std::vector<double> arr){components = arr;}
    Vector(std::initializer_list<double> list){for(double x : list)components.push_back(x);}

    Vector operator+ (const Vector& vec2) const {
        if(components.size()!= vec2.components.size()){
            throw std::invalid_argument("Vector dimensions do not match");
        }
        std::vector<double> newcomponents;
        newcomponents.reserve(components.size());
        for(int i=0; i<components.size();i++)
        {newcomponents.push_back((components[i]+vec2.components[i]));}

        Vector newvec(newcomponents);
        return newvec;
    }
    Vector operator*(const int& scalar) const {
        std::vector<double> newcomponents;
        for(double x : components){newcomponents.push_back(scalar*x);}
        Vector newvec(newcomponents);
        return newvec;
    }
    Vector operator*(const double& scalar) const {
        std::vector<double> newcomponents;
        for(double x : components){newcomponents.push_back(scalar*x);}
        Vector newvec(newcomponents);
        return newvec;
    }
    
};
    Vector operator*(const int& scalar,Vector vec){
        std::vector<double> newcomponents;
        for(double x: vec.components){newcomponents.push_back(scalar*x);}
        Vector newvec(newcomponents);
         return newvec;
    }
    Vector operator*(const double& scalar, Vector vec){
        std::vector<double> newcomponents;
        for(double x: vec.components){newcomponents.push_back(scalar*x);}
        Vector newvec(newcomponents);
        return newvec;
    }

#endif
