class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Initialize the sum
        int sum = 0;

        // Step 3: Add every second element (which are the minimums in each pair)
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        // Step 4: Return the sum
        return sum;
    }
};
