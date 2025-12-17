#include "dot.hpp"
#include <stdexcept>

topit::Dot::Dot(p_t dd):
    IDraw(),
    d{dd}
{}
topit::Dot::Dot(int x, int y):
    IDraw(),
    d{x, y}
{}

topit::p_t topit::Dot::begin() const{
    return d;
}

topit::p_t topit::Dot::next(p_t prev) const{
    if(prev != begin()){
        throw std::logic_error("bad impl");
    }
    return d;
}