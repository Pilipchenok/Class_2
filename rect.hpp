#ifndef RECT_HPP
#define RECT_HPP
#include "idraw.hpp"

namespace topit{
    struct Rect: IDraw{
        Rect(p_t u_l, p_t r_b);
        p_t begin() const override;
        p_t next(p_t) const override;

        p_t upper_left;
        p_t right_bottom;
    };
}

#endif