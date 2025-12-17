#include <iostream>
#include "ascii_draw.hpp"

int main(){
    using topit::IDraw;
    using topit::Dot;
    using topit::p_t;
    using topit::f_t;
    int err = 0;
    IDraw* shps[3] = {};
    p_t* pts = nullptr;
    size_t s = 0;
    try{
        shps[0] = new Dot(0, 0);
        shps[1] = new Dot(5, 7);
        shps[2] = new topit::Rect({2, 2}, {5, 10});

        for (size_t i = 0; i < 3; ++i){
            s += points(*(shps[i]), &pts, s);
        }
        f_t fr = frame(pts, s);
        char* cnv = canvas(fr, '.');
        for(size_t i = 0; i < s; ++i){
            paint(cnv,  fr, pts[i], '#');
        }
        flush(std::cout, cnv, fr);
        delete[] cnv;
    }catch(std::logic_error& e){
        err = 2;
        std::cerr << "Bad drawing " << e.what() << "\n";
    }

    delete[] pts;
    delete shps[0];
    delete shps[1];
    delete shps[2];
    return err;
}
