#pragma once
#include"statement.h"
void guide()
{
	IMAGE img;
	int x = 100;
	int y = 50;
	loadimage(&img, L"�λ�.jpg", WIN_WIDTH, WIN_HEIGHT);
	setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
	putimage(0, 0, &img);
	settextstyle(50, 0, L"����");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"������������");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 70, L"������С����");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 140, L"����������");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 210, L"����������");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 10, y + 280, L"Esc�˳�");
	Sleep(2500);
	cleardevice();
}