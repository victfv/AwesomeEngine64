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
	for (OctreeNode* ch : children)
	{
		ch->~OctreeNode();
	}
}

AABB OctreeNode::subdivSpace(int index)
{
	using namespace glm;
	dvec3 max = aabb.getBoundsMax();
	dvec3 min = aabb.getBoundsMin();
	dvec3 mid = aabb.getMidpoint();
	switch (index)
	{
	case 0:
		return AABB(mid, max);
		break;
	case 1:
		return AABB(dvec3(mid.x, mid.y, min.z),dvec3(max.x, max.y, mid.z));
		break;
	case 2:
		return AABB(dvec3(min.x, mid.y, min.z), dvec3(mid.x, max.y, mid.z));
		break;
	case 3:
		return AABB(dvec3(min.x, mid.z, mid.y), dvec3(mid.x, max.y, max.z));
		break;
	case 4:
		return AABB(dvec3(mid.x, min.y, mid.z), dvec3(max.x, mid.y, max.z));
		break;
	case 5:
		return AABB(dvec3(mid.x, min.y, min.z), dvec3(max.x, mid.y, mid.z));
		break;
	case 6:
		return AABB(min, mid);
		break;
	case 7:
		return AABB(dvec3(min.x, min.y, mid.z), dvec3(mid.x, mid.y, max.z));
		break;
	}
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
			children[index] = new OctreeNode(subdivSpace(index));
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
