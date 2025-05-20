#include "Block.h"
#include "Constants.h"

Block::Block(int shape, int angle, int x, int y)
{
	this->shape = shape;
	this->angle = angle;
	this->x = x;
	this->y = y;
}

int Block::getColor() const
{
	return GRAY;
}

int Block::getShape() const
{
	return shape;
}

int Block::getAngle() const
{
	return angle;
}

int Block::getX() const
{
	return x;
}

int Block::getY() const
{
	return y;
}

void Block::setAngle(int angle)
{
	this->angle = angle;
}

void Block::setX(int x)
{
	this->x = x;
}

void Block::setY(int y)
{
	this->y = y;
}

void Block::set(int shape, int angle, int x, int y)
{
	this->shape = shape;
	this->angle = angle;
	this->x = x;
	this->y = y;
}
