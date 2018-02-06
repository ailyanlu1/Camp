#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

#define maxn 10001

int x[maxn];
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&x[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int choice;
		scanf("%d",&choice);
		if(choice==1)
		{
			int l=0,r=0,a=0,j=0;
			scanf("%d %d %d",&l,&r,&a);
			for(l;l<=r+1;l++);
			{
				x[l-1]+=(a+j)*(a+j);
				printf("%d",(a+j)*(a+j));
				j++;
				//printf("%d\n",x[l-1]);
			}
		}
		if(choice==2)
		{
			int want=0;
			int l=0,r=0;
			scanf("%d %d",&l,&r);
			for(l;l<=r;l++)
			{
				//printf("Ö´ÐÐÁË"); 
				want+=x[l-1];
			}
			printf("%d\n",want%1000000007);
		}
	}
	return 0;
}
