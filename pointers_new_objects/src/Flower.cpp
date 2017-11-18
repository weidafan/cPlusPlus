/*
 * Flower.cpp
 *
 *  Created on: Oct 20, 2017
 *      Author: keith
 */

#include "Flower.h"

void Flower::bloom(color aColor) {
	//color ac = color(rand() % 4);
	mycolor = aColor;
}
void Flower::grow() {
	height++;
}
Flower::Flower():height(0), mycolor(GREEN)
{
}


Flower::~Flower()
{
}
