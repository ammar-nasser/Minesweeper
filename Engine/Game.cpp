/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//control the speed
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight)
		{
			    vx++;
				inhibitRight = true;
				
		}
	}
	else
	{
		inhibitRight = false;
	}
		
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft)
		{
			vx--;
			inhibitLeft = true;
		
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			vy--;
			inhibitUp = true;
			
		}
	}
	else
	{
		inhibitUp = false;
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			vy++;
			inhibitDown = true;
		
		}
	}
	else
	{
		inhibitDown = false;
	}

	x_mobile += vx;
	y_mobile += vy;

	//end of control speed



	//check screen boundray
	if (checkScreenBoundary(x_mobile, y_mobile))
	{
		vx = 0;
		vy = 0;
	}
	//end of secure

	//check the target
	colliding = ifColliding(x_mobile , y_mobile,x_fixed0, y_fixed0)
		     || ifColliding(x_mobile, y_mobile, x_fixed1, y_fixed1)
		     || ifColliding(x_mobile, y_mobile, x_fixed2, y_fixed2)
		     || ifColliding(x_mobile, y_mobile, x_fixed3, y_fixed3);
	//end check the target





	//stop if space is pressed
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vy = 0;
		vx = 0;
	}


	//gb = (wnd.kbd.KeyIsPressed(VK_CONTROL)) ? 0 : 255;
	//changeShape = (wnd.kbd.KeyIsPressed(VK_SHIFT)) ? true : false;
}



void Game::ComposeFrame()
{
	drawBox(x_fixed0, y_fixed0, 0, 255, 0);
	drawBox(x_fixed1, y_fixed1, 0, 255, 0);
	drawBox(x_fixed2, y_fixed2, 0, 255, 0);
	drawBox(x_fixed3, y_fixed3, 0, 255, 0);


	if (colliding)
	{
		drawMobile(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		drawMobile(x_mobile, y_mobile, 255, 255, 255);
	}
}

void Game::drawMobile(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 0, y + 2, r, g, b);
	gfx.PutPixel(x + 0, y + 3, r, g, b);
	gfx.PutPixel(x + 0, y + 4, r, g, b);
	gfx.PutPixel(x + 0, y + 5, r, g, b);
	gfx.PutPixel(x + 0, y - 2, r, g, b);
	gfx.PutPixel(x + 0, y - 3, r, g, b);
	gfx.PutPixel(x + 0, y - 4, r, g, b);
	gfx.PutPixel(x + 0, y - 5, r, g, b);
	gfx.PutPixel(x + 2, y + 0, r, g, b);
	gfx.PutPixel(x + 3, y + 0, r, g, b);
	gfx.PutPixel(x + 4, y + 0, r, g, b);
	gfx.PutPixel(x + 5, y + 0, r, g, b);
	gfx.PutPixel(x - 2, y + 0, r, g, b);
	gfx.PutPixel(x - 3, y + 0, r, g, b);
	gfx.PutPixel(x - 4, y + 0, r, g, b);
	gfx.PutPixel(x - 5, y + 0, r, g, b);
}


void Game::drawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
	gfx.PutPixel(x + 2, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y + 2, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x - 2, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 3, r, g, b);
	gfx.PutPixel(x - 5, y + 2, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x + 2, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);
	gfx.PutPixel(x + 5, y - 2, r, g, b);
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x - 2, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);
	gfx.PutPixel(x - 5, y - 2, r, g, b);
}

bool Game::ifColliding(int x_move, int y_move, int x_targ, int y_targ)
{
	const int left_move   =   x_move - 5;
	const int right_move  =   x_move + 5;
	const int top_move    =   y_move - 5;
	const int bottom_move =   y_move + 5;

	const int left_targ   = x_targ - 5;
	const int right_targ  = x_targ + 5;
	const int top_targ    = y_targ - 5;
	const int bottom_targ = y_targ + 5;

	return (left_move <= right_targ&&
		right_move >= left_targ &&
		top_move <= bottom_targ&&
		bottom_move >=  top_targ) ;

}

bool Game::checkScreenBoundary(int& x, int& y)
{
	if ( y + 6 > gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
		return true;
	}
	if ( y < 6)
	{
		y = 6;
		return true;
	}
	if ( x + 6 > gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 6;
		return true;
	}
	if (x < 6)
	{
		x = 6;
		return true;
	}
	return false;
}
