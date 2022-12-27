// Problem link: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators/submissions/code/1354123772

#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)
#define inf 1e9
int t,n, dp[1<<13][13], dist[13][13], arr[13][2], visited_all,p;

int abs(int x)
{
    if(x<0) return -x;
    return x;
}

int tsp(int mask, int pos)
{
    if(mask == visited_all) return dist[pos][n+1];  // because kim has to go home.. 

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = inf;
    REP(i,0,n+1){
        if((mask&(1<<i)) == 0){
            int newAns = dist[pos][i] + tsp(mask|(1<<i), i);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    t = 10;
    REP(k,1,t+1)
    {
        cin >> n;
        visited_all = (1<<(n+1)) - 1;
        p = 1<<(n+2);
        REP(i,0,p) REP(j,0,n+1) dp[i][j] = -1;
        cin >> arr[0][0] >> arr[0][1];
        cin >> arr[n+1][0] >> arr[n+1][1];
        REP(i,1,n+1) cin >> arr[i][0] >> arr[i][1];

        REP(i,0,n+2)REP(j,i+1,n+2){
            dist[i][j] = abs(arr[i][0]-arr[j][0]) + abs(arr[i][1]-arr[j][1]);
            dist[j][i] = dist[i][j];
        }
        // REP(i,0,n+2){
        //     REP(j,0,n+2) cout << dist[i][j] << " ";
        //     cout << "\n";
        // } 

        cout << "# " << k << " " << tsp(1,0) << "\n";
    }

}
