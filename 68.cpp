//Text Justification

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int i = 0;
		while (i < words.size()) {
			vector<string> candidate;
			int width = 0;
			int count = 0;
			do {
				candidate.push_back(words[i]);
				width += words[i].size();
				count++;
				i++;
			} while (i < words.size() && width + count + words[i].size() <= maxWidth);
			int blank = maxWidth - width;
			string temp;
			if (count == 1) {
				temp = candidate[0];
				for (int k = temp.size(); k < maxWidth; k++)
					temp += ' ';
			}
			else {
				if (i < words.size()) {
					int mod = blank % (count - 1);
					for (int j = 0; j < count; j++) {
						temp += candidate[j];
						if (j < count - 1) {
							for (int k = 0; k < blank / (count - 1); k++)
								temp += ' ';
							if (j < mod)
								temp += ' ';
						}
					}
				}
				else {//the last line
					//Why the following case:
					//["What","must","be","shall","be."]
					//12
					//expected answer is:
					//["What must be","shall be.   "]
					//rather than:
					//["What must be","shall    be."]
					for (int j = 0; j < count; j++)
						temp += candidate[j] + ' ';
					for (int k = temp.size(); k < maxWidth; k++)
						temp += ' ';
				}
			}
			result.push_back(temp);
		}
		return result;
	}
};
