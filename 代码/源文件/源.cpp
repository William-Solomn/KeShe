#include"statement.h"
#include"initscene.h"
#include"thunder.h"
#include"rain.h"
#include"riffle.h"
#include"waterLevelrise.h"
#include"over.h"
#include"guide.h"

void raindrop()//����ҹ����ɫ�����庯��
{
	srand((unsigned)time(NULL));//ʹ��ϵͳʱ����Ϊ������������ӣ�����ÿ�����г������ֵ����ͬ
	int i; raindropNumber = little_rain_number;
	for (i = 0; i < raindropNumber; i++)
	{
		initrain(i);
		r[i].top = rand() % (waterHeight / 2) + 35;
	}
	//���׵纯�������ŵ�һ���߳���ִ�У�������ִ���ʱ���ֹͣ��������
	thundering = CreateThread(NULL, 0, thunder, NULL, 0, NULL);
	//ѭ�����ű������ֺ�����
	mciSendString(L"open backGroundMuic.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	mciSendString(L"open ����.mp3 alias rain", 0, 0, 0);
	mciSendString(L"play rain repeat", 0, 0, 0);
	while (true)
	{
		if (_kbhit())
		{
			change_rain_flag(raindropNumber);
		}
		for (i = 0; i < raindropNumber; i++)
		{
			if (r[i].isRiffle == 1)
			{
				riffleInWater(i);
				waterLevel += 0.00001;//�������һ����ˮλ������0.00001
			}
			if (r[i].isRiffle == 0)
			{
				moverain(i);
			}
			waterLevelRise();//ÿ����һ���궼���һ��ˮλ�仯
		}
		if (raindropNumber == little_rain_number)
		{
			Sleep(10);
		}
		if (raindropNumber == middle_rain_number)
		{
			Sleep(5);
		}
		else if (raindropNumber == big_rain_number)
		{
			Sleep(3);
		}
	}
}
int main()
{
	initScene();//��ʼ������
	//��ʼչʾ����ҹ����ɫ�꾰��
	raindrop();

	return 0;

}