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
	r[i].endY = waterHeight + 70 + rand() % (WIN_HEIGHT - waterHeight - 70);//��εĽ���y����Ҫ�ڳ���֮��
	r[i].step = (rand() % 4) + 3;	// ���������ٶ�
	r[i].color = RGB(rand() % 255, rand() % 255, rand() % 255);	//��ε���ɫ
	r[i].isRiffle = 0;//��־��ʼΪ0�����������
	r[i].riffle.x = r[i].left;
	r[i].riffle.y = r[i].endY;
	r[i].riffle.r = rand() % 30 + 10;
	r[i].riffle.curR = rand() % 2;
	r[i].riffle.rainCircleSpeed = raindropNumber / 20;//ʹ������ɢ�ٶ���������Э��
}
/*
	������һ����ˮ
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
		r[i].top += r[i].step;			//�����һ�ε�λ�õ�����һ��λ�ü��ٶ�
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
		r[i].top += r[i].step;			//�����һ�ε�λ�õ�����һ��λ�ü��ٶ�
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
		r[i].top += r[i].step;			//�����һ�ε�λ�õ�����һ��λ�ü��ٶ�
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
	��ȡ���������ַ�����������
	�����(72)����ˮ���ӣ�key++
	�����(80)����ˮ���٣�key--
	һ���д��С�С���֣�key = 2��1��0

	��ȡ���������ַ���������ķ���
	�����(75)����ˮ����Ʈ��keydirection++
	�����(77)����ˮ����Ʈ��keydirection--
	��45����45��ֱ��key = 4,5,6
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
	�Ӽ����յ���Ϣ����Ҫ�����ı䣬�˺������ܼ����
	1.����
	2.����
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
	if (raindropNumber > rain_number_temp)	//��С�������ӳ�ʼ��
	{
		for (i = rain_number_temp; i < raindropNumber; i++)
		{
			initrain(i);
			r[i].top = rand() % (waterHeight);
		}
	}
	else if (raindropNumber < rain_number_temp) {	//�Ӵ�С,����һ���ֵ���
		for (i = rain_number_temp - 1; i >= raindropNumber; i--)
		{
			clear_rain(i);
		}
	}
	//����
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
