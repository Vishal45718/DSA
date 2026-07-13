class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inBlock = false;
        string curr;

        for (string &line : source) {
            int n = line.size();

            if (!inBlock)
                curr.clear();

            for (int i = 0; i < n; i++) {
                if (!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
                    inBlock = true;
                    i++; // Skip '*'
                }
                else if (inBlock && i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
                    inBlock = false;
                    i++; // Skip '/'
                }
                else if (!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
                    break; // Ignore rest of line
                }
                else if (!inBlock) {
                    curr.push_back(line[i]);
                }
            }

            if (!inBlock && !curr.empty()) {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};