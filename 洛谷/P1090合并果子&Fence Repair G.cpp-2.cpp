#include <cstdio>
#include <queue>
using namespace std;
/** STL 堆（优先队列） **/
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	while(q.size() > 1)
	{
		int f1 = q.top();
		q.pop();
		int f2 = q.top();
		q.pop();
		ans += f1 + f2;
		q.push(f1 + f2);
	}
	printf("%d", ans);
	return 0;
}