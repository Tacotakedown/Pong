#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <array>
#include <cmath>



	class boundingBox
	{
	private:
		std::array<int, 2> mCenter;
		std::array<int, 2> mExtent;

	public:
		boundingBox();

		bool collision(const boundingBox& other) const;

		const std::array<int, 2>& getCenter() const {
			return mCenter; 
		}
		const std::array<int, 2>& getExtent() const { 
			return mExtent; }


		int getCenterX() const {
			return mCenter[0]; 
		}
		int getCenterY() const {
			return mCenter[1]; 
		}
		int getExtentX() const {
			return mExtent[0]; 
		}
		int getExtentY() const { 
			return mExtent[1]; 
		}

		void setCenterX(int x) {
			mCenter[0] = x; 
		}
		void setCenterY(int y) {
			mCenter[1] = y;
		}
		void setExtentX(int x) {
			mExtent[0] = x;
		}
		void setExtentY(int y) {
			mExtent[1] = y;
		}
	};







#endif // !PONG_BOUNDINGBOX_H



