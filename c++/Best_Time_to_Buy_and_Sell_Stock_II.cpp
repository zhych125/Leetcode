class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) {
            return 0;
        }
        int ret=0;
        int lowest=prices[0];
        int highest=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]<highest) {
                ret+=highest-lowest;
                highest=lowest=prices[i];
            }
            else {
                highest=prices[i];
            }
        }
        ret+=highest-lowest;
        return ret;
    }
};