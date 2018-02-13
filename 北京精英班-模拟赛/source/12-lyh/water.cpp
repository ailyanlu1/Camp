#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair<int, int> cup[2000];
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out","w",stdout);
	int n;
	scanf("%d", &n);
	int a, b;
	for(int i = 0; i < n ;++i){
		scanf("%d%d", &a, &b);
		b *= b;//a为高，b为底面积 
		cup[i].first = a, cup[i].second = b;
	}
	sort(cup, cup + n);
	long long ans = 0;
	int maxsec = 0;
	for(int i = n;  i >= 0; --i){
		if(cup[i].second > maxsec)maxsec = cup[i].second;
		if(i != 0){
			ans += maxsec * (cup[i].first - cup[i - 1].first); 
		}else{
			ans += maxsec * cup[i].first;
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
