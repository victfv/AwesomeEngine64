#include "AABB.h"

AABB::AABB(glm::dvec3 max, glm::dvec3 min)
{
	boundsMax = max;
	boundsMin = min;
}

AABB::AABB(double max, double min)
{
	boundsMax = glm::dvec3(max, max, max);
	boundsMin = glm::dvec3(min, min, min);
}

AABB::~AABB()
{
}
