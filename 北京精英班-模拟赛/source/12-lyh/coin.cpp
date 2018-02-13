#include <cstdio>
using namespace std;

int n;

double game[100005][2];
//pair<double, double> game[100005];

double max(double a, double b){
	return a > b ? a : b;
}

double min(double a, double b){
	return a < b ? a : b;
}

double trythis(unsigned long long state){//枚举所有可能 
	double yes = 0;
	double no = 0;
	int bakup = state;
	for(int i = 0; i < n; ++i){
		if((state & 3ul) == 3ul){//skip
			//printf("skip ");
			state >>= 2;
			continue;
		}else if((state & 2ul) == 2ul){//yesno
			//printf("yn ");
			yes += game[i + 1][0] - 2;
			no += game[i + 1][1] - 2;
		}else if((state & 1ul) == 1ul){//yes
			//printf("y ");
			yes += game[i + 1][0] - 1;
			no -= 1;
		}else if((state & 0ul) == 0ul){//no
			//printf("n ");
			no += game[i + 1][1] - 1;
			yes -= 1;
		}
		state >>= 2;
	}
	double ans = min(yes, no);
	//printf("%3x: %lf\n", bakup, ans);
	return ans;
}

int main(){
	//int t = time(0);
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	scanf("%d", &n);
	double cbig, csmall;
	double ans = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%lf%lf", game[i], game[i] + 1);//&cbig, &csmall);
		//game[i].first = cbig;
		//game[i].second = csmall;
		//printf("%lf %lf\n", cbig, csmall);
	}
	//sort(game + 1, game + n);
	//if(n <= 10){
	for(unsigned long long i = 0; i < (1 << (2 * n)); ++i){
		ans = max(ans, trythis(i));
		//if(i % 1000 == 0)if(time(0) - t > 1)break;
	}	
	//}
	//trythis(92);
	printf("%.4lf\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
