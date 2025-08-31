#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> a;

inline bool check(string s, string t)
{
	int l1 = s.size(), l2 = t.size();
	if(s == t)
		return true;
	else if(l1 - l2 == 1)
	{
		for(int i = 0, j = 0; i < l1 && j < l2; ++i, ++j)
			if(s[i] != t[j])
				if(s[i - 1] == t[j - 1] && s[i + 1] == t[j])
					++i;
				else
					return false;
		return true;
	}
	else if(l2 - l1 == 1)
	{
		for(int i = 0, j = 0; i < l1 && j < l2; ++i, ++j)
			if(s[i] != t[j])
				if(s[i - 1] == t[j - 1] && s[i] == t[j + 1])
					++j;
				else
					return false;
		return true;
	}
	else if(l1 == l2)
	{
		bool flag = true;
		for(int i = 0; i < l1; ++i)
			if(s[i] != t[i])
				if(flag)
					flag = false;
				else
					return false;
		return true;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string t;
	cin >> n >> t;
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		if(check(s, t))
			a.push_back(i);
	}
	cout << a.size() << "\n";
	for(const auto &p: a)
		cout << p << " ";
	return 0;
}