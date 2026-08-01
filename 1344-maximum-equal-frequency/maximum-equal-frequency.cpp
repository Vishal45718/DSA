class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;      
        unordered_map<int, int> freqCnt;  

        int ans = 0;
        int maxFreq = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (cnt[x] > 0)
                freqCnt[cnt[x]]--;

            cnt[x]++;
            freqCnt[cnt[x]]++;

            maxFreq = max(maxFreq, cnt[x]);

            int n = i + 1;

            if (maxFreq == 1) {
                ans = n;
            }

            else if (maxFreq * freqCnt[maxFreq] +
                         (maxFreq - 1) * freqCnt[maxFreq - 1] == n &&
                     freqCnt[maxFreq] == 1) {
                ans = n;
            }

            else if (maxFreq * freqCnt[maxFreq] + 1 == n &&
                     freqCnt[1] == 1) {
                ans = n;
            }
        }

        return ans;
    }
};