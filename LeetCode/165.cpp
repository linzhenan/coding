//Compare Version Numbers

class Solution {
public:
	int getSubVersion(string v, int& pos) {
		stringstream ss;
		while (pos < v.size() && v[pos] != '.')
			ss << v[pos++];
		pos++;
		int subv = 0;
		ss >> subv;
		return subv;
	}
	int compareVersion(string version1, string version2) {
		int pos1 = 0;
		int pos2 = 0;
		while (pos1 < version1.size() || pos2 < version2.size()) {
			int subVer1 = getSubVersion(version1, pos1);
			int subVer2 = getSubVersion(version2, pos2);
			if (subVer1 > subVer2)
				return 1;
			if (subVer1 < subVer2)
				return -1;
		}
		return 0;
	}
};