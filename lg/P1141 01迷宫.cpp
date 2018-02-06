#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int n;
int map[maxn][maxn];

int dfs(int x,int y)
{
		 if(map[x+1][y]+map[x][y]==1&&x+1<=n)	dfs(x+1,y);
	else if(map[x-1][y]+map[x][y]==1&&x-1>=0)	dfs(x+1,y);
	else if(map[x][y+1]+map[x][y]==1&&y+1>=0)	dfs(x,y+1);
	else if(map[x][y-1]+map[x][y]==1&&y-1>=0)	dfs(x,y-1);
	else 
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&map[i]);
	}
	
	return 0;
}
