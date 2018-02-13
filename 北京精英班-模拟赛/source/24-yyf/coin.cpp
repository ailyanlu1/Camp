#include <fstream>
#include <algorithm> 

using namespace std;

ifstream fin("coin.in");
ofstream fout("coin.out");

double a[100010],b[100010];
int n; 

bool px(double aa,double bb)
{
	return aa>bb; 
} 

int main()
{
	double ans=0.0,tx=0.0,td=0.0;
	int i,j; 
	
	fin>>n; 
	
	for (i=0;i<n;++i)
	{
		fin>>a[i]>>b[i]; 
	} 
	
	sort(a,a+n,px);
	sort(b,b+n,px);
	
	i=j=0;
	
	while (i<n|j<n)
	{
		tx-=1.0;
		td-=1.0;
		if (i==n)
		{
			tx+=b[j++]; 
		} 
		else if (j==n)
		{
			td+=a[i++]; 
		} 
		else if (td>tx)
		{
			tx+=b[j++]; 
		} 
		else
		{
			td+=a[i++]; 
		} 
		ans=max(ans,min(tx,td)); 
	} 
	
	fout.setf(ios_base::fixed);
	fout.precision(4);
	fout<<ans; 
	
	return 0; 
}
