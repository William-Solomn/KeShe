#pragma once
#include <conio.h>
#include <time.h>
#include <graphics.h>
#pragma comment ( lib, "Winmm.lib" )
#define WIN_WIDTH 640//ͼ�ν�����
#define WIN_HEIGHT 480//ͼ�ν���߶�
int raindropNumber;//����
int wind_flag; //������ -1,0,1 
int rainTime = 0;//����ʱ��
int thunderTime = 3100;//��������ʱ����
HANDLE thundering;//�׵��߳̾��
TCHAR s[10];//ͨ���ַ�����������Ҫ�����ַ���ת���ı���
double waterLevel = 0;//����
double lastWaterLevel = 0;//�ϴγ���ˮλ
int waterHeight = 350;//��������ʱ��y����
//��ͬ���͵���ˮ������
enum raintype_number
{
	little_rain_number = 35,
	middle_rain_number = 50,
	big_rain_number = 70
};
struct rainCircle//�����ṹ��
{
	int x;//�������ĵ�x����
	int y;//�������ĵ�y����
	int r;//�������뾶
	int curR;//������ǰ�뾶
	int rainCircleSpeed;//������ɢ�ٶ�
};
typedef struct rainnode//��νṹ��
{
	int left;
	int top;
	int right;
	int bottom;
	double stangle;		//	��һ���Ƕ�
	double endangle;	//�ڶ����Ƕ�
	int endY;//����γ�����ʱ��y����
	int color;//�����ɫ
	int step;//��������ٶ�
	int isRiffle ;//�ж�����Ƿ���������
	int rainLength;//��γ���
	struct rainCircle riffle;//������Ӧ������
} rain;

rain r[big_rain_number];
