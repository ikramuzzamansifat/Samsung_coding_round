#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)
#define inf 1e9
int t,n,dist[12][12], dp[1<<12][12], visited_all;

int tsp(int mask, int pos)
{
    if(mask == visited_all) return dist[pos][0];
    
    if(dp[mask][pos] != -1) return dp[mask][pos];
    
    int ans = inf;
    REP(i,0,n){
        if((mask&(1<<i)) == 0){
            int newAns = dist[pos][i] + tsp(mask|(1<<i),i);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        visited_all = (1<<n) - 1;
        int p = 1<<n;
        REP(i,0,p)REP(j,0,n) dp[i][j] = -1;
        
        REP(i,0,n)REP(j,0,n) cin >> dist[i][j];
        
        cout << tsp(1,0) << "\n";
        
        
    }
}
