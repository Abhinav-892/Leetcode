class Solution {
public:
    struct Compare {
        bool operator()(string a, string b) {
            if(a.size() != b.size())
                return a.size() > b.size();

            return a > b;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {

        priority_queue<string, vector<string>, Compare> pq;

        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++) {
            if(Compare()(nums[i], pq.top())) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};