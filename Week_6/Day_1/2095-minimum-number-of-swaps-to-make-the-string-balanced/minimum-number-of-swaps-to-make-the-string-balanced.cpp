class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n = s.size();

        for (char ch : s) {
            if (ch == '[') {
                st.push(ch);
            } else {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(ch);
            }
        }

        int unmatched = st.size();
        return (unmatched / 2 + 1) / 2;
    }
};