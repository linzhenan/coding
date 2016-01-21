//Insert Interval

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> results;
        if (intervals.size() == 0) {
            results.push_back(newInterval);
            return results;
        }
        
        stack<Interval> s;
        for (int i = 0; i < intervals.size(); i++)
            if (intervals[i].end < newInterval.start)
                results.push_back(intervals[i]);
            else
                break;
        for (int i = intervals.size() - 1; i >= 0; i--)
            if (intervals[i].start > newInterval.end)
                s.push(intervals[i]);
            else
                break;
        int leftIndex = results.size();
        int rightIndex = intervals.size() - s.size() - 1;
        Interval temp;
        if (leftIndex > rightIndex) {
            temp = newInterval;
        }
        else {
            temp.start = min(intervals[leftIndex].start, newInterval.start);
            temp.end = max(intervals[rightIndex].end, newInterval.end);
        }
        results.push_back(temp);
        while (!s.empty()) {
            temp = s.top();
            s.pop();
            results.push_back(temp);
        }
        return results;
    }
};