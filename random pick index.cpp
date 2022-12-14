
class Solution {
public:
    Solution(vector<int> nums) : nums_(nums) {
        
    }
    
    int pick(int target) {
        auto reservoir = -1;
        auto n = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != target) {
                continue;
            }
            if (rand() % ++n == 0) {
                reservoir = i;
            }
        }
        return reservoir;
    }

private:
    const vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
