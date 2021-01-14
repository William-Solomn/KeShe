#pragma once
#include"rain.h"
#include"statement.h"
void updateRainCircle(int i)//������������
{
	r[i].riffle.curR += r[i].riffle.rainCircleSpeed;//�õ�ǰ�뾶���
}
void drawRainCircle(int i)//������������
{
	//������ɫ����Ӧ�����ɫ��ͬ
	setcolor(r[i].color);
	ellipse(r[i].riffle.x - r[i].riffle.curR, r[i].riffle.y - r[i].riffle.curR / 3, 
		r[i].riffle.x + r[i].riffle.curR, r[i].riffle.y + r[i].riffle.curR / 3);
}
void clearRainCircle(int i)//�����������

{
	//ʹ�ó�����ɫ���ǵ��������Դﵽ���Ч��
	setcolor(BLUE);
	ellipse(r[i].riffle.x - r[i].riffle.curR, r[i].riffle.y - r[i].riffle.curR / 3, 
		r[i].riffle.x + r[i].riffle.curR, r[i].riffle.y + r[i].riffle.curR / 3);
}
void riffleInWater(int i)//��������
{
	//��������ǰ�뾶�ﵽ���뾶ʱ��������ʧ���������
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