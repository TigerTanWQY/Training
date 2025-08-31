#include <bits/stdc++.h>
using namespace std;

const int N = 11;
const int M = 100003;

void dfs(const int &cur, vector<string> &s, vector<string> &t, const int &remain, const string &ans)
{
	if(remain < 0)
		return;
	if(cur == s.size())
	{
		if(ans.size() >= 3 && !binary_search(t.cbegin(), t.cend(), ans))
		{
			cout << ans;
			exit(0);
		}
		return;
	}
	if(ans.size() && ans.back() != '_')
		dfs(cur, s, t, remain, ans + '_');
	else
	{
		dfs(cur + 1, s, t, remain, ans + s[cur]);
		if(ans.size())
			dfs(cur, s, t, remain - 1, ans + "_");
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, remain = 16;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s.begin(), s.end());
	for(int i = 0; i < m; ++i)
		cin >> t[i];
	sort(t.begin(), t.end());
	for(int i = 0; i < n; ++i)
		remain -= s[i].size();
	remain -= n - 1;
	do{
		dfs(0, s, t, remain, "");
	} while(next_permutation(s.begin(), s.end()));
	cout << "-1";
	return 0;
}