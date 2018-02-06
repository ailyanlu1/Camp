#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

#define maxn 1001

int n,m,ll,rr;
int map[maxn][maxn];

int dfs(int tx,int ty)
{
	
}

using namespace std;

int main()
{
	scanf("%d %d %d %d",&n,&m,&ll,&rr);
	for(int i=1;i<=m;i++)
	{
		int one,two,three;
		scanf("%d %d %d",&one,&two,&three);
		map[one][two]=three;
	}
	
	return 0;
}
