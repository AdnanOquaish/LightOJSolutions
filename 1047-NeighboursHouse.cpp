#include<bits/stdc++.h>
 
using namespace std;
int t,n;
int arr[250][50];
int dp[250][50];
int flag[250][50];
 
int findMinCost(int row, int prevSelection)
{
    if(row >= n)
        return 0;
    if(prevSelection == 0)
    {
        if(flag[row+1][1] == 1)
        {
            if(flag[row+1][2] == 1)
            {
                return min(arr[row][1] + dp[row+1][1], arr[row][2] + dp[row+1][2]);
            }
            dp[row+1][2] = findMinCost(row+1,2);
            flag[row+1][2] = 1;
            return min(arr[row][1] + dp[row+1][1], arr[row][2] + dp[row+1][2]);
        }
        else
        {
            dp[row+1][1] = findMinCost(row+1,1);
            flag[row+1][1] = 1;
            if(flag[row+1][2] == 1)
            {
                return min(arr[row][1] + dp[row+1][1], arr[row][2] + dp[row+1][2]);
            }
            dp[row+1][2] = findMinCost(row+1,2);
            flag[row+1][2] = 1;
            return min(arr[row][1] + dp[row+1][1], arr[row][2] + dp[row+1][2]);
        }
    }
    else if(prevSelection == 1)
    {
        if(flag[row+1][0] == 1)
        {
            if(flag[row+1][2] == 1)
            {
                return min(arr[row][0] + dp[row+1][0], arr[row][2] + dp[row+1][2]);
            }
            dp[row+1][2] = findMinCost(row+1,2);
            flag[row+1][2] = 1;
            return min(arr[row][0] + dp[row+1][0], arr[row][2] + dp[row+1][2]);
        }
        else
        {
            dp[row+1][0] = findMinCost(row+1,0);
            flag[row+1][0] = 1;
            if(flag[row+1][2] == 1)
            {
                return min(arr[row][0] + dp[row+1][0], arr[row][2] + dp[row+1][2]);
            }
            dp[row+1][2] = findMinCost(row+1,2);
            flag[row+1][2] = 1;
            return min(arr[row][0] + dp[row+1][0], arr[row][2] + dp[row+1][2]);
        }
    }
    else if(prevSelection == 2)
    {
        if(flag[row+1][0] == 1)
        {
            if(flag[row+1][1] == 1)
            {
                return min(arr[row][0] + dp[row+1][0], arr[row][1] + dp[row+1][1]);
            }
            dp[row+1][1] = findMinCost(row+1,1);
            flag[row+1][1] = 1;
            return min(arr[row][0] + dp[row+1][0], arr[row][1] + dp[row+1][1]);
        }
        else
        {
            dp[row+1][0] = findMinCost(row+1,0);
            flag[row+1][0] = 1;
            if(flag[row+1][1] == 1)
            {
                return min(arr[row][0] + dp[row+1][0], arr[row][1] + dp[row+1][1]);
            }
            dp[row+1][1] = findMinCost(row+1,1);
            flag[row+1][1] = 1;
            return min(arr[row][0] + dp[row+1][0], arr[row][1] + dp[row+1][1]);
        }
    }
}
 
int main()
{
    int i,j,k,l,c;
    cin>>t;
    k = 0;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>arr[i][j];
            }
        }
        memset(flag,0,sizeof(flag[0][0])*240*40);
        memset(dp,0,sizeof(dp[0][0])*240*40);
        c = min(findMinCost(0,0),findMinCost(0,1));
        c = min(c,findMinCost(0,2));
        k++;
        cout<<"Case "<<k<<": "<<c<<endl;
    }
    return 0;
}
