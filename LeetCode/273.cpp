#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	string digit2word(int digit) {
		switch (digit) {
		case 1: return "One";
		case 2: return "Two";
		case 3: return "Three";
		case 4: return "Four";
		case 5: return "Five";
		case 6: return "Six";
		case 7: return "Seven";
		case 8: return "Eight";
		case 9: return "Nine";
		case 10: return "Ten";
		case 11: return "Eleven";
		case 12: return "Twelve";
		case 13: return "Thirteen";
		case 14: return "Fourteen";
		case 15: return "Fifteen";
		case 16: return "Sixteen";
		case 17: return "Seventeen";
		case 18: return "Eighteen";
		case 19: return "Nineteen";
		case 20: return "Twenty";
		case 30: return "Thirty";
		case 40: return "Forty";
		case 50: return "Fifty";
		case 60: return "Sixty";
		case 70: return "Seventy";
		case 80: return "Eighty";
		case 90: return "Ninety";
		}
		return "";
	}
	string number2Words(int num) {
		string words;
		if (num > 999 || num < 1)
			return words;

		int tmp = num / 100;
		num %= 100;
		if (tmp) words += digit2word(tmp) + " Hundred ";

		if (num) {
			if (num < 20)
				words += digit2word(num);
			else
				words += digit2word(num / 10 * 10) + " " + digit2word(num % 10);
		}
		if (words[words.size() - 1] == ' ')
			words = words.substr(0, words.size() - 1);
		return words;
	}
	string numberToWords(int num) {
		string words;

		if (!num)
			words = "Zero";

		int tmp = num / 1000000000;
		num %= 1000000000;
		if (tmp) words += number2Words(tmp) + " Billion ";

		tmp = num / 1000000;
		num %= 1000000;
		if (tmp) words += number2Words(tmp) + " Million ";

		tmp = num / 1000;
		num %= 1000;
		if (tmp) words += number2Words(tmp) + " Thousand ";

		if (num) words += number2Words(num);

		if (words[words.size() - 1] == ' ')
			words = words.substr(0, words.size() - 1);
		return words;
	}
};
int main() {
	int num = 0xD4A50FFF;
	num = 1;

	if (num < 999999999999) {
		num++;
	}
}