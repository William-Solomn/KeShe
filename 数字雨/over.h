#pragma once
#include"statement.h"
void over()//������������

{
	cleardevice();
	mciSendString(L"close bgm", 0, 0, 0);//�رձ�������
	mciSendString(L"close rain", 0, 0, 0);//�ر�����
	TerminateThread(thundering, 0);//�����׵��߳�
	CloseHandle(thundering);//�ͷŵ��׵��߳���ռ��ջ
	_stprintf_s(s, _T("%.5f"), waterLevel);//��������ˮλת��Ϊ�ַ������ͣ���������ʾ��ͼ�ν�����
	settextstyle(50, 0, L"����");
	//������ֱ�ʾ�������
	setcolor(LIGHTRED);
	outtextxy(150, 200, L"һҹ����.....");
	_getch();
	cleardevice();//��������ʾ����ˮλ
	//��ʾ���ճ���ˮλ
	IMAGE bg;
	loadimage(&bg, L"�λ�.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"����");
	outtextxy(70, 100, L"����ˮλ��");
	outtextxy(320, 100, s);
	_getch();
	//��ʾ��βͼƬ
	IMAGE secondDay;
	loadimage(&secondDay, L"�λ�.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &secondDay);
	settextstyle(50, 0, L"����");
	settextcolor(LIGHTRED);
	outtextxy(50, 100, L"л");
	settextcolor(LIGHTBLUE);
	outtextxy(110, 150, L"л");
	settextcolor(YELLOW);
	outtextxy(170, 200, L"��");
	settextcolor(LIGHTGREEN);
	outtextxy(230, 250, L"��");
	_getch();
	closegraph();//�ر�ͼ�ν���
	exit(0);
}