#pragma once
#include"statement.h"
void over()//场景结束函数

{
	cleardevice();
	mciSendString(L"close bgm", 0, 0, 0);//关闭背景音乐
	mciSendString(L"close rain", 0, 0, 0);//关闭雨声
	TerminateThread(thundering, 0);//结束雷电线程
	CloseHandle(thundering);//释放掉雷电线程所占堆栈
	_stprintf_s(s, _T("%.5f"), waterLevel);//将浮点型水位转化为字符串类型，以用来显示在图形界面上
	settextstyle(50, 0, L"黑体");
	//输出文字表示下雨结束
	setcolor(YELLOW);
	outtextxy(150, 200, L"雨停之后.....");
	_getch();
	cleardevice();//清屏来显示池塘水位
	//显示最终池塘水位
	IMAGE bg;
	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);
	setcolor(YELLOW);
	settextstyle(50, 0, L"黑体");
	outtextxy(70, 200, L"降雨量：");
	outtextxy(320, 200, s);
	_getch();
	//显示结尾图片
	IMAGE secondDay;
	loadimage(&secondDay, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &secondDay);
	settextstyle(50, 0, L"黑体");
	settextcolor(LIGHTRED);
	outtextxy(50, 50, L"谢谢观看~~~~~~");

	_getch();
	closegraph();//关闭图形界面
	exit(0);
}