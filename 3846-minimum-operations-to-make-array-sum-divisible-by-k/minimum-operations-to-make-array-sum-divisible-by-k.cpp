class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for(int x : nums){
            sum += x;
            }
        int ans = sum % k;
        return ans ;
    }
};