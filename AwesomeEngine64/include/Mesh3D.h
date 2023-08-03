#pragma once
#include <glm/vec3.hpp>
#include <vector>

class Mesh3D
{
public:
	static Mesh3D* loadMesh;
private:
	std::vector <glm::vec3> vertices;
	std::vector <glm::vec3> normals;
	std::vector <glm::vec3> UVs;
};

