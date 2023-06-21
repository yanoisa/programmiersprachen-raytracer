#include <glm/vec3.hpp>
#include "shape.hpp"
#include "color.hpp"
class Sphere : public Shape {
	public:
		Sphere();
		Sphere(glm::vec3 const& point, float radius);
		Sphere(glm::vec3 const& point, float radius, Color const& color, std::string const& name);
		float area() const override;
		float volume() const override;
	private:
		glm::vec3	point_;
		float	radius_;
		Color color_;
		std::string name_;
};
