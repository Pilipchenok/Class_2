#ifndef DOT_HPP
#define DOT_HPP
#include "idraw.hpp"

namespace topit
{
    struct Dot: IDraw{
        Dot(int x, int y);
        explicit Dot(p_t dd);
        p_t begin() const override;
        p_t next(p_t) const override;
        p_t d;
    };
}
#endif