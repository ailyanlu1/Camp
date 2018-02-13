#include<bits/stdc++.h>
#define max1 1000000000
using namespace std;
int a[1001][1001];
int d[1001];
int p[1001];
int i,j,k;
int m;
int n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int min1;
	int x,y,z;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	for(i=1;i<=n;i++)
	d[i]=max1;
	d[1]=0;
	for(i=1;i<=n;i++){
		min1=max1;
		for(j=1;j<=n;j++)
		if(!p[j]&&d[j]<min1)
		{
			min1=d[j];
			k=j;
		}
			p[k]=j;
	for(j=1;j<=n;j++)
		if(a[k][j]!=0&&!p[j]&&d[j]>d[k]+a[k][j])
			d[j]=d[k]+a[k][j];
	}
cout<<d[n];
return 0;
}
