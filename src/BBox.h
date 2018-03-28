#pragma once

#include <glm/glm.hpp>

typedef glm::vec4  color4;
typedef glm::vec4  point4;

class BBox {
	point4 points[8];
public:
	BBox();
	BBox(point4*);
	point4* getPoints();
};