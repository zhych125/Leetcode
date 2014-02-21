class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        if(numbers.empty()) {
            return ret;
        }
        unordered_map<int,int> dict;
        for(int i=0;i<numbers.size();i++) {
            if(dict.find(numbers[i])==dict.end()) {
                dict[target-numbers[i]]=i;
            }
            else {
                ret.push_back(dict[numbers[i]]+1);
                ret.push_back(i+1);
                return ret;
            }
        }
        return ret;
    }
};