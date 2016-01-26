int divide(int dividend, int divisor) {
	int ans = 0;
	int sign = 0;
	int divisor_w;
	int ans_w;

	if (divisor == 0) {//what's the result when divisor = 0?
		return 0x7FFFFFFF;
	}
	else if (divisor == 1) {
		return dividend;
	}
	else if (divisor == -1) {
		if (dividend == 0x80000000)
			return 0x7FFFFFFF;
		else
			return -dividend;
	}
	else if (divisor == 0x80000000) {
		if (dividend == 0x80000000)
			return 1;
		else
			return 0;
	}

	if (dividend == 0) {
		return 0;
	}
	else if (dividend < 0) {
		if (divisor > 0) {
			sign = 1;
			divisor = -divisor;//dividend < 0, divisor < 0
		}

		divisor_w = divisor;
		ans_w = 1;
		while ((divisor_w << 1) < 0 && dividend <= (divisor_w << 1)) {
			divisor_w <<= 1;
			ans_w <<= 1;
		}
		while (dividend != 0 && dividend <= divisor_w) {
			ans += ans_w;
			dividend -= divisor_w;
			while (dividend != 0 && dividend > divisor_w) {
				divisor_w >>= 1;
				ans_w >>= 1;
			}
		}
	}
	else {
		if (divisor < 0) {
			sign = 1;
			divisor = -divisor;//dividend > 0, divisor > 0
		}
		divisor_w = divisor;
		ans_w = 1;
		while ((divisor_w << 1) > 0 && dividend >= (divisor_w << 1)) {
			divisor_w <<= 1;
			ans_w <<= 1;
		}
		while (dividend != 0 && dividend >= divisor_w) {
			ans += ans_w;
			dividend -= divisor_w;
			while (dividend != 0 && dividend < divisor_w) {
				divisor_w >>= 1;
				ans_w >>= 1;
			}
		}
	}

	if (sign)
		ans = -ans;
	return ans;
}