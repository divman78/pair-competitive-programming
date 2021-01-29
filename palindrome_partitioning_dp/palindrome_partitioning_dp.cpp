#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin >> str;
    int n = str.length();
    int dp[n][n];
    bool p[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        p[i][i] = true;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n-l; i++){
            int j = i+l-1;
            if(l == 2) p[i][j] = (bool)(str[i] == str[j]);
            else       p[i][j] = (bool)(p[i+1][j-1] && str[i] == str[j]);
            //cout << i << " " << j << " " << p[i][j] << " " << str.substr(i,l) << endl;
            if(p[i][j]){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][k]+dp[k+1][j]+1,dp[i][j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}


signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
	int t=1;
	//cin >> t; 
	while(t--){
        solve();
	}
	return 0;
}