#include<bits/stdc++.h>
using namespace std;


//problem-link - https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
//CODE STARTS
void solve(){

    int n;
    cin >> n; 	
    int sz[n];
    for(int i = 0; i < n; i++){
        cin >> sz[i];
    }
    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n-l; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][k]+dp[k+1][j]+sz[i-1]*sz[k]*sz[j], dp[i][j]);
                //cout << i << " " << k << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    cout << dp[1][n-1] << endl;
}
//CODE ENDS

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