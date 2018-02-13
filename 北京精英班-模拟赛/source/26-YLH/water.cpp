#include <cstdio>
#include <algorithm>
using namespace std;

struct hole {
	int h, r;
} map[1005];
int cmp(hole a, hole b) {
	return a.h<b.h;
}int n;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &map[i].h, &map[i].r);
	} sort(map, map+n, cmp);
	int now = 0; long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans+=map[i].r*map[i].r*(map[i].h-now);
		now=map[i].h;
	} printf("%lld", ans);
	return 0;
}

