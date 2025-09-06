#include <bits/stdc++.h>
using namespace std;
using U = unsigned;
using ULL = unsigned long long;
using VU = vector<U>;

constexpr const U BASE = 10000;

VU sti(string s) {
	if(s.empty())
		return {0};
	int n = s.size();
	s = string((4 - n % 4) % 4, '0') + s;
	n = s.size();
	VU res;
	for(int i = 0; i < (n + 3) / 4; ++i)
		res.push_back(stoul(s.substr(n - (i + 1) * 4, 4)));
	return res;
}

string its(const VU &num) {
	if(num.empty())
		return "0";
	string res;
	res += to_string(num.back());
	for(int i = num.size() - 2; i >= 0; --i) {
		string t = to_string(num[i]);
		t = string(4 - t.size(), '0') + t;
		res += t;
	}
	return res;
}

int cmp(const VU &a, const VU &b) {
	if(a.size() != b.size())
		return a.size() < b.size()? -1: 1;
	for(int i = a.size() - 1; i >= 0; --i)
		if(a[i] < b[i])
			return -1;
		else if(a[i] > b[i])
			return 1;
	return 0;
}

VU add(const VU &a, const VU &b) {
	int n = max(a.size(), b.size());
	VU res(n + 1, 0);
	ULL cnt = 0;
	for(int i = 0; i < n || cnt; ++i) {
		if(i < n) {
			cnt += (i < a.size()? a[i]: 0);
			cnt += (i < b.size()? b[i]: 0);
		}
		if(i >= res.size())
			res.push_back(cnt % BASE);
		else
			res[i] = cnt % BASE;
		cnt /= BASE;
	}
	for(; res.size() > 1 && res.back() == 0; res.pop_back());
	return res;
}

VU sub(const VU &a, const VU &b) {
	VU res = a;
	bool flg = false;
	for(int i = 0; i < res.size(); ++i) {
		U bi = i < b.size()? b[i]: 0;
		if(res[i] < bi + flg) {
			res[i] = BASE + res[i] - bi - flg;
			flg = true;
		} else {
			res[i] = res[i] - bi - flg;
			flg = false;
		}
	}
	for(; res.size() > 1 && res.back() == 0; res.pop_back());
	return res;
}

VU mul(const VU &a, const VU &b) {
	int lenA = a.size(), lenB = b.size();
	if(lenA == 0 || lenB == 0)
		return {0};
	vector<ULL> tmp(lenA + lenB, 0);
	for(int i = 0; i < lenA; ++i)
		for(int j = 0; j < lenB; ++j)
			tmp[i + j] += (ULL)(a[i]) * (ULL)(b[j]);
	VU res;
	ULL cnt = 0;
	for(int i = 0; i < tmp.size(); ++i) {
		ULL tot = tmp[i] + cnt;
		cnt = tot / BASE;
		res.push_back(tot % BASE);
	}
	for(; res.size() > 1 && res.back() == 0; res.pop_back());
	return res;
}

VU div2(const VU &a) {
	if(a.empty())
		return {0};
	VU res = a;
	ULL cnt = 0;
	for(int i = a.size() - 1; i >= 0; --i) {
		ULL num = cnt * BASE + a[i];
		res[i] = num / 2;
		cnt = num % 2;
	}
	for(; res.size() > 1 && res.back() == 0; res.pop_back());
	return res;
}

VU pow5(const VU &x) {
	VU x2 = mul(x, x),
		x4 = mul(x2, x2),
		x5 = mul(x4, x);
	return x5;
}

int main() {
	freopen("sqrt5.in", "r", stdin);
	freopen("sqrt5.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	if(n == 0) {
		cout.put('0') << endl;
		return 0;
	}
	int d = (n - 1) / 5 + 1;
	VU L = sti("1" + string(d - 1, '0')),
		R = sti("1" + string(d, '0')),
		N = sti(s);
	while(cmp(L, R) <= 0) {
		VU M = div2(add(L, R));
		int res = cmp(pow5(M), N);
		if(res == 0) {
			cout << its(M) << endl;
			return 0;
		} else if(res < 0)
			L = add(M, {1});
		else
			R = sub(M, {1});
	}
	cout << its(L) << endl;
	return 0;
}
