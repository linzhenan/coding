//The Skyline Problem

#define LEFT 0
#define RIGHT 1
#define HEIGHT 2
class XEvent {
public:
	int index;
	int x;
	int side;
	XEvent(int idx, int pos, int s) : index(idx), x(pos), side(s) {}
};
class Solution {
private:
	vector<XEvent> events;
	static bool compareXEvent(const XEvent& e1, const XEvent& e2) {
		if (e1.x != e2.x)
			return e1.x < e2.x;
		else
			return e1.side < e2.side;
	}
	set<int> activeBuildings;
	vector<pair<int, int>> skyline;
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		for (int i = 0; i < buildings.size(); i++) {
			events.push_back(XEvent(i, buildings[i][LEFT], LEFT));
			events.push_back(XEvent(i, buildings[i][RIGHT], RIGHT));
		}
		sort(events.begin(), events.end(), compareXEvent);

		int currHeight = 0;
		for (int i = 0; i < events.size(); i++) {
			int x = events[i].x;
			if (events[i].side == LEFT) {
				int newHeight = buildings[events[i].index][HEIGHT];
				activeBuildings.insert(events[i].index);
				while (i + 1 < events.size() && events[i + 1].x == x && events[i + 1].side == LEFT) {
					i++;
					newHeight = max(newHeight, buildings[events[i].index][HEIGHT]);
					activeBuildings.insert(events[i].index);
				}
				if (newHeight > currHeight) {
					currHeight = newHeight;
					skyline.push_back(pair<int, int>(x, currHeight));
				}
			}
			else {
				int newHeight = buildings[events[i].index][HEIGHT];
				activeBuildings.erase(events[i].index);
				while (i + 1 < events.size() && events[i + 1].x == x && events[i + 1].side == RIGHT) {
					i++;
					newHeight = max(newHeight, buildings[events[i].index][HEIGHT]);
					activeBuildings.erase(events[i].index);
				}
				if (newHeight == currHeight) {
					int maxHeight = 0;
					for (auto index : activeBuildings)
						maxHeight = max(maxHeight, buildings[index][HEIGHT]);
					if (maxHeight < currHeight) {
						currHeight = maxHeight;
						skyline.push_back(pair<int, int>(x, currHeight));
					}
				}
			}
		}
		return skyline;
	}
};