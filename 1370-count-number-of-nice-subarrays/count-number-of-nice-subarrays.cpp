class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;

        int oddCount = 0;
        int ans = 0;

        for(int num : nums)
        {
            if(num % 2 == 1)
            {
                oddCount++;
            }

            if(freq.count(oddCount - k))
            {
                ans += freq[oddCount - k];
            }

            freq[oddCount]++;
        }

        return ans;
    }
};