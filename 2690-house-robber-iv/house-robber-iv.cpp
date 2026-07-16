class Solution {
public:
    bool check(vector<int>& nums, int k, int cap) {
        int cnt = 0;
        int i = 0;
        
        while (i < nums.size()) {
            if (nums[i] <= cap) {
                cnt++;
                i += 2; 
            } else {
                i++;
            }
        }
        
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
