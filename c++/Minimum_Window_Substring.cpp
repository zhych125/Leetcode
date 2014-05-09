class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty()||T.empty()) {
            return "";
        }
        int expected[256]={0};
        int received[256]={0};
        for(int i=0;i<T.size();i++) {
            expected[T[i]]++;
        }
        int wStart=0;
        int wEnd=0;
        int minStart=0;
        int minWindow=INT_MAX;
        int appeared=0;
        for(wEnd=0;wEnd<S.size();wEnd++) {
            if(expected[S[wEnd]]>0) {
                received[S[wEnd]]++;
                if(received[S[wEnd]]<=expected[S[wEnd]]) {
                    appeared++;
                }
            }
            if(appeared==T.size()) {
                while(expected[S[wStart]]==0||received[S[wStart]]>expected[S[wStart]]) {
                    received[S[wStart]]--;
                    wStart++;
                }
                if(wEnd-wStart+1<minWindow) {
                    minWindow=wEnd-wStart+1;
                    minStart=wStart;
                }
            }
        }
        return minWindow==INT_MAX?"":S.substr(minStart,minWindow);
    }
};