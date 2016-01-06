//Valid Number

//What about state machine?

bool isNumber(char* s) {
	char* endptr;
	strtod(s, &endptr);
	if (endptr == s)
		return false;
	for (; *endptr; endptr++)
		if (*endptr != ' ')
			return false;
	return true;
}