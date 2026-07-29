class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (string email : emails) {
            int at = email.find('@');

            string local = email.substr(0, at);
            string domain = email.substr(at + 1);

            string temp = "";
            for (char c : local) {
                if (c == '+') break;
                if (c == '.') continue;
                temp += c;
            }

            st.insert(temp + "@" + domain);
        }

        return st.size();
    }
};