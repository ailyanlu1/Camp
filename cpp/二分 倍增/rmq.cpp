#include <bits/stdc++.h>
using namespace std;

const int maxn=100000+15;
int n,m; 
int rmq[20][maxn];  //rmq[i][j]表示j到j+(2^i)-1的最大值 
int arr[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&rmq[0][i]);
	for (int i=1;i<=18;i++)
	 for (int j=1;j<=n;j++)
	  if (j+(1 << i)-1<=n)
	   rmq[i][j]=max(rmq[i-1][j],rmq[i-1][j+(1 << (i-1))]);  //维护rmq[i][j] 
	arr[1]=0;
	for (int i=2;i<=n;i++) arr[i]=arr[i>>1]+1;
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int s=arr[y-x+1];
	//	int s=(int)(log(y-x+1)/log(2));  //找到最大的s使得2^s<=y-x+1 
		printf("%d\n",max(rmq[s][x],rmq[s][y-(1 << s)+1]));
	}
	return 0;
 } 
