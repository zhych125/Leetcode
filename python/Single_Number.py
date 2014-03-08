class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        sum=0
        for elem in A:
            sum=sum^elem;
        return sum