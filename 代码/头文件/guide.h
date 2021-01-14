#pragma once
#include"statement.h"
void guide()
{
	IMAGE img;
	int x = 100;
	int y = 50;
	loadimage(&img, L"梦幻.jpg", WIN_WIDTH, WIN_HEIGHT);
	setbkmode(TRANSPARENT);//设置字体背景为透明
	putimage(0, 0, &img);
	settextstyle(50, 0, L"楷体");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"↑键增大雨量");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 70, L"↓键减小雨量");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 140, L"←风向向左");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 210, L"→风向向右");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 10, y + 280, L"Esc退出");
	Sleep(2500);
	cleardevice();
}