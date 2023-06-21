#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <numbers> 
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
Sphere::Sphere() : point_(), radius_(0.0f), color_{}, name_{} {}
Sphere::Sphere(glm::vec3 const& point, float radius) :point_(point), radius_(radius), color_{}, name_{} {}
Sphere::Sphere(glm::vec3 const& point, float radius, Color const& color, std::string const& name) :point_(point), radius_(radius), color_{ color }, name_{name} {}
float Sphere::area()const {
	return radius_ * radius_ * 4 * M_PI;
}
float Sphere::volume()const {
	return (4.0f/3.0f) * M_PI * pow(radius_,3);
}