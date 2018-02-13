#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int n,m;
struct node{
	int from;
	int to;
	int time;
}point[1001];
int searchway(int x)
{
	int sign1=1;
	int countnum=0;
	int countnum1=0;
	int swap1[1001];
	memset(swap,0,sizeof(swap));
	while(sign1)
	{
		if(point[countnum].from==x)
		{
			swap1[countnum1]=point[countnum].to;
			countnum++;
			countnum1++;
		}
		if(countnum)
	}
}


int main()
{
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		 scanf("%d %d %d",&point[i].from,&point[i].to,&point[i].time);
	}
	searchway(1);
	return 0;
}
