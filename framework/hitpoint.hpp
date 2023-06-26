# ifndef HITPOINT_HPP
# define HITPOINT_HPP
#include <glm/glm.hpp>
struct HitPoint
{
	bool cut = false;
	float distance;
	std::string name;
	Color color;
	glm::vec3 point;
	glm::vec3 direction;
};

#endif