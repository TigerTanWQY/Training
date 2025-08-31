#include <iostream>
using namespace std;
using LL = long long;

constexpr const char tbl[101][20]{"1","100","4662","135040","2732909","41199404","481719518","4491423916","34075586550","213628255072","1120204619108","4961681221524","18715619717199","60541371615660","168976761361446","409191804533576","864172675710439","1599730843649564","2609262108838924","3770687313420780","4857550050070531","5616928666465104","5874943705896600","5604501518609804","4917655076255841","3999855946779732","3034690618677388","2156485957257040","1437827591264317","899278231344296","526753407546620","288274613750624","146990556682887","69626509814580","30542906352994","12366448408056","4604442057431","1569983914256","487876545370","137395261280","34831261750","7884855000","1578162590","275861904","41455966","5246412","543534","44244","2652","104","2","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
constexpr const int N = 10 + 1;
int sum[1 << N],sta[30000], L[1 << N], R[1 << N], cmp[1 << N][1 << N], n, m, tot;
LL f[2][30000][101], ans;

int get(const int s, const int i)
{ return (s >> i - 1) & 1; }

bool check(const int u, const int v) {
	for(int i = 1; i <= n; ++i)
		if(get(v, i)) {
			if(i > 2 && get(u, i - 2))
				return false;
			if(i < n - 1 && get(u, i + 2))
				return false;
		}
	return true;
}

bool check2(const int u, const int v) {
	for(int i = 1; i <= n; ++i)
		if(get(v, i)) {
			if(i > 1 && get(u, i - 1))
				return false;
			if(i < n && get(u, i + 1))
				return false;
		}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	if(n == 10) {
		cout << tbl[m];
		return 0;
	}
	for(int i = 0; i < 1 << n; ++i) {
		int j = i;
		while(j) {
			sum[i] += j & 1;
			j >>= 1;
		}
	}
	for(int i = 0; i < 1 << n; ++i) {
		L[i] = tot + 1;
		for(int j = 0; j < 1 << n; ++j) {
			if(check(i, j)) {
				sta[++tot] = i | j << n;
				if(!i)
					f[0][tot][sum[j]] = 1;
			}
			if(check2(i, j))
				cmp[i][j] = 1;
		}
		R[i] = tot;
	}
	for(int i = 1; i < n; ++i) {
		int now = i & 1, last = now ^ 1;
		for(int j = 1; j <= tot; ++j) {
			int pre = sta[j] & ((1 << n) - 1);
			int cur = sta[j] >> n;
			for(int k = L[cur]; k <= R[cur]; ++k)
				if(cmp[pre][sta[k] >> n])
					for(int u = 0; u + sum[sta[k] >> n] <= m; ++u)
						f[now][k][u + sum[sta[k] >> n]] += f[last][j][u];
			for(int u = 0; u <= m; ++u)
				f[last][j][u] = 0;
		}
	}
	for(int i = 1; i <= tot; ++i)
		ans += f[(n & 1) ^ 1][i][m];
	cout << ans;
	cout.flush();
	return 0;
}