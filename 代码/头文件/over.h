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
	setcolor(YELLOW);
	outtextxy(150, 200, L"��֮ͣ��.....");
	_getch();
	cleardevice();//��������ʾ����ˮλ
	//��ʾ���ճ���ˮλ
	IMAGE bg;
	loadimage(&bg, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bg);
	setcolor(YELLOW);
	settextstyle(50, 0, L"����");
	outtextxy(70, 200, L"��������");
	outtextxy(320, 200, s);
	_getch();
	//��ʾ��βͼƬ
	IMAGE secondDay;
	loadimage(&secondDay, L"image.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &secondDay);
	settextstyle(50, 0, L"����");
	settextcolor(LIGHTRED);
	outtextxy(50, 50, L"лл�ۿ�~~~~~~");

	_getch();
	closegraph();//�ر�ͼ�ν���
	exit(0);
}