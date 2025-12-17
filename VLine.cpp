#include "VLine.hpp"
#include <stdexcept>

topit::VLine::VLine(p_t s, p_t e):
    IDraw(),
    start(s),
    end(e)
{}

topit::p_t topit::VLine::begin() const{
    return start;
}

topit::p_t topit::VLine::next(p_t prev) const{
    if(prev == end){
        return start;
    }
    if(prev.x == start.x && start.y <= prev.y && prev.y <= end.y){
        return {prev.x, prev.y + 1};
    }
    throw std::logic_error("bad impl");
}