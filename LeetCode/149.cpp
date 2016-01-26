/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3)
            return n;
        unordered_map<double, int> map;
        int result = 0;
        for (int i = 0; i < n; i++) {
            map.clear();//note!
            int samePointNum = 0;
            int sameLineMaxNum = 1;
            for (int j = i + 1; j < n; j++) {
                double slope;
                if (points[i].x == points[j].x) {
                    slope = std::numeric_limits<double>::infinity();
                    if (points[i].y == points[j].y) {
                        samePointNum++;
                        continue;
                    }
                }
                else {
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                int count;
                if (map.find(slope) != map.end()) {
                    count = ++map[slope];
                }
                else {
                    count = 2;
                    map[slope] = 2;
                }
                if (sameLineMaxNum < count)
                    sameLineMaxNum = count;
            }
            result = max(result, sameLineMaxNum + samePointNum);
        }
        return result;
    }
};