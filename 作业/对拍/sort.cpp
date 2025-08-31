#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[1000003], n;

namespace Bubble // 冒泡排序
{
	void Main()
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n - i; ++j)
				if(a[j] < a[j + 1])
					swap(a[j], a[j + 1]);
	}
}

namespace Merge // 归并排序
{
	void Main()
	{ stable_sort(a + 1, a + n + 1, greater<int>()); }
}

//namespace Quick // 快速排序
//{
//	void Main()
//	{ sort(a + 1, a + n + 1, greater<int>()); }
//}

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if(n <= 1e4) // 分点作答
		Bubble::Main();
	else
		Merge::Main();
//	else
//		Quick::Main();
	for(int i = 1; i <= m; ++i)
		printf("%d ", a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}