#include <iostream>
#include <algorithm>
using namespace std;

struct Stu {
	int Chi, Mat, Eng, id, tot;
	bool friend operator<(const Stu& x, const Stu& y) {
		if(x.tot != y.tot)
			return x.tot > y.tot;
		else if(x.Chi != y.Chi)
			return x.Chi > y.Chi;
		else
			return x.id < y.id;
	}
} a[303];

istream& operator>>(istream& fin, Stu& x) {
	fin >> x.Chi >> x.Mat >> x.Eng;
	x.tot = x.Chi + x.Mat + x.Eng;
	return fin;
}

ostream& operator<<(ostream& fout, const Stu& x) {
	fout << x.id << ' ' << x.tot;
	return fout;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= 5; ++i)
		cout << a[i] << '\n';
	cout.flush();
	return 0;
}