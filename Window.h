#pragma once
#ifndef WINDOW_H__
#define WINDOW_H__

class Window
{
public:
	int w;
	int h;
	virtual ~Window();
	virtual void init(int width, int height) = 0;
	virtual void createSurface(int width, int height, SDL_PixelFormat format) = 0;
	// virtual void clear() = 0;
	virtual void update() = 0;
	virtual bool isRunning() = 0;
	virtual void displayFPS() = 0;

};

#endif 
