#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 100001

int n; double l = 0; double r = 0; double mid = 0;
double A[maxn]; double B[maxn];

inline int cheak(double val) {
	double a= 0; double b = 0; double m = val;
	int p1 = n-1; int p2 = n-1;
	while (a<m||b<m) {
		if (p1<=0||p2<=0) return 0;
		if (a<m) {
			m+=1;
			a+=A[p1--];
		} if (b<m) {
			m+=1;
			b+=B[p2--];
		}
	} return 1;
}
	

int main() {
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 0; i < n; ++i) {
		cin >> A[i] >> B[i];
		r+=A[i]+B[i];
	} sort(A, A+n);
	sort(B, B+n);
	while (r-l>0.000001) {
		mid=(l+r)/2;
		if (cheak(mid)) l=mid;
		else r=mid;
	} printf("%.4f", (l+r)/2);
	return 0;
}
