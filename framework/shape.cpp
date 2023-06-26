#include "shape.hpp"
#include "color.hpp"

Shape::Shape(): color_{}, name_{} {
   // std::cout << "ShapeKon" << "\n";
}
Shape::Shape(Color  color, std::string const& name) : color_{color}, name_{name} {
   // std::cout << "ShapeKon" << "\n";
}
Shape::~Shape(){
   // std::cout << "ShapeDes" << "\n";
}
std::ostream& Shape::print(std::ostream& os) const {
    os <<" name " <<name_ <<" color " <<color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}
