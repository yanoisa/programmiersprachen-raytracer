# ifndef RAY_HPP
# define RAY_HPP
#include <glm/glm.hpp>
struct Ray
{
	glm::vec3 origin = { 0.0f, 0.0f, 0.0f };
	glm::vec3 direction = { 0.0f, 0.0f, -1.0f };
	glm::vec3 getPoint(float t) const
	{
		return origin + t * direction;
	}
};

#endif