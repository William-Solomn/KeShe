#pragma once
#include"statement.h"
DWORD WINAPI thunder(LPVOID lpParam)//������������������һ���̣߳�
{
	IMAGE thunder;
	loadimage(&thunder, L"����.jpg", 120, 200);//��thunder������������ͼƬ
	int thunder_X;//����������ֵ�x����
	for (; ; rainTime++)
	{
		//������ʱ���ﵽ�׵�ʱ����ʱ����ֵ�������Ч��
		if (rainTime%thunderTime == 3000)
		{
			//�ȿ�����������������
			putimage(thunder_X = 120 * rand() % WIN_WIDTH, 50, &thunder);//��������������λ�ó���
			//�����������ʾ����ʧ
			Sleep(500);
			mciSendString(L"play ����.mp3", 0, 0, 0);
			setfillcolor(BLACK);
			setlinecolor(BLACK);
			fillrectangle(thunder_X, 50, thunder_X + 120, 250);
			clearrectangle(thunder_X, 50, thunder_X + 120, 250);
		}
		Sleep(3);
	}
	return 0;
}