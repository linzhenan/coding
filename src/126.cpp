#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	void dfs(vector<vector<string>>& res, vector<string>& path, unordered_map<string, bool>& visit,
		string& endWord, string& word, int level, int maxlevel) {
		path.push_back(word);
		if (level == maxlevel) {
			if (word == endWord)
				res.push_back(path);
			path.pop_back();
			return;
		}

		string copy = word;
		for (int i = 0; i < word.size(); i++) {
			for (int ch = 'a'; ch <= 'z'; ch++) {
				if (word[i] != ch) {
					word[i] = ch;
					if (visit.find(word) != visit.end() && !visit[word]) {
						visit[word] = true;
						dfs(res, path, visit, endWord, word, level + 1, maxlevel);
						visit[word] = false;
					}
					word = copy;
				}
			}
		}
		path.pop_back();
	}
	vector<vector<string>> findLaddersBFSandDFS(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string>> res;
		vector<string> path;
		if (beginWord == endWord) {
			path.push_back(beginWord);
			res.push_back(path);
			return res;
		}
		if (wordList.find(beginWord) != wordList.end())
			wordList.erase(beginWord);
		if (wordList.find(endWord) == wordList.end())
			wordList.insert(endWord);

		unordered_map<string, bool> visit;
		for (auto e : wordList)
			visit[e] = false;

		queue<string> qwords;
		queue<int> qlevel;
		qwords.push(beginWord);
		qlevel.push(1);

		int minlevel = -1;
		while (!qwords.empty()) {
			string word = qwords.front();
			int level = qlevel.front();
			qwords.pop();
			qlevel.pop();

			if (word == endWord) {
				minlevel = level;
				break;
			}

			string copy = word;
			for (int i = 0; i < word.size(); i++) {
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (word[i] != ch) {
						word[i] = ch;
						if (wordList.find(word) != wordList.end() && !visit[word]) {
							visit[word] = true;
							qwords.push(word);
							qlevel.push(level + 1);
						}
						word = copy;
					}
				}
			}
		}

		if (minlevel != -1) {
			for (auto& e : visit)
				e.second = false;
			dfs(res, path, visit, endWord, beginWord, 1, minlevel);
		}

		return res;
	}

	void dfsRec(vector<vector<string>>& res, vector<string>& path,
		string& word, string& beginWord, unordered_map<string, vector<string>>& father) {
		path.push_back(word);
		if (word == beginWord) {
			res.push_back(path);
			reverse(res.back().begin(), res.back().end());
		}
		else {
			for (auto& fword : father[word])
				dfsRec(res, path, fword, beginWord, father);
		}
		path.pop_back();
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string>> res;
		vector<string> path;

		unordered_map<string, vector<string>> father;

		unordered_map<string, bool> visit;
		for (auto word : wordList)
			visit[word] = false;
		visit[endWord] = false;

		vector<string> curr;
		vector<string> next;

		curr.push_back(beginWord);
		bool found = false;
		int visited = 0;//will be ETL without it!
		//"cet"
		//"ism"
		//["kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob"]
		while (curr.size() && !found && visited < visit.size()) {
			for (auto word : curr) {
				visit[word] = true;
				visited++;
				cout << word << " ";
			}
			cout << endl;
			for (auto word : curr) {
				string copy = word;
				for (int i = 0; i < word.size(); i++) {
					for (char ch = 'a'; ch <= 'z'; ch++) {
						if (word[i] != ch) {
							word[i] = ch;
							if (visit.find(word) != visit.end() && !visit[word]) {
								if (word == endWord)
									found = true;
								father[word].push_back(copy);
								if (find(next.begin(), next.end(), word) == next.end())//will have repeated results without it!
									next.push_back(word);
								//output [["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
								//expect [["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
							}
							word = copy;
						}
					}
				}
			}
			curr.clear();
			swap(curr, next);
		}

		if (found)
			dfsRec(res, path, endWord, beginWord, father);
		return res;
	}
};

void main() {
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");

	Solution slu;
	vector<vector<string>> res = slu.findLadders("red", "tax", dict);
}