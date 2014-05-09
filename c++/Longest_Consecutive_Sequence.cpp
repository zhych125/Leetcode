class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty()) {
            return 0;
        }
        unordered_set<int> numSet;
        for(int i=0;i<num.size();i++) {
            numSet.insert(num[i]);
        }
        int longest=0;
        while(numSet.size()) {
            int a=*numSet.begin();
            numSet.erase(a);
            int size=1;
            int b=a;
            while(numSet.find(b+1)!=numSet.end()) {
                b++;
                numSet.erase(b);
                size++;
            }
            b=a;
            while(numSet.find(b-1)!=numSet.end()) {
                b--;
                numSet.erase(b);
                size++;
            }
            if(longest<size) {
                longest=size;
            }
        }
        return longest;
    }
};