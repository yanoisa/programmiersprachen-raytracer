#include "shape.hpp"
#include "color.hpp"

Shape::Shape(): color_{}, name_{} {}
Shape::Shape(Color color, std::string const& name) : color_{ color }, name_{name} {}
std::ostream& Shape::print(std::ostream& os) const{
	Shape::print(os);
	return os << name_<<color_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	s.print(os);
}
