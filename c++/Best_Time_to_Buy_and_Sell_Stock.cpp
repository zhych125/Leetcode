class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) {
            return 0;
        }
        int low=prices[0];
        int maximum=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]>low) {
                maximum=max(maximum,prices[i]-low);
            }
            if(prices[i]<low) {
                low=prices[i];
            }
        }
        return maximum;
    }
};