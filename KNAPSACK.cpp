#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,W; cin>>n>>W;
	vector<int> v(n+1),w(n+1);
	vector<vector<int>> dp(n+1,vector<int>(W+1)),dp2(n+1,vector<int>(W+1));
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(i==0||j==0) {dp[i][j]=0; dp2[i][j]=0;}
			else if(w[i]<=j){
				dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
				dp2[i][j]=dp2[i-1][j]+1;
				if(dp[i-1][j]<v[i]+dp[i-1][j-w[i]]) {dp[i][j]=v[i]+dp[i-1][j-w[i]]; dp2[i][j]=dp2[i-1][j-w[i]]+1;}
				else {dp[i][j]=dp[i-1][j]; dp2[i][j]=dp2[i-1][j];}
			}
			else {dp[i][j]=dp[i-1][j]; dp2[i][j]=dp2[i-1][j];}
		}
	}
	cout<<dp[n][W]<<endl<<dp2[n][W];
	return 0;
}