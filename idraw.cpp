#include "idraw.hpp"
namespace
{
    void extend(topit::p_t** pts, size_t s, topit::p_t p)
    {
        topit::p_t* e = new topit::p_t[s + 1];
        for(size_t i = 0; i < s; ++i)
        {
            e[i] = (*pts)[i];
        }
        e[s] = p;
        delete[] *pts;
        *pts = e;
    }
}
size_t topit::points(const IDraw& d, p_t** pts, size_t& s)
{
    size_t r = 1;
    p_t p = d.begin();
    extend(pts, s, p);
    while(d.next(p) != d.begin())
    {
        p = d.next(p);
        extend(pts, s + r, p);
        ++r;
    }
    return r;
}

