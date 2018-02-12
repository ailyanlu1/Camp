#include <cstdio>
#define N 50055

int h[N],a[N],f[N],g[N],F[N],G[N],n,i,top;
long long ans,tmp;

int main()
{
	scanf("%d", &n);
	h[0] = -1000000000;
	top = 0;
	for (i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]); 
		h[++top] = a[i]; // f[i]是单调栈里记的高度 
		f[top] = 1;
		while (h[top] <= h[top-1])
		{
			f[top-1] += f[top]; // f[i]是单调栈里记的dp值 
			h[top-1] = h[top];
			--top;
		}
		F[i] = f[top]; // F[i]相当于课件里的f[i] 
	}
	top = 0;
	for (i=n; i>=1; --i)
	{
		h[++top] = a[i];
		g[top] = 1;
		while (h[top] <= h[top-1])
		{
			g[top-1] += g[top];
			h[top-1] = h[top];
			--top;
		}
		G[i] = g[top];
		tmp = (long long)(F[i]+G[i]-1)*a[i];
		if (tmp > ans) ans = tmp;
	}
	printf("%lld\n", ans);
	return 0;
}
