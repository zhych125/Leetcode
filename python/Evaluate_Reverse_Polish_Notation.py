class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack=[]
        for i in tokens:
            if i=="+":
                op2=stack.pop()
                op1=stack.pop()
                stack.append(op1+op2)
            elif i=="-":
                op2=stack.pop()
                op1=stack.pop()
                stack.append(op1-op2)
            elif i=="*":
                op2=stack.pop()
                op1=stack.pop()
                stack.append(op1*op2)
            elif i=="/":
                op2=stack.pop()
                op1=stack.pop()
                stack.append(int(op1*1.0/op2)) #Python's divsion is different from c++
            else:
                stack.append(int(i))
        return stack.pop()