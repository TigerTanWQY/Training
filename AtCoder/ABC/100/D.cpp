#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 1'003;
struct Cake {
	LL x, y, z;
	Cake friend operator+(const Cake& A, const Cake& B) noexcept {
		Cake res;
		res.x = A.x + B.x;
		res.y = A.y + B.y;
		res.z = A.z + B.z;
		return res;
	}
	Cake& operator+=(const Cake& A) noexcept {
		*this = *this + A;
		return *this;
	}
	bool friend operator<(const Cake& A, const Cake& B) noexcept
	{ return abs(A.x) + abs(A.y) + abs(A.z) < abs(B.x) + abs(B.y) + abs(B.z); }
	void reset(void) noexcept
	{ x = y = z = 0; }
} a[N], f[N];

Cake abs(Cake A) {
	A.x = abs(A.x);
	A.y = abs(A.y);
	A.z = abs(A.z);
	return A;
}

ostream& operator<<(ostream& fout, const Cake& A) noexcept
{ return fout << abs(A.x) + abs(A.y) + abs(A.z); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].z;
	memset(f, -0x3f, sizeof(f));
	f[0].reset();
	const int V = N - 3;
	for(int i = 1; i <= n; ++i)
		for(int j = V; j; --j)
			if(f[j] < abs(f[j - 1] + a[i]))
				f[j] = f[j - 1] + a[i];
	cout << f[V] << endl;
	return 0;
}