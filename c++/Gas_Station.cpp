class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty()||cost.empty()) {
            return 0;
        }
        int total_sum=0;
        int start=0;
        int current_sum=0;
        for(int i=0;i<gas.size();i++) {
            total_sum+=gas[i]-cost[i];
            current_sum+=gas[i]-cost[i];
            if(current_sum<0) {
                start=i+1;
                current_sum=0;
            }
        }
        if(total_sum>=0) {
            return start;
        }
        else return -1;
    }
};