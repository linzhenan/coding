//Wildcard Matching

bool isMatch(char* s, char* p) {
	bool star = false;
	char *str, *ptr;
	for (str = s, ptr = p; *str != '\0';) {
		switch (*ptr) {
		case '?':
			str++;
			ptr++;
			break;
		case '*':
			star = true;
			while (*ptr == '*')
				ptr++;
			if (*ptr == '\0')
				return true;
			p = ptr;
			s = str;
			break;
		default:
			if (*str != *ptr) {
				if (!star)
					return false;
				s++;
				str = s;
				ptr = p;
			}
			else {
				str++;
				ptr++;
			}
			break;
		}
	}
	while (*ptr == '*')
		ptr++;
	return *ptr == '\0';
}