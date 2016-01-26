//Simplify Path

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs;
		for (auto i = path.begin(); i != path.end();) {
			i++;
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);
			if (!dir.empty() && dir != ".") {
				if (dir == "..") {
					if (!dirs.empty())
						dirs.pop_back();
				}
				else {
					dirs.push_back(dir);
				}
			}
			i = j;
		}
		string result;
		if (dirs.empty()) {
			result = "/";
		}
		else {
			for (auto dir : dirs)
				result += "/" + dir;
		}
		return result;
	}
};