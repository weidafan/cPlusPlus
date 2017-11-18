/*
 * Flower.h
 *
 *  Created on: Oct 20, 2017
 *      Author: keith
 */

#ifndef FLOWER_H_
#define FLOWER_H_

enum color{GREEN,RED,YELLOW,BLUE};
class Flower
{
private:
	color mycolor;
	int height;
public:
	void grow();
	void bloom(color aColor);
	~Flower();
	Flower();
};


#endif /* FLOWER_H_ */
