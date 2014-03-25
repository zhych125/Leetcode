/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    struct mycomp{
        bool operator()(Interval left,Interval right){
            return left.start<right.start;
        }
    } lessThan;
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if(intervals.empty()) {
            return ret;
        }
        sort(intervals.begin(),intervals.end(),lessThan);
        ret.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start<=ret.back().end) {
                ret.back().end=max(ret.back().end,intervals[i].end);
            }
            else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};