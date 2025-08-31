#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

int cnt = 0;

inline void output()
{
	freopen("sort.in", "r", stdin);
	printf("# %d\n", cnt);
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for(int x; n--; )
	{
		scanf("%d", &x);
		printf("%d ", x);
	}
	printf("\n\n");
	fclose(stdin);
}

int main()
{
	// 编译
	system("g++.exe -O2 -std=c++14 -c gen.cpp -o gen.o");
	system("g++.exe -o gen.exe gen.o -static");
	system("g++.exe -O2 -std=c++14 -c baoli.cpp -o baoli.o");
	system("g++.exe -o baoli.exe baoli.o -static");
	system("g++.exe -O2 -std=c++14 -c sort.cpp -o sort.o");
	system("g++.exe -o sort.exe sort.o -static");
   // 删除临时文件
	system("del /f /a /q .\\*.o");
	system("del /f /a /q .\\*.log");
   // 开始对拍
	while(++cnt)
	{
		system("gen.exe");
		system("baoli.exe");
		system("sort.exe");
		if(system("fc sort.out sort.ans"))
		{
			system("cls");
			output(); //输出 hack 数据
			freopen("CON", "r", stdin);
			getch(); //systen("pause") 貌似出了亿些问题
		}
	}
	return 0;
}