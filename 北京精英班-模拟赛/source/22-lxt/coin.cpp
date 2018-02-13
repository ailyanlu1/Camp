#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100010;
double a[maxn],b[maxn];
int n;
bool cmp(double a,double b)
{
	return a>b;
}
double minx(double a,double b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	//+1s
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a[i],&b[i]);
	}
	
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	
	double x=0.0,y=0.0;
	int n1=0,n2=0; 
	double last;
	a[n+1]=-1999999999.0;//防止一列放完 
	b[n+1]=-1999999999.0;
	
	while(1)
	{
	  if(n1!=0&&n2!=0)last=minx(x,y);
	  else last=-19999.0; 
	 
	  if(a[n1+1]<1.0||b[n2+1]<1.0)
	     if(n1!=n&&n2!=n)break;
	  if(n1==n&&n2==n)break;
	  if(x==y)
	  {
		if(a[n1+1]>b[n2+1])
		{
		  if(y-1.0>last)
		  {
		  	x+=a[++n1]-1.0;
		  	y--;
		  }  
		  else break;
	    }
	    else if(a[n1+1]<b[n2+1])
		{
		 
	      if(x-1.0>last)
		  {
		  	y+=b[++n2]-1.0;
		  	x--;
		  }
		  else break;
	    }
	  }
	  else if(x>y)
	  {
	  	 if(x-1.0>last)
		  {
		  	y+=b[++n2]-1.0;
		  	x--;
		  }
		 else break;
	  }
	  else if(x<y)
	  {
	  	  if(y-1.0>last)
		  {
		  	x+=a[++n1]-1.0;
		  	y--;
		  }
		  else break;
	  }
	   
	}
	
	if(x<=(double)0.0000||y<=(double)0.0000)
	      printf("0.0000\n");
	else 
	{
	double ans=minx(x,y);
	printf("%.4lf\n",ans);
    }
    
    fclose(stdin);
    fclose(stdout);
	return 0;
}
