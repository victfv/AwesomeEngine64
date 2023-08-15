#include "OctreeNode.h"


OctreeNode::OctreeNode(AABB aabb)
{
	this->aabb = aabb;
}

OctreeNode::OctreeNode(double max, double min)
{
	this->aabb = AABB(max, min);
}

OctreeNode::~OctreeNode()
{

}