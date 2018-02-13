#include <fstream>
#include <vector> 
#include <algorithm> 
#include <cstdlib> 

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

vector<int> g[510]; 
int d[510][510],dd[510][510],n,m,f[510][60]; 
bool cb,vis[510],zy[510][60]; 

int main()
{
	int i,j,k,t,x,y,w,mind,mindi,c;
	
	fin>>n>>m;
	
	for (i=0;i<m;++i)
	{
		fin>>x>>y>>w;
		g[x].push_back(y);
		g[y].push_back(x); 
		dd[x][y]=dd[y][x]=d[x][y]=d[y][x]=w; 
	}
	
	for (i=1;i<=n;++i)
	{
		fin>>k;
		if (k>0)
		{
			cb=true; 
		} 
		for (j=0;j<k;++j)
		{
			fin>>t;
			zy[i][t]=true; 
		} 
	} 
	
	for (j=1;j<=n;++j)
	{
		mind=0x7fffffff; 
		for (i=1;i<=n;++i)
		{
			if (!vis[i]&&d[n][i]>0&&d[n][i]<mind)
			{
				mind=d[n][i]; 
				mindi=i; 
			} 
		} 
		vis[mindi]=true; 
		for (i=1;i<n;++i)
		{
			if (d[mindi][i]&&(d[n][i]==0||d[n][i]>d[n][mindi]+d[mindi][i]))
			{
				d[n][i]=d[n][mindi]+d[mindi][i]; 
			} 
		} 
	}
	
	if (!cb) 
	{ 
		fout<<d[n][1]; 
	} 
	
	else
	{
		for (i=1;i<n;++i)
		{
			f[i][51]=d[n][i]; 
		}
		for (j=50;j>=0;--j)
		{
			for (i=1;i<n;++i)
			{
				if (f[i][j+1]) 
				{ 
					f[i][j]=f[i][j+1]+1; 
				} 
				if (!zy[i][j]) 
				{ 
					for (w=0;w<g[i].size();++w)
					{
						k=g[i][w];
						c=dd[i][k];
						if (j+c>50&&(d[n][k]||n==k)) 
						{
							if (f[i][j]==0||c+d[n][k]<f[i][j])
							{
								f[i][j]=c+d[n][k]; 
							} 
						} 
						else
						{
							if ((f[i][j]==0||c+f[k][j+c]<f[i][j])&&(f[k][j+c]||k==n)) 
							{
								f[i][j]=c+f[k][j+c]; 
							} 
						} 
					} 
				} 
			} 
		} 
		
		fout<<f[1][0]; 
	}
	
	return 0; 
} 
