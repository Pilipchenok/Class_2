#include "rect.hpp"
#include <stdexcept>

topit::Rect::Rect(p_t u_l, p_t r_b):
    IDraw(),
    upper_left(u_l),
    right_bottom(r_b)
{}

topit::p_t topit::Rect::begin() const{
    return upper_left;
}

topit::p_t topit::Rect::next(p_t prev) const{
    if (prev.x == upper_left.x && prev.y == upper_left.y) {
        return {prev.x + 1, prev.y - 1};
    } else if (prev.x == upper_left.x && prev.y > right_bottom.y) {
        return {prev.x, prev.y - 1};
    } else if (prev.x < right_bottom.x && prev.y == right_bottom.y) {
        return {prev.x + 1, prev.y};
    } else if (prev.x == right_bottom.x && prev.y < upper_left.y) {
        return {prev.x, prev.y + 1};
    } else if (prev.x > upper_left.x && prev.y == upper_left.y) {
        return {prev.x - 1, prev.y};
    } else if (prev.x == upper_left.x + 1 && prev.y == upper_left.y) {
        return {prev.x - 2, prev.y};
    }
    throw std::logic_error("bad impl");
}