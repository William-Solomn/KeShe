#pragma once
#include"statement.h"
#include"guide.h"
void darkClouds()//�������ƺ���
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
		fillellipse(l + 20, 0, l + 60, 10);//��
		fillellipse(l + 20, 10, l + 60, 20);//��
		fillellipse(l, 5, l + 40, 15);//��
		fillellipse(l + 40, 5, l + 80, 15);//��

		l = l + 80;

		fillellipse(l + 20, 20, l + 60, 30);//��
		fillellipse(l + 20, 30, l + 60, 40);//��
		fillellipse(l, 25, l + 40, 35);//��
		fillellipse(l + 40, 25, l + 80, 35);//��
	}
}
void lotusLeaf()//���ƺ�Ҷ����
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
void pond()//���Ƴ�������
{
	setfillcolor(RGB(25, 48, 66));//25, 48, 66);
	solidrectangle(0, waterHeight, WIN_WIDTH, WIN_HEIGHT);
	lotusLeaf();
}
void start()//������ͷ���ܺ���
{
	int x;
	int y;
	_stprintf_s(s, _T("%.5f"), waterLevel);
	IMAGE bg;
	loadimage(&bg, L"�λ�.jpg", WIN_WIDTH, WIN_HEIGHT);
	setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
	x = 190;
	y = 50;

	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);	//�Բʺ����ɫ˳����ʾ����
	settextstyle(50, 0, L"����");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"��");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 10, L"��");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 10, L"ҹ");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 10, L"��");
	settextcolor(LIGHTCYAN);
	outtextxy(x + 90, y + 100, L"��");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 140, y + 100, L"ɫ");
	settextcolor(LIGHTMAGENTA);
	outtextxy(x + 190, y + 100, L"��");
	//��ʾ��Ŀ��Ա
	setcolor(YELLOW);
	settextstyle(30, 0, L"����");
	outtextxy(x - 180, y + 250, L"----");
	outtextxy(x - 100, y + 250, L"���Ĳ�");
	outtextxy(x + 50, y + 250, L"���Ž�");
	outtextxy(x - 30, y + 310, L"֣����");
	outtextxy(x + 120, y + 310, L"�¼���");
	_getch();
	cleardevice();
	//��ʾ��ʼˮλ

	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);

	setcolor(YELLOW);
	settextstyle(50, 0, L"����");
	outtextxy(70, 100, L"����������");
	outtextxy(320, 100, s);
	_getch();
	cleardevice();
}
void initScene(void) //������ʼ������
{
	initgraph(WIN_WIDTH, WIN_HEIGHT);//��ʼ��ͼ�ν���
	start();
	guide();
	pond();
	darkClouds();
}