#include "geom.hpp"
bool topit::operator==(p_t a, p_t b){
    return a.x == b.x && a.y == b.y;
}

bool topit::operator!=(p_t a, p_t b){
    return !(a == b);
}

size_t topit::rows(f_t fr)
{
    return fr.bb.y - fr.aa.y + 1;
}

size_t topit::cols(f_t fr){
    return fr.bb.x - fr.aa.x + 1;
}