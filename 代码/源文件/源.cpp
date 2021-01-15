#include"statement.h"
#include"initscene.h"
#include"thunder.h"
#include"rain.h"
#include"riffle.h"
#include"waterLevelrise.h"
#include"over.h"
#include"guide.h"

void raindrop()//池塘夜降彩色雨主体函数
{
	srand((unsigned)time(NULL));//使用系统时间作为随机数发生种子，避免每次运行程序随机值都相同
	int i; raindropNumber = little_rain_number;
	for (i = 0; i < raindropNumber; i++)
	{
		initrain(i);
		r[i].top = rand() % (waterHeight / 2) + 35;
	}
	//将雷电函数单独放到一个线程中执行，避免出现打雷时雨滴停止下落的情况
	thundering = CreateThread(NULL, 0, thunder, NULL, 0, NULL);
	//循环播放背景音乐和雨声
	mciSendString(L"open backGroundMuic.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	mciSendString(L"open 雨声.mp3 alias rain", 0, 0, 0);
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
				waterLevel += 0.00001;//落入池塘一滴雨水位便增加0.00001
			}
			if (r[i].isRiffle == 0)
			{
				moverain(i);
			}
			waterLevelRise();//每落入一滴雨都检测一遍水位变化
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
	initScene();//初始化场景
	//开始展示池塘夜降彩色雨景象
	raindrop();

	return 0;

}