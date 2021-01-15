#pragma once
#include"statement.h"
#include"guide.h"
void darkClouds()//绘制乌云函数
{
	setfillcolor(DARKGRAY);
	solidrectangle(40, 0, 640, 30);
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	circle(45, 15, 25);
	fillcircle(45, 15, 25);
	setcolor(BLACK);
	setfillcolor(BLACK);
	circle(30, 15, 25);
	fillcircle(30, 15, 25);
	setcolor(RGB(192, 192, 192));
	setfillcolor(RGB(192, 192, 192));
	int l;
	for (l = 10; l <= 600; l = l + 70)
	{
		fillellipse(l + 20, 0, l + 60, 10);//上
		fillellipse(l + 20, 10, l + 60, 20);//下
		fillellipse(l, 5, l + 40, 15);//左
		fillellipse(l + 40, 5, l + 80, 15);//右

		l = l + 80;

		fillellipse(l + 20, 20, l + 60, 30);//上
		fillellipse(l + 20, 30, l + 60, 40);//下
		fillellipse(l, 25, l + 40, 35);//左
		fillellipse(l + 40, 25, l + 80, 35);//右
	}
}
void lotusLeaf()//绘制荷叶函数
{
	int x;
	setfillcolor(RGB(116, 199, 0));
	solidellipse(x = 40, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 140, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 240, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 340, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 440, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 540, waterHeight, x + 60, waterHeight + 30);
}
void pond()//绘制池塘函数
{
	setfillcolor(RGB(25, 48, 66));//25, 48, 66);
	solidrectangle(0, waterHeight, WIN_WIDTH, WIN_HEIGHT);
	lotusLeaf();
}
void start()//场景开头介绍函数
{
	int x;
	int y;
	_stprintf_s(s, _T("%.5f"), waterLevel);
	IMAGE bg;
	loadimage(&bg, L"梦幻.jpg", WIN_WIDTH, WIN_HEIGHT);
	setbkmode(TRANSPARENT);//设置字体背景为透明
	x = 190;
	y = 50;

	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);	//以彩虹的颜色顺序显示主题
	settextstyle(50, 0, L"楷体");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"池");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 10, L"塘");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 10, L"夜");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 10, L"降");
	settextcolor(LIGHTCYAN);
	outtextxy(x + 90, y + 100, L"彩");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 140, y + 100, L"色");
	settextcolor(LIGHTMAGENTA);
	outtextxy(x + 190, y + 100, L"雨");
	//显示项目成员
	setcolor(YELLOW);
	settextstyle(30, 0, L"宋体");
	outtextxy(x - 180, y + 250, L"----");
	outtextxy(x - 100, y + 250, L"仇誓博");
	outtextxy(x + 50, y + 250, L"陈昱健");
	outtextxy(x - 30, y + 310, L"郑世杰");
	outtextxy(x + 120, y + 310, L"温家乐");
	_getch();
	cleardevice();
	//显示初始水位

	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);

	setcolor(YELLOW);
	settextstyle(50, 0, L"黑体");
	outtextxy(70, 100, L"池塘雨量：");
	outtextxy(320, 100, s);
	_getch();
	cleardevice();
}
void initScene(void) //场景初始化函数
{
	initgraph(WIN_WIDTH, WIN_HEIGHT);//初始化图形界面
	start();
	guide();
	pond();
	darkClouds();
}