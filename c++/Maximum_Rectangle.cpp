class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()||matrix[0].empty()) {
            return 0;
        }
        vector<vector<int> > histogram(matrix.size(),vector<int> (matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j]!='0') {
                    histogram[i][j]=i==0?1:histogram[i-1][j]+1;
                }
            }
        }
        
        int maximum=0;
        for(int i=0;i<histogram.size();i++) {
            stack<int> histack;
            histogram[i].push_back(0);
            int j=0;
            while(j<histogram[i].size()){
                if(histack.empty()||histogram[i][j]>histogram[i][histack.top()]) {
                    histack.push(j);
                    j++;
                }
                else {
                    int height=histogram[i][histack.top()];
                    histack.pop();
                    maximum=max(maximum,height*(histack.empty()?j:(j-histack.top()-1)));
                }
            }
        }
        return maximum;
    }
};