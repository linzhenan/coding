//Pow(x, n)

//Test Cases:
//8.88023
//3
//8.88023
//0
//8.88023
//- 1
//0.00001
//2147483647

double power(double x, int n) {
	if (!n)
		return 1.0;
	double tmp = power(x, n / 2);
	if (!(n & 0x01))
		return tmp * tmp;
	else
		return tmp * x * tmp;
}
double myPow(double x, int n) {
	if (!n)
		return 1.0;
	else if (n > 0)
		return power(x, n);
	else
		return 1.0 / power(x, n);
}