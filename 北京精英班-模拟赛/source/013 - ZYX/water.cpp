#include <bits/stdc++.h>
#define maxn 101000
using namespace std;
struct Cup{int h,r;}a[maxn];
bool cmp(Cup a,Cup b){
	return a.h<b.h;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	long long ans=0;int n=0;cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i].h>>a[i].r;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
	ans+=a[i].r*a[i].r*(a[i].h-a[i-1].h);
	cout<<ans;
	return 0;
}
