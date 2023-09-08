#include "CenterDivider.h"

CenterLine::CenterLine(int x, int y, int h, int w) : mRect({ x,y,w,h })
{

}

void CenterLine::onDraw(SDL_Renderer& renderer)
{
	for (float y = static_cast<float>(mRect.y); y < mRect.h; y += (1.93f * mRect.w))
	{
		SDL_Rect rect{ mRect.x, static_cast<int>(y),mRect.w,mRect.w };
		SDL_RenderFillRect(&renderer, &rect);
	}
}