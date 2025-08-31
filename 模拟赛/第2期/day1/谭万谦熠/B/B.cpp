#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> cnt;
int a[5003];

inline bool check(const int &x, const int &y)
{
	if(a[x] != a[y])
		if((a[x] ^ a[y]) == a[x] || (a[x] ^ a[y]) == a[y])
			return cnt[a[x] ^ a[y]] >= 2;
		else
			return true;
	else
		if(a[x] == (a[x] ^ a[y]))
			return cnt[a[x]] >= 3;
		else
			return true;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(cnt.find(a[i] ^ a[j]) != cnt.cend() && check(i, j) && j < upper_bound(a + j + 1, a + n + 1, a[i] ^ a[j]) - a - 1)
				++ans;
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//using namespace std;
////±©Á¦ 60 ·Ö
//int a[5003];
//
//int main()
//{
//	int n, ans = 0;
//	scanf("%d", &n);
//	for(int i = 1; i <= n; ++i)
//		scanf("%d", &a[i]);
//	for(int i = 1; i < n - 1; ++i)
//		for(int j = i + 1; j < n; ++j)
//			for(int k = j + 1; k <= n; ++k)
//				if((a[i] ^ a[j] ^ a[k]) == 0)
//					++ans;
//	printf("%d", ans);
//	return 0;
//}