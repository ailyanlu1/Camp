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
		la[i]=i-1;//ǰһ���λ�� 
		ne[i]=i+1;//��һ���λ�� 
	}
	sort(a+1,a+n+1);//Ȩֵ��С����Ȩֵ�������Ӵ�С 
	for(i=1;i<=n;i++){//ö�� 
		x=n-a[i].second;
		ans[x]=ne[x]-x-1;//��� 
		aans+=ans[x];
		del(x);//ɾ�� 
	}
	printf("%d\n",aans);
}
