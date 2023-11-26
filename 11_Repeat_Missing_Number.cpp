#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int req_sum = (n*(n+1))/2, rep = 0, sum = 0;

	for(int i = 0; i < n; ++i) sum += arr[i];

	for(int i = 0; i < n; ++i){
		int index = abs(arr[i]) - 1;
		arr[index] *= -1;
		if(arr[index] >= 0){
			rep = index+1;
			break;
		}
	}

	int miss = req_sum - (sum - rep);
	return make_pair(miss, rep);
	
}
