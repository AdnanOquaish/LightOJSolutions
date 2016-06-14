#include<bits/stdc++.h>
using namespace std;
 
pair<vector<int>, int> divBuckets[1005];
 
int findDiv(int n)
{
    int i,c = 0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
        }
    }
    return c;
}
 
int main()
{
    int i,j,k,l,t,n;
    int tempn;
    for(i=0;i<=100;i++)
    {
        divBuckets[i].second = 0;
    }
    for(i=1000;i>=1;i--)
    {
        j = findDiv(i);
        divBuckets[j].first.push_back(i);
        divBuckets[j].second++;
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        tempn = n;
        for(k=1;k<1001;k++)
        {
            if(tempn <= divBuckets[k].second)
            {
                l = divBuckets[k].first[tempn-1];
                break;
            }
            tempn -= divBuckets[k].second;
        }
        X:
        cout<<"Case "<<i<<": "<<l<<endl;
    }
    return 0;
}
