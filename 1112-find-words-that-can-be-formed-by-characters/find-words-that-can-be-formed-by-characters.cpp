class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);

        for (char c : chars) {
            freq[c - 'a']++;
        }

        int ans = 0;

        for (string word : words) {
            vector<int> temp(26, 0);
            bool possible = true;


            for (char c : word) {
                temp[c - 'a']++;
                if (temp[c - 'a'] > freq[c - 'a']) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans += word.length();
            }
        }

        return ans;
    }
};