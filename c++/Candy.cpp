class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty()) {
            return 0;
        }
        vector<int> candy(ratings.size(),1);
        for(int i=1;i<ratings.size();i++) {
            if(ratings[i]>ratings[i-1]) {
                candy[i]=candy[i-1]+1;
            }
        }
        int sum=0;
        for(int j=ratings.size()-2;j>=0;j--) {
            if(ratings[j]>ratings[j+1]) {
                candy[j]=max(candy[j],candy[j+1]+1);
            }
            sum+=candy[j];
        }
        sum+=candy[ratings.size()-1];
        return sum;
    }
};