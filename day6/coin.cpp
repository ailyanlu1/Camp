#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define maxn 100001

using namespace std;

double computesafemoney(double x,double y)
{
	return min(x,y);
		
}
struct host{
	double ai,bi;
}money[maxn];

double aside,bside;
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf %lf",&money[i].ai,&money[i].bi);
	for(int i=0;i<n;i++)
	{
		aside+=money[i].ai-1;
		bside+=money[i].bi-1;
		if(min(aside,bside)==aside)
			bside-=money[i].bi-1;
		else
			aside-=money[i].ai-1;
	}
	printf("%d",min(aside,bside));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

