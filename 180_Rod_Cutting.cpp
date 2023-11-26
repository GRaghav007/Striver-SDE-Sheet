
#include<bits/stdc++.h>

int solveByTabu(vector<int> price, int size, int target){
	vector<vector<int>> dp(size, vector<int>((target+1, 0)));

	for(int i = 0; i <= target; ++i)	dp[0][i] = price[0] * i;
	
	for(int i = 1; i < size; ++i){
		for(int j = 0; j <= target; ++j){
			int notPick = dp[i-1][j];
			int pick = -1e9;
			int rodLength = i+1;
			if(rodLength <= j)	pick = price[i] + dp[i][j-rodLength];

			return dp[i][j] = max(notPick, pick);
		}
	}

	return dp[size-1][target];
}

int cutRod(vector<int> &price, int n)
	int res = solveByTabu(price, n, n);

	return res;
}
