#include<cstdio>
#include<cstring>
using namespace std;
struct xir{
	int p,w;
};
int main()
{
	int k,i,j;
	int n,m;
	xir point[100][100];
	int tuhao[100][100];
	int tip[100];
	int a,b,c;
	xir queue[100];
	int worth[100];
	int l=0,r=0;
	memset(point,0,sizeof(point));
	scanf("%d%d",&n,&m);
	for(k=0;k<m;k++)
	{
		scanf("%d%d%d",&a,&b,&c);
		point[a][++point[a][0].p].p=b;
		point[a][point[a][0].p].w=c;
		point[b][++point[b][0].p].p=a;
		point[b][point[b][0].p].w=c;
	}
	for(k=0;k<n;k++)
	{
		scanf("%d",&i);
		for(j=0;j<i;j++)
		{
			scanf("%d",&tuhao[k][j]);
		}
	}
	while(l<=r)
	{
		for(k=1;k<=point[queue[l].p][0].p;k++)
		{
			if(tip[point[queue[l].p][k].p]==0) && worth[queue[l].p]+point[queue[l].p][k].w<worth[point[queue[l].p][k].p])
			{
				worth[point[queue[l].p][k].p]=worth[queue[l].p]+point[queue[l].p][k].w];
				queue[++r]=point[queue[l].p][k];
				tip[queue[r].p]=1;
			}
		}
		l++;
	}
	printf("%d",worth[n]);
	return 0;
}
