#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iomanip>
#define ll long long
using namespace std;
int n;
double a[100020],b[100020],ans=0,s1[100020],s2[100020],ans1,ans2;
bool cmp(double a,double b)
{
	return a>b;
}
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	//ans=search(0,2*n);
	for(int i=1;i<=n;i++)
	{
			double ans1_=ans1,ans2_=ans2;
			ans1_+=a[i]-1;
			ans2_-=1;
			ans=max(ans,min(ans1_,ans2_));
			ans1_-=1;
			ans2_+=b[i]-1;
			ans=max(ans,min(ans1_,ans2_));
			double ans1__=ans1,ans2__=ans2;
			ans1__-=1;
			ans2__+=b[i]-1;
			ans=max(ans,min(ans1__,ans2__));
			ans1__+=a[i]-1;
			ans2__-=1;
			ans=max(ans,min(ans1__,ans2__));
			if(min(ans1_,ans2_)>min(ans1__,ans2__))
			ans1=ans1_,ans2=ans2_;
			else
			ans1=ans1__,ans2=ans2__;
	}
	cout<<setprecision(4)<<fixed<<ans;
	return 0;
}
