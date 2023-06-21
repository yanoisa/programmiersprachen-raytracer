#include <glm/vec3.hpp>
#include "shape.hpp"
class Sphere : public Shape {
	public:
		Sphere();
		Sphere(glm::vec3 const& point, float radius);
		float area() const override;
		float volume() const override;
	private:
		glm::vec3	point_;
		float	radius_;
};
