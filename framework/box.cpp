#include <glm/vec3.hpp>
#include "box.hpp"
#include <cmath>
#include <glm/gtx/string_cast.hpp>
#include "shape.hpp"
#include "color.hpp"
Box::Box() :min_{}, max_{}, name_{}, color_{} {}
Box::Box(glm::vec3 const& min, glm::vec3 const& max) :min_{ min }, max_{ max }, name_{}, color_{} {}
Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, std::string const& name)
	: Shape(color, name), min_(min), max_(max), color_(color), name_(name){}
Box::~Box() {}
float Box::area()const {
	float x = std::abs(max_.x - min_.x);
	float y = std::abs(max_.y - min_.y);
	float z = std::abs(max_.z - min_.z);
	return 2 * x * z + 2 * x * y + 2 * y * z;
}
float Box::volume()const {
	float x = max_.x - min_.x;
	float y = max_.y - min_.y;
	float z = max_.z - min_.z;
	return std::abs(x * y * z);
}
std::ostream& Box::print(std::ostream& os) const {
	Shape::print(os);
	os <<" min " << glm::to_string(min_) << " max " << glm::to_string(max_);
	return os;
}
