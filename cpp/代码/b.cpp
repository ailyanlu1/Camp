#include<bits/stdc++.h> 
using namespace std;
int n,i,top,ne[100010],la[100010],x,ans[100010],aans;
pair<int,int>a[100010];
void del(int x){
	ne[la[x]]=ne[x];
	la[ne[x]]=la[x];
}
int main(){
	scanf("%d",&n);
	ne[0]=1;
	la[n+1]=n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=n-i;
		la[i]=i-1;//前一项的位置 
		ne[i]=i+1;//后一项的位置 
	}
	sort(a+1,a+n+1);//权值从小到大，权值相等坐标从大到小 
	for(i=1;i<=n;i++){//枚举 
		x=n-a[i].second;
		ans[x]=ne[x]-x-1;//求答案 
		aans+=ans[x];
		del(x);//删除 
	}
	printf("%d\n",aans);
}
