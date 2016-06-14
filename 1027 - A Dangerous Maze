#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,k,l,m,n,t,p,q;
	int np,nn,sp,sn;
	cin>>t;
	for(l=1;l<=t;l++)
	{
		np=nn=sp=sn=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>j;
			if(j>0)
			{
				np++;
				sp+=j;
			}
			else
			{
				nn++;
				sn-=j;
			}
		}
		if(np==0)
		{
			cout<<"Case "<<l<<": inf"<<endl;
		}
		else
		{
			p = sp+sn;
			q = __gcd(p,np);
			cout<<"Case "<<l<<": ";
			cout<<(p/q)<<"/"<<(np/q)<<endl;
		}
	}
	return 0;
}
