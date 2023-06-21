#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <numbers> 
#define _USE_MATH_DEFINES
#include <cmath>
Sphere::Sphere() : point_(), radius_(0.0f) {}
Sphere::Sphere(glm::vec3 const& point, float radius):point_(point),radius_(radius){}

float Sphere::area()const {
	return radius_ * radius_ * 4 * M_PI;
}
float Sphere::volume()const {
	return (4.0f/3.0f) * M_PI * pow(radius_,3);
}