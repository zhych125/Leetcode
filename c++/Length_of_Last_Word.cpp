class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=strlen(s);
        int lastLen=0;
        while(s[len-1]==' '&&len>=0) len--;
        for(int i=len-1;i>=0;i--) {
            if(s[i]!=' ') {
                lastLen++;
            }
            else break;
        }
        return lastLen;
    }
};