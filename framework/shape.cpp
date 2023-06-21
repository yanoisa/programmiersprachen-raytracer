#include "shape.hpp"
#include "color.hpp"
Shape::Shape(): color_{}, name_{} {}
Shape::Shape(Color color, std::string const& name) : color_{ color }, name_{name} {}
