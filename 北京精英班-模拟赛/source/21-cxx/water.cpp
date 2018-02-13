#include<bits/stdc++.h>

#define MAXN 1010
using namespace std;

int n;
long long ans=0;
int h[MAXN],r[MAXN];

bool comp(int a, int b)
{
	return a>b;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i]>>r[i];
	sort(r+1,r+n+1);
	sort(h+1,h+n+1,comp);
	for(int i=1;i<=n;i++) {
		ans+=r[i]*r[i]*h[i]-h[i]*r[i-1]*r[i-1];
	}
	cout<<ans;
	return 0;
}
