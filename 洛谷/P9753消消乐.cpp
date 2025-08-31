#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
using ULL = unsigned long long;

const int N = 2000003;
const int P = 191;
struct st
{
	char ch;
	int id;
} stk[N];
unordered_map<ULL, int> t;
char ch[N];
ULL Hash[N];

int main()
{
	int n, top = 0;
	long long ans = 0;
	scanf("%d%s", &n, ch + 1);
	t[0] = 1;
	for(int i = 1; i <= n; ++i)
		if(!top)
		{
			stk[++top] = {ch[i], i};
			Hash[i] = ch[i] - '0';
			ans += t[Hash[i]]++;
		}
		else if(stk[top].ch == ch[i])
		{
			--top;
			Hash[i] = Hash[stk[top].id];
			ans += t[Hash[i]]++;
		}
		else
		{
			Hash[i] = Hash[stk[top].id] * P + (ch[i] - '0');
			stk[++top] = {ch[i], i};
			ans += t[Hash[i]]++;
		}
	printf("%lld", ans);
	return 0;
}