#include<iostream>
#include<Windows.h>
#include<algorithm>
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include <graphics.h>//包含图形库头文件
#include <mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")

using namespace std;

IMAGE img1,img[27];
int ArrMap[13][13] = {
	1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
	1 , 5 , 0 , 11, 17, 17, 0 , 0 , 0 , 0 , 0 , 0 , 1 ,
	1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 ,
	1 , 8 , 0 , 0 , 3 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 1 ,
	1 , 11, 21, 0 , 1 , 0 , 1 , 1 , 7 , 1 , 1 , 0 , 1 ,
	1 , 1 , 3 , 1 , 1 , 0 , 3 , 16, 24, 10, 1 , 0 , 1 ,
	1 , 11, 0 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 1 ,
	1 , 0 , 21, 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 1 ,
	1 , 1 , 3 , 1 , 1 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 1 ,
	1 , 0 , 0 , 0 , 1 , 1 , 3 , 1 , 1 , 1 , 1 , 3 , 1 ,
	1 , 8 , 13, 11, 1 , 11, 0 , 11, 1 , 0 , 16, 0 , 1 ,
	1 , 8 , 0 , 11, 1 , 0 , 0 , 0 , 1 , 18, 9 , 18, 1 ,
	1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
};
void ezx();
void load();
void put();


void diamon(int half, int n = 1)
{//递归菱形，n是当前行数，half是半径 共2*half-1
	if (n == half)
	{
		for (int i = 0; i < 2 * n - 1; i++)
			cout << '*';
		cout << endl;//中间一行没有空格
		return;
	}
	for (int i = 0; i < half - n; i++)
		cout << ' ';
	for (int i = 0; i < 2 * n - 1; i++)
		cout << '*';
	cout << endl;//上半 half-1

	diamon(half,n+1); //调用

	for (int i = 0; i < half - n; i++)
		cout << ' ';
	for (int i = 0; i < 2 * n - 1; i++)
		cout << '*';
	cout << endl;//下半
}
int main()
{	
	//diamon(5);
	//ezx();
	load();
	put();


	system("pause");
	return 0;
}

/*
	round 四舍五入
	ceil 向上 floor 向下
	atoi 碰到第一个不为数字的字符中止
	_itoa_s(31,a,10,16);
	//数字，目标，位数，进制
	printf是输出
	sprintf_s是输入
	memcpy,memset
	ZeroMemory(a,sizeof(a));就是
	memset(a,0,sizeof(a))

	char a[6] = "hello";
	char b[6] = "world";
	char c[11]{};
	strcpy_s(c,6,a);
	c[5] = ' ';
	strcpy_s(c+6,6,b);//不能小于b
	cout << c;

	strcmp 左>右

	sizeof 带空格，strlen不带

	1.数学 2.转化（读表 3.
*/

void ezx()
{
	
	//初始化图形,宽高
	loadimage(&img1,"picture/头像01.jpg");
	initgraph(1024, 886);
	putimage(499,0,&img1);
	
	//mciSendString("open ./picture/乐逍遥.mp3 alias bgm",0,0,0);
	//地址，别名
	//mciSendString("play bgm repeat",0,0,0);
	//播放,循环
	//Sleep(5000);
	//mciSendString("close bgm",0,0,0);
	//停止

}

void load()
{
	for (int i = 0; i < 27; i++)
	{
		char a[64]="";
		sprintf_s(a,"picture/%d.png",i);//默认cpp，工作目录bin
		loadimage(img+i, a,32,32);
	}
	initgraph(13*32, 13*32);

}

void put()
{
	int x, y;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			x = j * 32;
			y = i * 32;
			putimage(x, y, &img[ArrMap[i][j]]);
		}
	}
}
