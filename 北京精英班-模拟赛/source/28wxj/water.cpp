#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define ll long long
using namespace std;
struct cup
{
	ll h,r;
}c[2000];
bool cmp(cup a,cup b)
{
	return a.h>b.h;
}
ll n,ans;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>c[i].h>>c[i].r;
	sort(c+1,c+1+n,cmp);
	ans+=c[1].r*c[1].r*c[1].h;
	for(int i=2;i<=n;i++)
	ans+=(c[i].r*c[i].r-c[i-1].r*c[i-1].r)*c[i].h;
	cout<<ans;
	return 0;
}
