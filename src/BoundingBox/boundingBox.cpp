#include "boundingBox.h"

boundingBox::boundingBox() : mCenter({ 0,0 }), mExtent({ 0,0 })
{

}
bool boundingBox::collision(const boundingBox& other) const
{
	auto x = std::abs(mCenter[0] - other.mCenter[0]) < (mExtent[0] + other.mExtent[0]);
	auto y = std::abs(mCenter[1] - other.mCenter[1]) < (mExtent[1] + other.mExtent[1]);
	return x && y;
}