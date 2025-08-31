#include <bits/stdc++.h>
using namespace std;

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

int main()
{
	int date1, date2;
	scanf("%d%d", &date1, &date2);
	int ans = 0;
	for(int y = date1 / 10000; y <= date2 / 10000; ++y)
	{
		int date = rev(y);
		int m = date / 100, d = date % 100;
		if(0 < m && m <= 12 && 0 < d && d <= getday(y, m))
			++ans;
	}
	printf("%d", ans);
	return 0;
}