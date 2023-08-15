#include "OctreeNode.h"


OctreeNode::OctreeNode(AABB aabb)
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