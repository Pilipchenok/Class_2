#include "geom.hpp"
#include <stdexcept>
#include <algorithm>
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

topit::f_t topit::frame(const p_t* pts, size_t s)
{
    if(!s)
    {
        throw std::logic_error("no pts");
    }
    int minx = pts[0].x, maxx = minx;
    int miny = pts[0].y, maxy = miny;
    for(size_t i = 1; i < s; ++i)
    {
        minx = std::min(minx, pts[i].x);
        maxx = std::max(maxx, pts[i].x);
        miny = std::min(miny, pts[i].y);
        maxy = std::max(maxy, pts[i].y);
    }
    p_t aa = {minx, miny};
    p_t bb = {maxx, maxy};
    return {aa, bb};
}