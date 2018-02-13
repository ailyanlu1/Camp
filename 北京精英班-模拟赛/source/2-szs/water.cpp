#include <bits/stdc++.h>
int n, c[11000],b[11000],ans;
int main(){
	freopen ("water.in","r",stdin);
	freopen ("water.out","w",stdout);
	int i;
    scanf("%d", &n); 
	for(i =1; i <= n; i++) scanf("%d%d", &c[i],&b[i]);
	ans=0;
	for(i =1; i <= n; i++){
		ans+=((c[i])*c[i]*(b[i]-b[i+1]));
	}
	printf ("%d",ans);
	return 0;
}
