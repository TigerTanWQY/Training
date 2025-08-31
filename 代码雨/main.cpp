#include <cstdio>
#include <ctime>
#include <windows.h>
#include <graphics.h>
using namespace std;

#define WIDTH 960
#define HEIGHT 720
#define STR_SIZE 20
#define STR_NUM 128
#define STR_WIDTH 15

struct Rain
{
	int x, y, speed;
	TCHAR str[STR_SIZE];
} rain[STR_NUM];

char CreateCh()
{
	char ch = 0;
	int flag = rand() % 3;
	if(flag == 0)
		ch = rand() % 26 + 'a';
	else if(flag == 1)
		ch = rand() % 26 + 'A';
	else
		ch = rand() % 10 + '0';
	return ch;
}

void InitRain()
{
	for(int i = 0; i < STR_NUM; ++i)
	{
		rain[i].x = i * STR_WIDTH;
		rain[i].y = rand() % HEIGHT;
		rain[i].speed = rand() % 5 + 5;
	}
	for(int i = 0; i < STR_NUM; i++)
		for (int j = 0; j < STR_SIZE; j++)
			rain[i].str[j] = CreateCh();
}

void DrawRain()
{
	cleardevice();
	for(int i = 0; i < STR_NUM; i++)
		for(int j = 0; j < STR_SIZE; j++)
		{
			outtextxy(rain[i].x, rain[i].y - STR_WIDTH * j, rain[i].str[j]);
			settextcolor(RGB(0, 255 - j * 13, 0));
		}
}

void MoveRain()
{
	for(int i = 0; i < STR_NUM; i++)
	{
		rain[i].y += rain[i].speed;
		if(rain[i].y - STR_WIDTH * STR_SIZE > HEIGHT)
			rain[i].y = 0;
	}
}

void ChangeCh()
{
	for(int i = 0; i < STR_NUM; i++)
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = CreateCh();
}
int main()
{
	srand((unsigned int)time(NULL));
	initgraph(WIDTH, HEIGHT);
	InitRain();
	DWORD t1 = GetTickCount(), t2 = t1;
	while(true)
	{
		BeginBatchDraw();
		DrawRain();
		ChangeCh();
		if(t2 - t1 > STR_SIZE)
		{
			MoveRain();
			t1 = t2;
		}
		t2 = GetTickCount();
		EndBatchDraw();
	}
	getchar();
	closegraph();
	return 0;
}