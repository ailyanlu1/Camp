#include <bits/stdc++.h>
#define lls long long
int main(void)
{
	lls a,b,swap;
	lls tmp;
	bool exit;
	scanf("%lld %lld",&a,&b);
	int ans[10];
	memset(ans,0,sizeof(ans));
	for(lls i=a;i<=b;i++)
	{
		swap=i;
		exit=0;
		while(!exit)
		{
			while(swap>=10)
			{
				tmp=swap%10;
				ans[tmp]++;
				swap/=10;
			}
			ans[swap]++;
			exit=1; 
		}
	}
	printf("%d %d %d %d %d %d %d %d %d %d",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5],ans[6],ans[7],ans[8],ans[9]);
	return 0;
 } 
