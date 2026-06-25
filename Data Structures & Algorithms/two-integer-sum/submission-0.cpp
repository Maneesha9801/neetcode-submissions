class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> answer;
        for(int i = 0 ; i < nums.size(); i++){
            int complement = target - nums[i];

            if (answer.find(complement)!= answer.end()){
                return {answer[complement], i};
            }
            answer[nums[i]] = i;
        }
        return {};
    }
};


