//Multiply Strings

char* multiply(char* num1, char* num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if (len1 == 1 && num1[0] == '0' ||
		len2 == 1 && num2[0] == '0')
		return "0";

	if (len2 < len1) {
		char *p = num1;
		num1 = num2;
		num2 = p;

		int tmp = len1;
		len1 = len2;
		len2 = tmp;
	}
	int len = 1 + len1 + len2 + 1;//for 'sign' and '\0'
	char *num = malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++)
		num[i] = '0';
	int i, j, k;
	for (i = len1 - 1; i >= 0; i--) {
		for (j = len2 - 1; j >= 0; j--) {
			int mul = (num1[i] - '0') * (num2[j] - '0');
			k = (len1 - 1 - i) + (len2 - 1 - j);
			do {
				mul += num[k] - '0';
				num[k] = '0' + mul % 10;
				mul = mul / 10;
				k++;
			} while (mul);
		}
	}
	num[k] = '\0';
	i = 0;
	j = k - 1;
	while (i < j) {
		char tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
		i++;
		j--;
	}
	return num;
}