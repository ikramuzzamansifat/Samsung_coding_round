#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)


int n,m,k;

void solve()
{
    map<string, int> mp;
    map<string, int>::iterator it;

    cin >> n >> m >> k;
    char arr[n][m];
    REP(i,0,n){
        string s = "";
        REP(j,0,m) {
        cin >> arr[i][j];
        s += arr[i][j];
        }
        mp[s]++;
    }

    // REP(i,0,m.size()) cout << m[i][0] << " " << m[i][1] << "\n";
    int noz,mx = 0;
    for(it = mp.begin(); it!=mp.end(); it++){
        string t = it->first;
        noz = 0;
        REP(i,0,m)
            if(t[i] == '0')noz++;
        if(k>=noz && (k-noz)%2==0){
            if(it->second > mx) mx = it->second;
        }
    }
    cout << mx << "\n";
    // cout << "\n";


}

int main()
{
    solve();
}
