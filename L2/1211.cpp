#include <bits/stdc++.h>
using namespace std;

int getday(const int &year, const int &month)
{
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 29;
	else
		return 28;
}

int nextday(const int &x)
{
	int y = x / 10000, m = x / 100 % 100, d = x % 100;
	if(d < getday(y, m))
		++d;
	else if(m < 12)
	{
		++m;
		d = 1;
	}
	else
	{
		++y;
		m = d = 1;
	}
	return y * 10000 + m * 100 + d;
}

int rev(int x)
{
	int ret = 0;
	while(x > 0)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

int main()
{
	int date1, date2;
	scanf("%d%d", &date1, &date2);
	int ans = 0;
	for(int d = date1; d <= date2; d = nextday(d))
		if(d == rev(d))
			++ans;
	printf("%d", ans);
	return 0;
}