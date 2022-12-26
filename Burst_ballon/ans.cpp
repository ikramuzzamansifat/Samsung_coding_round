#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int n;
void solve()
{
    cin >> n;
    int arr[n], dp[n][n];
    REP(i,0,n) cin >> arr[i];
    bool left,right;
    int left_ans, right_ans;
    REP(i,0,n){
        if(i==0) left = 0; else left = 1;
        if(i==n-1) right = 0; else right = 1;
        
        if(left&&right) dp[i][i] = arr[i-1]*arr[i+1];
        else if(left) dp[i][i]  = arr[i-1];
        else if(right) dp[i][i] = arr[i+1];
        else dp[i][i] = arr[i];
    }
    int cnt = 2,temp,mx;
    while(cnt<=n)
    {
        REP(i,0,n-cnt+1){
                mx = -1;
            REP(last,i,i+cnt){
                if(last==i) left_ans = 0; else left_ans = dp[i][last-1];
                if(last==i+cnt-1) right_ans=0; else right_ans = dp[last+1][i+cnt-1];
                temp = left_ans+right_ans;

                if(i-1<0)left=0; else left=1;
                if(i+cnt>=n)right=0; else right = 1;
                if(left&&right) temp += arr[i-1]*arr[i+cnt];
                else if(left) temp += arr[i-1];
                else if(right) temp += arr[i+cnt];
                else temp += arr[last];

                // cout << i << " " << last << " ";
                // cout <<left_ans<<" "<<right_ans<<" "<<temp << "\n";
                if(temp > mx) mx = temp;
                
            }
            dp[i][i+cnt-1] = mx;
            // cnt++;
        }
        cnt++;
    }

    cout << dp[0][n-1] << "\n";
    // REP(i,0,n){
    //     REP(j,0,n)cout << dp[i][j] << " ";
    //     cout << "\n";
    // } 
}

int main()
{
    solve();

    return 0;
}
