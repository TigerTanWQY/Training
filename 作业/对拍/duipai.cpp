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
	// ����
	system("g++.exe -O2 -std=c++14 -c gen.cpp -o gen.o");
	system("g++.exe -o gen.exe gen.o -static");
	system("g++.exe -O2 -std=c++14 -c baoli.cpp -o baoli.o");
	system("g++.exe -o baoli.exe baoli.o -static");
	system("g++.exe -O2 -std=c++14 -c sort.cpp -o sort.o");
	system("g++.exe -o sort.exe sort.o -static");
   // ɾ����ʱ�ļ�
	system("del /f /a /q .\\*.o");
	system("del /f /a /q .\\*.log");
   // ��ʼ����
	while(++cnt)
	{
		system("gen.exe");
		system("baoli.exe");
		system("sort.exe");
		if(system("fc sort.out sort.ans"))
		{
			system("cls");
			output(); //��� hack ����
			freopen("CON", "r", stdin);
			getch(); //systen("pause") ò�Ƴ�����Щ����
		}
	}
	return 0;
}