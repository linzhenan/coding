//Fraction to Recurring Decimal

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long int num;
		long long int den;
		int sign = 0;
		if (numerator < 0) {
			sign = !sign;
			num = numerator;
			num = -num;//note
		}
		else {
			num = numerator;
		}
		if (denominator < 0) {
			sign = !sign;
			den = denominator;
			den = -den;//note
		}
		else {
			den = denominator;
		}
		if (num == 0)
			return "0";
		stringstream ss;
		if (sign)
			ss << '-';
		long long int q = num / den;
		long long int r = num % den;
		ss << q;

		unordered_map<long, int> map;
		string str;
		if (r) {
			ss << '.';
			map[r] = ss.str().size();
		}
		else {
			str = ss.str();
		}
		while (r) {
			r = r * 10;
			q = r / den;
			r = r % den;
			ss << q;
			if (map.find(r) != map.end()) {
				str += ss.str().substr(0, map[r]) + '(' + ss.str().substr(map[r]) + ')';
				break;
			}
			else if (r == 0) {
				str = ss.str();
				break;
			}
			else {
				map[r] = ss.str().size();//note!
			}
		}
		return str;
	}
};