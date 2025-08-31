#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/* ºéË®Ìî³äËã·¨ */
const int N = 1003;
vector<int> a;
set<int> st;
bool b[N][N];
char s[N][N];
int f[N][N], n, m, cnt = 0;

void flood(const int &x, const int &y)
{
	if(x < 1 || x > n || y < 1 || y > m || b[x][y] || s[x][y] == '*')
		return;
	b[x][y] = true;
	++a[cnt];
	f[x][y] = cnt;
	flood(x + 1, y);
	flood(x - 1, y);
	flood(x, y + 1);
	flood(x, y - 1);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	a.push_back(0);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '.' && !b[i][j])
			{
				a.push_back(0);
				++cnt;
				flood(i, j);
			}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '.')
				putchar(s[i][j]);
			else
			{
				int d = 1;
				st.insert(f[i + 1][j]);
				st.insert(f[i - 1][j]);
				st.insert(f[i][j + 1]);
				st.insert(f[i][j - 1]);
				for(const auto &y: st)
					d += a[y];
				printf("%d", d % 10);
				st.clear();
			}
		printf("\n");
	}
	return 0;
}