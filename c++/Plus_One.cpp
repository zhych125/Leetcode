class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--) {
            int num=carry+digits[i];
            digits[i]=num%10;
            carry=num/10;
        }
        if(carry) {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};