#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define maxn 1001

using namespace std;

int result[maxn];
int answer=0;

struct data{
	int height;
	int r;
}cup[maxn];

int compare(data x,data y)
{
	return x.height>y.height;//得到一个升序排列的 height
}

int countnum=0;
int heightsort[maxn];



int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&cup[i].height,&cup[i].r);
		countnum++;
	}
	sort(cup,cup+countnum,compare);
	/*for(int i=0;i<num;i++)
	{
		printf("height=%d\n",cup[i].height);
		printf("r=%d\n",cup[i].r);
	}*/
	for(int i=0;i<num;i++)
	{
		if(i==num-1)
			;
		else
			cup[i].height-=cup[i+1].height;
		//printf("%d\n",cup[i].height);
		answer+=(cup[i].height*cup[i].r*cup[i].r);
		//printf("%d\n",(cup[i].height*cup[i].r*cup[i].r));
	} 
	printf("%d",answer);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


