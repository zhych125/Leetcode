class Solution:
    # @return an integer
    def numTrees(self, n):
        num=[0 for i in range(n+1)]
        num[0]=1
        for nodeNum in range(1,n+1):
            for leftNum in range(nodeNum) :
                num[nodeNum]+= num[leftNum]*num[nodeNum-leftNum-1]
        return num[n]
        