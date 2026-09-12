class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_set<int> st;

        for (int i : nums) {
            st.insert(i);
        }

        int global_len = 0;

        for (int i : st) {
            if (!st.count(i - 1)) {
                int currlen = 1;
                int currNum = i;

                while (st.count(currNum + 1)) {
                    currlen++;
                    currNum++;
                }
                global_len = max(currlen, global_len);
            }
        }
        return global_len;
    }
};