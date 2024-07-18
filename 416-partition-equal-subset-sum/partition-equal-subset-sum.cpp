class Solution {
public:
    bool helper(int ind, int target, vector<int> &arr){
	if(ind == arr.size()){
		return false;		
	}
	if(target == 0) return true;
	
	bool take = false;
	if(target >= arr[ind]){
		take = helper(ind + 1, target - arr[ind], arr);
	}

	bool notTake = helper(ind + 1, target, arr);

	return take || notTake;
}


bool canPartition(vector<int> &arr){
	int sum = 0;
	int n = arr.size();
	
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}

	if(sum % 2 != 0) return false;
    int target = sum / 2;
	// return helper(0, sum / 2, arr);

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    // base case
    for(int i = 0; i < n + 1; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i < target + 1; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < target + 1; j++){
            bool take = false;
            if(j >= arr[i - 1]){
                take = dp[i - 1][j - arr[i - 1]];
            }

            bool notTake = dp[i - 1][j];

            dp[i][j] = take || notTake;
        }
    }

    return dp[n][target];
}

};