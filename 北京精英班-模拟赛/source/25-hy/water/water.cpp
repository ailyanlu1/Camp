#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct C { int h, r; } c[1010];
inline bool operator<(const C& a, const C& b) { return a.r < b.r; }

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i].h >> c[i].r;
	sort(c, c + n);
	long long x = c[0].r * c[0].r * c[0].h;
	for (int i = 1; i < n; ++i) {
		x += (c[i].r * c[i].r - c[i - 1].r * c[i - 1].r) * c[i].h;
	}
	cout << x << endl;
	return 0;
}
