class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(*needle=='\0') {
            return haystack;
        }
        while(*haystack!='\0') {
            char *h=haystack;
            char *n=needle;
            while(*h==*n) {
                h++;
                n++;
                if(*n=='\0') {
                    return haystack;
                }
            }
            if(*h=='\0') {
                return NULL;
            }
            haystack++;
        }
        return NULL;
    }
};