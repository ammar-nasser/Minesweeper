/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void drawMobile(int x, int y, int r, int g, int b);
	void drawBox(int x, int y, int r, int g, int b);
	bool ifColliding(int x, int y, int x1, int y1);
	bool checkScreenBoundary(int& x, int& y);
	/********************************/

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x_mobile{ 400 };
	int y_mobile{ 400 };
	int x_fixed0{ 200 };
	int y_fixed0{ 200 };
	int x_fixed1{ 200 };
	int y_fixed1{ 300 };
	int x_fixed2{ 450 };
	int y_fixed2{ 381 };
	int x_fixed3{ 180 };
	int y_fixed3{ 294 };
	int gb{ 255 };
	int vx{ 0 };
	int vy{ 0 };
	bool colliding{ false };
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;

	/********************************/
};