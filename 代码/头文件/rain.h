#pragma once
#include"statement.h"
#include"over.h"

void initrain(int i)
{
	r[i].left = rand() % WIN_WIDTH;
	r[i].top = 35;
	r[i].right = r[i].left + 27;
	r[i].bottom = r[i].top + 27;
	r[i].stangle = 4.6;
	r[i].endangle = 4.9;
	r[i].endY = waterHeight + 70 + rand() % (WIN_HEIGHT - waterHeight - 70);//雨滴的结束y坐标要在池塘之内
	r[i].step = (rand() % 4) + 3;	// 雨滴下落的速度
	r[i].color = RGB(rand() % 255, rand() % 255, rand() % 255);	//雨滴的颜色
	r[i].isRiffle = 0;//标志初始为0，代表还是雨滴
	r[i].riffle.x = r[i].left;
	r[i].riffle.y = r[i].endY;
	r[i].riffle.r = rand() % 30 + 10;
	r[i].riffle.curR = rand() % 2;
	r[i].riffle.rainCircleSpeed = raindropNumber / 20;//使涟漪扩散速度与雨量相协调
}
/*
	擦掉上一个雨水
*/
void clear_rain(int i)
{
		setfillcolor(BLACK);
		setlinecolor(BLACK);
	if(r[i].top>waterHeight)
	{
		setfillcolor(RGB(25, 48, 66));
		setlinecolor(RGB(25, 48, 66));
	}
	fillpie(r[i].left, r[i].top, r[i].right, r[i].bottom, r[i].stangle, r[i].endangle);
}
void moverain(int i)
{
	clear_rain(i);
	switch (wind_flag)
	{
	case 0: {
		r[i].top += r[i].step;			//雨滴下一次的位置等于上一次位置加速度
		r[i].bottom = r[i].top + 27;
		r[i].stangle = 4.6;
		r[i].endangle = 4.9;
		if (r[i].bottom > waterHeight)
		{
			r[i].top += 42;
			r[i].bottom = r[i].top + 27;
		}
		if (r[i].bottom < r[i].endY)
		{
			setfillcolor(r[i].color);
			setlinecolor(r[i].color);
			fillpie(r[i].left, r[i].top, r[i].right, r[i].bottom, r[i].stangle, r[i].endangle);
		}
		break;
	}
	case -1: {
		r[i].top += r[i].step;			//雨滴下一次的位置等于上一次位置加速度
		r[i].bottom = r[i].top + 27;
		r[i].left -= r[i].step;
		r[i].right = r[i].left + 27;
		r[i].riffle.x = r[i].left;
		r[i].stangle = 3.8;
		r[i].endangle = 4.1;
		if (r[i].bottom > waterHeight)
		{
			r[i].top += 42;
			r[i].bottom = r[i].top + 27;
		}
		if (r[i].left <= 0)
		{
			r[i].left = WIN_WIDTH - 30;
			r[i].right = r[i].left + 27;
		}
		if (r[i].bottom < r[i].endY)
		{
			setfillcolor(r[i].color);
			fillpie(r[i].left, r[i].top, r[i].right, r[i].bottom, r[i].stangle, r[i].endangle);
		}
		break;
	}
	case 1: {
		r[i].top += r[i].step;			//雨滴下一次的位置等于上一次位置加速度
		r[i].bottom = r[i].top + 27;
		r[i].left += r[i].step;
		r[i].right = r[i].left + 27;
		r[i].riffle.x = r[i].left;
		r[i].stangle = 5.4;
		r[i].endangle = 5.7;
		if (r[i].bottom > waterHeight)
		{
			r[i].top += 42;
			r[i].bottom = r[i].top + 27;
		}
		if (r[i].left >= WIN_WIDTH)
		{
			r[i].left = 0;
			r[i].right = r[i].left + 30;
		}
		if (r[i].bottom < r[i].endY)
		{
			setfillcolor(r[i].color);
			fillpie(r[i].left, r[i].top, r[i].right, r[i].bottom, r[i].stangle, r[i].endangle);
		}
		break;
	}
	}
	if (r[i].bottom >= r[i].endY)
		r[i].isRiffle = 1;
}
/*
	获取键盘输入字符来控制雨量
	方向↑(72)，雨水增加，key++
	方向↓(80)，雨水减少，key--
	一共有大、中、小三种，key = 2、1、0

	获取键盘输入字符来控制雨的方向
	方向←(75)，雨水向左飘，keydirection++
	方向→(77)，雨水向右飘，keydirection--
	左45，右45，直，key = 4,5,6
*/
int get_control_rain()
{
	int key = 0;
	static int keynumber = 0;
	static int keydirection = 5;
	char ch;
	ch = _getch();
	switch (ch)
	{
	case 80: {
		if (keynumber < 2) {
			keynumber++;
		}
		return keynumber;
	}
	case 72: {
		if (keynumber > 0) {
			keynumber--;
		}
	}
			 return keynumber;
	case 75: {
		if (keydirection > 4) {
			keydirection--;
		}
	}
			 return keydirection;
	case 77: {
		if (keydirection < 6) {
			keydirection++;
		}
		return keydirection;
	}
	case 27: {
		over();
	}
	}
}
/*
	从键盘收到消息后，需要作出改变，此函数功能既如此
	1.雨量
	2.风向
*/
void change_rain_flag(int &raindropNumber)
{
	int i, k, rain_number_temp;
	k = get_control_rain();
	rain_number_temp = raindropNumber;
	if (k == 0) {
		raindropNumber = little_rain_number;
	}
	else if (k == 1) {
		raindropNumber = middle_rain_number;
	}
	else if (k == 2)
	{
		raindropNumber = big_rain_number;
	}
	if (raindropNumber > rain_number_temp)	//从小到大，增加初始化
	{
		for (i = rain_number_temp; i < raindropNumber; i++)
		{
			initrain(i);
			r[i].top = rand() % (waterHeight);
		}
	}
	else if (raindropNumber < rain_number_temp) {	//从大到小,擦掉一部分的雨
		for (i = rain_number_temp - 1; i >= raindropNumber; i--)
		{
			clear_rain(i);
		}
	}
	//风向
	if (k == 4) {
		wind_flag = -1;
	}
	else if (k == 5) {
		wind_flag = 0;
	}
	else if (k == 6)
	{
		wind_flag = 1;
	}
}
