#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <numbers> 
#include <cmath>
#include <glm/gtx/string_cast.hpp>
#include "shape.hpp"
#include "color.hpp"
#include <glm/gtx/intersect.hpp>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
Sphere::Sphere() : point_(), radius_(0.0f), color_{}, name_{} {}
Sphere::Sphere(glm::vec3 const& point, float radius) :point_(point), radius_(radius), color_{}, name_{} {}
Sphere::Sphere(glm::vec3 const& point, float radius, Color const& color, std::string const& name):Shape(color, name), point_(point), radius_(radius), color_(color), name_(name){}
float Sphere::area()const {
	return radius_ * radius_ * 4 * M_PI;
}
float Sphere::volume()const {
	return (4.0f/3.0f) * M_PI * pow(radius_,3);
}
HitPoint Sphere::intersect(Ray const& ray) const{
    HitPoint hit;

    float distance = 0.0f;
    bool hasIntersection = glm::intersectRaySphere(
        ray.origin, ray.direction,
        point_, radius_ * radius_,
        distance);

    if (hasIntersection)
    {
        hit.cut = true;
        hit.distance = distance;
        hit.name = name_;
        hit.color = color_;
        hit.point = ray.getPoint(distance);
        hit.direction = ray.direction;
    }

    return hit;
}
std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "middlepoint" << glm::to_string(point_) << "radius" << radius_;
    return os;
}
