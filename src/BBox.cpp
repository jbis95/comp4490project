#include "BBox.h"
#include <stdio.h>
BBox::BBox() {
	for (int i = 0; i < 8; i++) {
		points[i] = point4(0, 0, 0, 1);
	}
}
BBox::BBox(point4* list) {
	float top = 0, bot = 0, left = 0, right = 0, back = 0, front = 0;
	for (int i = 0; i < list->length(); i++) {
		if (list[i].x > right) {
			right = list[i].x;
		}
		else if (list[i].x < left) {
			left = list[i].x;
		}
		if (list[i].y > top) {
			top = list[i].y;
		}
		else if (list[i].y < bot) {
			bot = list[i].y;
		}
		if (list[i].z > front) {
			front = list[i].z;
		}
		else if (list[i].z < back) {
			back = list[i].z;
		}
	}
	printf("front = %f, back = %f, left = %f, right = %f, top = %f, bot = %f\n", front, back, left, right, top, bot);
	points[0] = point4(right, top, front , 1);
	points[1] = point4(left, top, front, 1);
	points[2] = point4(right, top, back, 1);
	points[3] = point4(left, top, back, 1);
	points[4] = point4(right, bot, front, 1);
	points[5] = point4(left, bot, front, 1);
	points[6] = point4(right, bot, back, 1);
	points[7] = point4(left, bot, back, 1);
}
point4* BBox::getPoints() {
	return points;
}