#include<bits/stdc++.h>
using namespace std;
double a[100010],b[100010];
int main() {
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%lf%lf",a+i,b+i);
	}
	sort(a,a+n,greater<double>());
	sort(b,b+n,greater<double>());
	int ai=1,bi=1;
	double ma=a[0]-2;
	double mb=b[0]-2;
	if(a[0]<2||b[0]<2) {
		printf("0.0000");
		return 0;
	}
	while(1) {
		if(a[ai]>=2&&b[bi]>=2) {
			ma=ma+a[ai++]-2;
			mb=mb+b[bi++]-2;
		} else if(ma>mb) {
			if(ma-1>mb)mb=mb-1+b[bi++],ma--;
			else break;
		} else if(ma<mb) {
			if(mb-1>ma)ma=ma-1+a[ai++],mb--;
			else break;
		} else break;
	}
	printf("%.4f",min(ma,mb));
	return 0;
}
