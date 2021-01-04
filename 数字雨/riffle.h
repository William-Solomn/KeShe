#pragma once
#include"rain.h"
#include"statement.h"
void updateRainCircle(int i)//更新涟漪函数
{
	r[i].riffle.curR += r[i].riffle.rainCircleSpeed;//让当前半径变大
}
void drawRainCircle(int i)//绘制涟漪函数
{
	//涟漪颜色与相应雨滴颜色相同
	setcolor(r[i].color);
	ellipse(r[i].riffle.x - r[i].riffle.curR, r[i].riffle.y - r[i].riffle.curR / 3, 
		r[i].riffle.x + r[i].riffle.curR, r[i].riffle.y + r[i].riffle.curR / 3);
}
void clearRainCircle(int i)//清除涟漪函数

{
	//使用池塘颜色覆盖掉涟漪，以达到清除效果
	setcolor(BLUE);
	ellipse(r[i].riffle.x - r[i].riffle.curR, r[i].riffle.y - r[i].riffle.curR / 3, 
		r[i].riffle.x + r[i].riffle.curR, r[i].riffle.y + r[i].riffle.curR / 3);
}
void riffleInWater(int i)//涟漪函数
{
	//当涟漪当前半径达到最大半径时，涟漪消失并重生雨滴
	if (r[i].riffle.curR >= r[i].riffle.r)
	{
		clearRainCircle(i);
		initrain(i);
	}
	else
	{
		clearRainCircle(i);
		updateRainCircle(i);
		drawRainCircle(i);
	}
}