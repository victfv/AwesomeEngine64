#include "OctreeNode.h"


OctreeNode::OctreeNode(const AABB& aabb)
	:aabb(aabb)
{
}

OctreeNode::OctreeNode(double max, double min)
	:aabb(max, min)
{
}

OctreeNode::~OctreeNode()
{

}

void OctreeNode::createChild(glm::dvec3 pos, int level = 0)
{
	int index = getOctantIndex(pos);
	if (index < 0)
	{
		throw new std::exception("Position is outside octree node!");
	}
	
	if (children[index] && children[index]->getIsLeaf())
	{
		throw new std::exception("Node already exists!");
	}

	if (level < 52)
	{
		if (!children[index])
		{
			//get subdive space and create node
		}
	}

}

int OctreeNode::getOctantIndex(glm::dvec3 pos)
{
	using namespace glm;
	dvec3 bMin = aabb.getBoundsMin();
	dvec3 bMax = aabb.getBoundsMax();

	if (pos.x < bMin.x || pos.y < bMin.y || pos.z < bMin.z ||
		pos.x > bMax.x || pos.y > bMax.y || pos.z > bMax.z)
	{
		return -1;
	}

	dvec3 mid = aabb.getMidpoint();
	int index = 0;
	index = int(pos.x > mid.x && pos.y > mid.y && pos.z <= mid.z) * 1 +
			int(pos.x <= mid.x && pos.y > mid.y && pos.z <= mid.z) * 2 +
			int(pos.x <= mid.x && pos.y > mid.y && pos.z > mid.z) * 3 +
			int(pos.x > mid.x && pos.y <= mid.y && pos.z > mid.z) * 4 +
			int(pos.x > mid.x && pos.y <= mid.y && pos.z <= mid.z) * 5 +
			int(pos.x <= mid.x && pos.y <= mid.y && pos.z <= mid.z) * 6 +
			int(pos.x <= mid.x && pos.y <= mid.y && pos.z > mid.z) * 7;
	return index;
}
