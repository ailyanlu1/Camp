#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

#define maxn 101

char numberN[300];
int n,k;
int ll[maxn],rr[maxn];
int deg[maxn];
long long point;
int error=0;
int sw;

int cf(int gjd)
{
	//printf("haha");
	int ans=0;
	char numberM[300];
	if(gjd==1)
	{
		return point;
	}
	else if(gjd==100)
	{
		point+=2;
		return point;
	}
	else
	{
		numberM[0]=(gjd/10)+48;
		numberM[1]=(gjd%10)+48;
		//printf("终于来了");
	}
	int n = strlen(numberN), m = strlen(numberM);
	int a[n], b[m];
	int i, j;
	for (i = 0, j = n - 1; i < n; i++, j--)
		{
			a[i] = numberN[j] - '0';
		}
	for (i = 0, j = m - 1; i < m; i++, j--)
		{
			b[i] = numberM[j] - '0';
		}
	int c[600];
	for (i = 0; i < 300; i++)
		{
			c[i] = 0;
		}
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				{
					c[i + j] += a[i] * b[j];
				}
		}
	for (i = 0; i < n + m; i++)
		{
			if (c[i] >= 10)
				{
					c[i + 1] += c[i] / 10;
					c[i] %= 10;
				}
		}
	for (j = 599; j > 0; j--)
		{
			if (c[j] != 0)
				break;
		}
	for (i = j; i >= 0; i--)
		{
			ans++;
		}
	//printf("%d",ans);
	return ans;
}



using namespace std;

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);

	memset(ll,0,sizeof(ll));
	memset(rr,0,sizeof(rr));
	memset(deg,0,sizeof(deg));

	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d %d",&ll[i],&rr[i]);

	for(int i=0; i<n; i++)
		deg[i]=ll[i];

	sw=0;//位置标记
	while(point<k)
		{
			while(point<k)
				{
					point=0;
					for(int i=0;i<n;i++)
					{
						//printf("%d\n",deg[i]);
						cf(deg[i]);
					}
						
					//int exist=1;
					
					/*for(int i=0; i<n; i++)
						{
							if(deg[i]==1)
								{
									continue;
								}
							else if(deg[i]==100)
								{
									point+=2;
								}
							else
								{
									
								}
						}*/
					/*for(int i=0; i<n ; i++)
						point=deg[i]*point;*/
					//printf("%lld\n",point);
					deg[sw]++;
					//printf("deg[sw]=%d rr[sw]=%d point=%d\n",deg[sw],rr[sw],point);
					//system("pause");
					if(deg[sw]>=rr[sw])
						break;
				}
			sw++;
			//printf("one\n");
			if(sw==n)
				{
					error=1;
					break;
				}
		}

	if (error==0)
		{
			printf("-1");
			return 0;
		}

	int result=1;
	for(int i=0; i<n; i++)
		result+=deg[i];

	printf("%d",result-2);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
