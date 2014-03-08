class Solution:
    # @return an integer
    def reverse(self, x):
        result=0;
        flag=False
        if x<0:
            flag=True
            x=-x
        while x>0:
            result=result*10
            result=result+x%10
            x=x/10
        if flag:
            result=-result
        return result