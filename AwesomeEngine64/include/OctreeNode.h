#pragma once

#include <glm/vec3.hpp>
#include <AABB.h>
#include <exception>

#define OCTREE_LEAF_LEVEL 52

class OctreeNode
{
public:
	OctreeNode(const AABB &aabb);
	OctreeNode(double max, double min);
	~OctreeNode();
	bool getIsLeaf() {return isLeafNode;}


protected:
	void createChild(glm::dvec3 pos, int level = 0);

private:
	/*
	* +x +y +z
	* -x +y +z
	* -x -y +z
	* -x -y -z
	* +x -y -z
	* +x +y -z
	* -x +y -z
	* +x -y +z
	*/
	AABB subdivSpace(int index);
	OctreeNode* children[8];
	AABB aabb;
	int getOctantIndex(glm::dvec3 pos);
	//BlockData blockData;

	bool isLeafNode;

};

