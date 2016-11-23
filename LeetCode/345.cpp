class Solution {
public:
	bool isVowels(char ch) {
		switch (ch) {
		case 'a': return true;
		case 'e': return true;
		case 'i': return true;
		case 'o': return true;
		case 'u': return true;
		case 'A': return true;
		case 'E': return true;
		case 'I': return true;
		case 'O': return true;
		case 'U': return true;
		}
		return false;
	}
	string reverseVowels(string s) {
		int i = 0;
		int j = s.size();
		j--;
		while (i < j) {
			while (i < j && !isVowels(s[i]))
				i++;
			while (i < j && !isVowels(s[j]))
				j--;
			char ch = s[i];
			s[i] = s[j];
			s[j] = ch;
			i++;
			j--;
		}
		return s;
	}
};