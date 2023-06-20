#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <numbers> 
#define OWN_PI 3.1415926
Sphere::Sphere():point_(),radius_(){}
Sphere::Sphere(glm::vec3 const& point, float radius):point_(point),radius_(radius){}

float Sphere::area()const {
	return radius_ * radius_ * OWN_PI;
}
float Sphere::volume()const {
	return 4 / 3 * OWN_PI * radius_ * radius_ * radius_;
}