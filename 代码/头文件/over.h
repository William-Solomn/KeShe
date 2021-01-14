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
	setcolor(LIGHTRED);
	outtextxy(150, 200, L"一夜过后.....");
	_getch();
	cleardevice();//清屏来显示池塘水位
	//显示最终池塘水位
	IMAGE bg;
	loadimage(&bg, L"梦幻.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"黑体");
	outtextxy(70, 100, L"池塘水位：");
	outtextxy(320, 100, s);
	_getch();
	//显示结尾图片
	IMAGE secondDay;
	loadimage(&secondDay, L"梦幻.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &secondDay);
	settextstyle(50, 0, L"黑体");
	settextcolor(LIGHTRED);
	outtextxy(50, 100, L"谢");
	settextcolor(LIGHTBLUE);
	outtextxy(110, 150, L"谢");
	settextcolor(YELLOW);
	outtextxy(170, 200, L"观");
	settextcolor(LIGHTGREEN);
	outtextxy(230, 250, L"看");
	_getch();
	closegraph();//关闭图形界面
	exit(0);
}