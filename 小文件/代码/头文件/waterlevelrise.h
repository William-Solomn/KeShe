#pragma once
#include"statement.h"
#include"initscene.h"
void waterLevelRise()//ˮλ��������
{
	//��ˮλ����һ����ʱ���Գ������½��л���
	if (waterLevel - lastWaterLevel >= 0.02)
	{
		if(waterHeight>250)
		{
			waterHeight--;//�ó�����y����-1
			pond();
			lastWaterLevel = waterLevel;//�������»��ƺ�ǰˮλ�ͱ�����ϴ�ˮλ
		}
		
	}
}