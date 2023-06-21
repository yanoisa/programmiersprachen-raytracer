#include <glm/vec3.hpp>
#include "box.hpp"

Box::Box() :min_{}, max_{} {}
Box::Box(glm::vec3 const& min, glm::vec3 const& max) :min_{ min }, max_{ max } {}

float Box::area()const {
	float x = max_.x - min_.x;
	float y = max_.y - min_.y;
	float z = max_.z - min_.z;
	return 2 * x * z + 2 * x * y + 2 * y * z;
}
float Box::volume()const {
	float x = max_.x - min_.x;
	float y = max_.y - min_.y;
	float z = max_.z - min_.z;
	return x * y * z;
}
