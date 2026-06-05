class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (auto ast : asteroids) {
            bool destroy = false;

            if (ast > 0) {
                st.push(ast);
            } else {

                if (st.empty() || st.top() < 0) {
                    st.push(ast);
                } else {
                    while (!st.empty() && st.top() > 0) {
                        if (abs(ast) == st.top()) {
                            destroy = true;
                            st.pop();
                            break;
                        } else if (abs(ast) > st.top()) {
                            st.pop();
                        } else {
                            destroy = true;
                            break;
                        }
                    }
                    if (!destroy) {
                        st.push(ast);
                    }
                }
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};