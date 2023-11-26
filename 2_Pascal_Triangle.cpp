vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> res;
    for(int i = 0; i < N; ++i){
        vector<int> x(i+1, 1);
        for(int j = 1; j < i; ++j){
            x[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(x);
    }

    return res;
}