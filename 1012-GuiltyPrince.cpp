#include<bits/stdc++.h>
using namespace std;
int graph[500][500];
int visited[500][500];
int w,h;
 
int findLand(int x, int y)
{
    int count  = 0;
    if(graph[x+1][y] == 1 && x+1 < h && visited[x+1][y] == 0)
    {
        visited[x+1][y] = 1;
        count += 1 + findLand(x+1,y);
    }
    if(graph[x][y+1] == 1 && y+1 < w && visited[x][y+1] == 0)
    {
        visited[x][y+1] = 1;
        count += 1 + findLand(x,y+1);
    }
    if(graph[x-1][y] == 1 && x-1 > -1 && visited[x-1][y] == 0)
    {
        visited[x-1][y] = 1;
        count += 1 + findLand(x-1,y);
    }
    if(graph[x][y-1] == 1 && y-1 > -1 && visited[x][y-1] == 0)
    {
        visited[x][y-1] = 1;
        count += 1 + findLand(x,y-1);
    }
    return count;
}
 
 
int main()
{
    int i,j,k,l,t,x,y;
    char c;
    cin>>t;
    l = 0;
    while(t--)
    {
        cin>>w>>h;
        memset(visited, 0, sizeof(visited[0][0])*400*400);
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                cin>>c;
                if(c == '.')
                {
                    graph[i][j] = 1;
                }
                else if(c == '#')
                {
                    graph[i][j] = 0;
                }
                else if(c == '@')
                {
                    graph[i][j] = 1;
                    x = i;
                    y = j;
                }
            }
        }
        k = findLand(x,y);
        if(visited[x][y] == 0)
            k+=1;
        l++;
        cout<<"Case "<<l<<": "<<k<<endl;
    }
    return 0;
}
