#pragma once

#include <glm/vec3.hpp>

class AABB
{
public:
	AABB(glm::dvec3 max, glm::dvec3 min);
	AABB(double max, double min);
	~AABB();

private:
	glm::dvec3 boundsMax;
	glm::dvec3 boundsMin;
};

