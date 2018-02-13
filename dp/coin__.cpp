#include<bits/stdc++.h>
using namespace std;
int N;
double a[100005],b[100005],ans,ta,tb;int pa,pb;
bool cmp(double a,double b)
{
	return a>b;
}
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin__.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		scanf("%lf%lf",&a[i],&b[i]);
	}	
	sort(a+1,a+N+1,cmp);sort(b+1,b+N+1,cmp);
	for(;;)
	{
		if(ta>tb&&pb<N)tb+=b[++pb];
	else	if(pa<N)ta+=a[++pa];
		if(pa>=N||pb>=N)break;
		ans=max(ans,min(ta,tb)-pa-pb);
	}
	printf("%.4f",ans);
	return 0;
}
