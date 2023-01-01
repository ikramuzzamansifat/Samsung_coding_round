#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)
#define inf 1e9

struct node{
    int x,y,l;
};

int n,m, arr[100][100];
bool visited[100][100];
bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

bool left(int x, int y)
{
return (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==6 || arr[x][y]==7); 
}
bool right(int x, int y)
{
return (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==4 || arr[x][y]==5); 
}
bool up(int x, int y)
{
return (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==4 || arr[x][y]==7); 
}
bool down(int x, int y)
{
return (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==5 || arr[x][y]==6); 
}

int solve(int x, int y, int l)
{
    visited[x][y] = 1;
    queue<node> q;
    q.push({x,y,l});
    int ans = 0;
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int l = cur.l;
        if(l == 0) continue;
        ans++;
            if(valid(x,y-1) && left(x,y) && right(x,y-1) && visited[x][y-1] == 0){
                q.push({x,y-1,l-1});
                visited[x][y-1] = 1;
            }
            if(valid(x,y+1) && right(x,y) && left(x,y+1) && visited[x][y+1] == 0){
                q.push({x,y+1,l-1});
                visited[x][y+1] = 1;
            }
            if(valid(x-1,y) && up(x,y) && down(x-1,y) && visited[x-1][y] == 0){
                q.push({x-1,y,l-1});
                visited[x-1][y] = 1;
            }
            if(valid(x+1,y) && down(x,y) && up(x+1,y) && visited[x+1][y] == 0){
                q.push({x+1,y,l-1});
                visited[x+1][y] = 1;
            }
    }
    
    return ans;
}


int main()
{
    int t;
    cin >> t;
    int x,y,l;
    while(t--){
        cin >> n >> m >> x >> y >> l;
        REP(i,0,n){
            REP(j,0,m){
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }
        if(arr[x][y] > 0) cout << solve(x,y,l) << "\n";
        else cout << 0 << "\n";
    }
}
