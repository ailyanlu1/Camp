#include<bits/stdc++.h>
using namespace std;
int n;unsigned long long total;
struct roll{
	int high;
	int wide;
};
roll num[1001];
bool cmp(roll a,roll b){
	return a.high<b.high;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&num[i].high,&num[i].wide);
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++){
		total+=num[i].wide*num[i].wide*(num[i].high-num[i-1].high);
	}
	cout<<total;
}
