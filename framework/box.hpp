#include <glm/vec3.hpp>
#include "shape.hpp"
#include "color.hpp"
class Box : public Shape {
	public:
		Box();
		Box(glm::vec3 const& min,glm::vec3 const& max);
		Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, std::string const& name);
		~Box()/*override */;
		float area() const override;
		float volume() const override;
		std::ostream& print(std::ostream& os) const override;

	private:
		glm::vec3	min_;
		glm::vec3	max_;
		//Color color_;
		//std::string name_;
};
