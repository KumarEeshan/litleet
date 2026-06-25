class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
    
    int n = nums.size();
    vector<int> count(2 * n + 1, 0);
    int offset = n;
        
    count[offset] = 1;
    int curr_sum = 0;
    long long smaller_count = 0;
    long long ans = 0;
        
    for (int num : nums) {
        if (num == target) {
            smaller_count += count[curr_sum + offset];
            curr_sum++;
        } else {
            curr_sum--;
        smaller_count -= count[curr_sum + offset];
            
        }
    ans += smaller_count;
        count[curr_sum + offset]++;
    }
        
    return ans;
}

};