#include <bits/stdc++.h>
using namespace std;

constexpr const long double eps = 1e-12;
struct Point {
	long double x, y;
	Point operator+(const Point& other) const
	{ return {x + other.x, y + other.y}; }
	Point operator-(const Point& other) const
	{ return {x - other.x, y - other.y}; }
	Point operator*(long double scalar) const
	{ return {x * scalar, y * scalar}; }
};
long double dot(const Point& a, const Point& b)
{ return a.x * b.x + a.y * b.y; }
long double norm(const Point& p)
{ return sqrt(p.x * p.x + p.y * p.y); }
long double dist(const Point& a, const Point& b)
{ return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	cout << fixed << setprecision(15);
	for(long double TS_x, TS_y, TG_x, TG_y, AS_x, AS_y, AG_x, AG_y; _T--; cout.put('\n')) {
		cin >> TS_x >> TS_y >> TG_x >> TG_y
			>> AS_x >> AS_y >> AG_x >> AG_y;
		Point T_st = {TS_x, TS_y}, T_ed = {TG_x, TG_y},
			A_st = {AS_x, AS_y}, A_ed = {AG_x, AG_y},
			T_dir = T_ed - T_st, A_dir = A_ed - A_st;
		long double T_len = norm(T_dir), A_len = norm(A_dir);
		Point T_unit = {0, 0}, A_unit = {0, 0};
		if(T_len > eps) {
			T_unit.x = T_dir.x / T_len;
			T_unit.y = T_dir.y / T_len;
		}
		if(A_len > eps) {
			A_unit.x = A_dir.x / A_len;
			A_unit.y = A_dir.y / A_len;
		}
		Point diff_st = T_st - A_st, diff_dir = T_unit - A_unit;
		long double a = dot(diff_dir, diff_dir),
			b = 2 * dot(diff_st, diff_dir),
			c = dot(diff_st, diff_st),
			ans = c;
		if(a > eps) {
			long double t_mn_bth = -b / (2 * a);
			t_mn_bth = max((long double)0.0, min({t_mn_bth, T_len, A_len}));
			long double dis_sq = a * t_mn_bth * t_mn_bth + b * t_mn_bth + c;
			if(dis_sq < ans)
				ans = dis_sq;
		}
		long double t_ed_bth = min(T_len, A_len),
			dis_sq_ed_bth = a * t_ed_bth * t_ed_bth + b * t_ed_bth + c;
		if(dis_sq_ed_bth < ans)
			ans = dis_sq_ed_bth;
		if(T_len < A_len) {
			Point fxd_T = T_ed, mv_A_dir = A_unit,
				diff_pos = fxd_T - A_st;
			long double a2 = dot(mv_A_dir, mv_A_dir),
				b2 = -2 * dot(diff_pos, mv_A_dir),
				c2 = dot(diff_pos, diff_pos),
				t_mn_o = -b2 / (2 * a2);
			t_mn_o = max(T_len, min(t_mn_o, A_len));
			long double dis_sq_o = a2 * t_mn_o * t_mn_o + b2 * t_mn_o + c2;
			if(dis_sq_o < ans)
				ans = dis_sq_o;
			long double dis_sq_ed = a2 * A_len * A_len + b2 * A_len + c2;
			if(dis_sq_ed < ans)
				ans = dis_sq_ed;
		} else if(A_len < T_len) {
			Point fxd_A = A_ed, mv_T_dir = T_unit,
				diff_pos = T_st - fxd_A;
			long double a2 = dot(mv_T_dir, mv_T_dir),
				b2 = 2 * dot(diff_pos, mv_T_dir),
				c2 = dot(diff_pos, diff_pos),
				t_mn_o = -b2 / (2 * a2);
			t_mn_o = max(A_len, min(t_mn_o, T_len));
			long double dis_sq_o = a2 * t_mn_o * t_mn_o + b2 * t_mn_o + c2;
			if(dis_sq_o < ans)
				ans = dis_sq_o;
			long double dis_sq_ed = a2 * T_len * T_len + b2 * T_len + c2;
			if(dis_sq_ed < ans)
				ans = dis_sq_ed;
		}
		long double dis_sq_bth_ed = dist(T_ed, A_ed);
		if(dis_sq_bth_ed < ans)
			ans = dis_sq_bth_ed;
		if(ans < 0)
			ans = 0;
		cout << sqrt(ans);
	}
	cout.flush(); return 0;
}
