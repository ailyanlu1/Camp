#include<cstdio>
int note[1010];
int n;
float a,b;
float c[1010][4][2];
float ans=0;
float min(float a,float b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}
float max(float a,float b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int dfs(int dep)
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int k;
	float end1=0,end2=0;
	if(dep==n)
	{
		for(k=0;k<n;k++)
		{
			end1+=c[k][note[k]][0];
			end2+=c[k][note[k]][1];
		}
		end1=min(end1,end2);
		ans=max(ans,end1);
		return 0;
	}
	for(k=0;k<4;k++)
	{
		note[dep]=k;
		dfs(dep+1);
	}
	return 0;
}
int main()
{
	int k,i,j;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%f%f",&a,&b);
		c[k][0][0]=a-2;
		c[k][0][1]=b-2;
		c[k][1][0]=0;
		c[k][1][1]=0;
		c[k][2][0]=a-1;
		c[k][2][1]=-1;
		c[k][3][0]=-1;
		c[k][3][1]=b-1;
	}
	/*for(k=0;k<n;k++)
	{
		scanf("%f%f",&a[k],&b[k]);
	}*/
	dfs(0);
	printf("%0.4f",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
