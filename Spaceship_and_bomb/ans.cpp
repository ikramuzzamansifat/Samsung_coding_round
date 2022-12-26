#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i<b; i++)

int t,n,ans;

void recursion(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j, bool bombused, int row, int coins)
{
    if(i<0 || j<0 || j>=5 ) {
        ans = max(ans,coins);
        return;
    }
    if(arr[i][j] == 1 || arr[i][j] == 2)
    {
        int new_coins = coins;
        if(arr[i][j] == 1){
            new_coins++;
        }
        if(bombused) row--;
        recursion(arr,dp,i-1,j-1,bombused,row,new_coins);
        recursion(arr,dp,i-1,j,bombused,row,new_coins);
        recursion(arr,dp,i-1,j+1,bombused,row,new_coins);
    }
    else if(arr[i][j] == 2){
        if(bombused){
            if(row<=0){
                ans = max(ans,coins);
                return;
            }
            else{
                row--;
                recursion(arr,dp,i-1,j-1,bombused,row,coins);
                recursion(arr,dp,i-1,j,bombused,row,coins);
                recursion(arr,dp,i-1,j+1,bombused,row,coins);
            }
        }
        else{
            bombused = 1;
            row = 4;
            recursion(arr,dp,i-1,j-1,bombused,row,coins);
            recursion(arr,dp,i-1,j,bombused,row,coins);
            recursion(arr,dp,i-1,j+1,bombused,row,coins);
        }
    }
}

int main()
{
    cin >> t;
    REP(i,1,t+1)
    {
        cin >> n;
        // int arr[n][5], dp[n][5];
        vector <vector<int>> arr, dp;
        arr.resize(n, vector<int>(5)); 
        dp.resize(n, vector<int>(5)); 
        REP(i,0,n)REP(j,0,5){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }

        ans = 0;
        int row = 4;
        bool bombused = 0;
        recursion(arr,dp,n-1,1,bombused,row,0);
        recursion(arr,dp,n-1,2,bombused,row,0);
        recursion(arr,dp,n-1,3,bombused,row,0);
        cout << "#" << i << " " << ans << "\n";
    }    
}
