#pragma once
#include <conio.h>
#include <time.h>
#include <graphics.h>
#pragma comment ( lib, "Winmm.lib" )
#define WIN_WIDTH 640//图形界面宽度
#define WIN_HEIGHT 480//图形界面高度
int raindropNumber;//雨量
int wind_flag; //左右中 -1,0,1 
int rainTime = 0;//下雨时长
int thunderTime = 3100;//电闪雷鸣时间间隔
HANDLE thundering;//雷电线程句柄
TCHAR s[10];//通用字符用来接收需要进行字符串转换的变量
double waterLevel = 0;//雨量
double lastWaterLevel = 0;//上次池塘水位
int waterHeight = 350;//池塘绘制时的y坐标
//不同类型的雨水的数量
enum raintype_number
{
	little_rain_number = 35,
	middle_rain_number = 50,
	big_rain_number = 70
};
struct rainCircle//涟漪结构体
{
	int x;//涟漪中心点x坐标
	int y;//涟漪中心点y坐标
	int r;//涟漪最大半径
	int curR;//涟漪当前半径
	int rainCircleSpeed;//涟漪扩散速度
};
typedef struct rainnode//雨滴结构体
{
	int left;
	int top;
	int right;
	int bottom;
	double stangle;		//	第一个角度
	double endangle;	//第二个角度
	int endY;//雨滴形成涟漪时的y坐标
	int color;//雨滴颜色
	int step;//雨滴下落速度
	int isRiffle ;//判断雨滴是否生成涟漪
	int rainLength;//雨滴长度
	struct rainCircle riffle;//雨滴相对应的涟漪
} rain;

rain r[big_rain_number];
