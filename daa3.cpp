#include <bits/stdc++.h>


// Write a program to solve a 0-1 Knapsack problem 
// using dynamic programming or branch and bound strategy.

using namespace std;


int knapsack(int idx, int cap, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {

	int result = 0;

	if (idx == weights.size() || cap == 0) {
		return result;
	}

	if (dp[idx][cap] != -1) return dp[idx][cap];
	
	// exclude
	int exclude = knapsack(idx + 1, cap, weights, values, dp);
	
	int include = 0;
	// include
	if (weights[idx] <= cap) {
		include = values[idx] + knapsack(idx + 1, cap - weights[idx], weights, values, dp);
	}

	return dp[idx][cap] = max(exclude, include);
}

int main() {

	cout << "HW!" << endl;

	vector<int> weights = {2, 3, 4, 5};
	vector<int> values = {40, 50, 65, 70};

	int capacity = 7;

	vector<vector<int>> dp(weights.size(), vector<int>(capacity + 1, -1));

	int res = knapsack(0, capacity, weights, values, dp);

	cout << res << endl;
	
	return 0;
}
