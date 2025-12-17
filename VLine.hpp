#ifndef VLINE_HPP
#define VLINE_HPP
#include "idraw.hpp"

namespace topit {
    struct VLine: IDraw{
        VLine(p_t s, p_t e);
        p_t begin() const override;
        p_t next(p_t) const override;

        p_t start, end;
    };
}

#endif