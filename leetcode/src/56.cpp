//Merge Intervals

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval i1, Interval i2) {
    return i1.start < i2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> results;
        if (intervals.size() == 0)
            return results;
        sort(intervals.begin(), intervals.end(), cmp);
        results.push_back(intervals[0]);
        for (int i = 0; i < intervals.size(); i++) {
            Interval last = results.back();
            if (intervals[i].start > last.end) {
                results.push_back(intervals[i]);
            }
            else {
                results.pop_back();
                last.end = max(last.end, intervals[i].end);
                results.push_back(last);
            }
        }
        return results;
    }
};