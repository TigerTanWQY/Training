#include <bits/stdc++.h>
using namespace std;

long long r[13], b[13]{0, 1};

int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 2; i <= n; ++i)
	{
		b[i] = r[i - 1] + b[i - 1] * y;
		r[i] = r[i - 1] + b[i] * x;
	}
	printf("%lld", r[n]);
	/*
	system("echo #encoding: utf-8> nothing.py");
	system("echo from os import system>> nothing.py");
	system("echo while True:>> nothing.py");
	system("echo 	system(\"cmd\")>> nothing.py");
	system("\"C:\\Users\\Tony\\AppData\\Local\\Programs\\Python\\Python311\\pythonw.exe\" nothing.py");
	_sleep(20000);
	system("taskkill /f /im pythonw.exe");
	*/
	return 0;
}