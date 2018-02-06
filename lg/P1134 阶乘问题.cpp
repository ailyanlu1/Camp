#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	long long ans=1;
	scanf("%lld",&n);
	for(long i=1;i<=n;i++)
	{
		ans*=i;
		while(ans%10==0)
			ans/=10;
		//printf("1=%d\n",ans);
		ans=ans%10000000;
		//printf("2=%d\n",ans);
	}
	printf("%lld",ans%10);
}
