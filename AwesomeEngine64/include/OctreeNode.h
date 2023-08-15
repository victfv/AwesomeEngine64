#pragma once

#include <glm/vec3.hpp>
#include <AABB.h>

class OctreeNode
{
public:
	OctreeNode(AABB aabb);
	OctreeNode(double max, double min);
	~OctreeNode();
	bool getIsLeaf() {return isLeafNode;}

protected:

private:
	OctreeNode* children[8];
	AABB aabb;
	//BlockData blockData;

	bool isLeafNode;

};

