#include <cstdio>
#include <string>
using namespace std;

const int day[]{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool is_lunar(const int &y)
{ return (!(y % 4) && y % 100) || !(y % 400); }

inline bool is_pld(const int &x)
{
	string str = to_string(x);
	for(int i = 0, j = str.size() - 1; i < j; ++i, --j)
		if(str[i] != str[j])
			return false;
	return true;
}

inline bool is_year(const int &x)
{
	const int y = x / 10000, m = x / 100 % 100, d = x % 100;
	return 1 <= m && m <= 12 && 1 <= d && d <= (m == 2? 28 + is_lunar(y): day[m]);
}

int main()
{
	int s, e, ans = 0;
	scanf("%d%d", &s, &e);
	for(int d = s; d <= e; ++d)
		if(is_year(d) && is_pld(d))
			++ans;
	printf("%d", ans);
	return 0;
}