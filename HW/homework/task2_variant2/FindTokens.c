#include <stdio.h>
#include <math.h>
#define STATE_INIT 0
#define STATE_BAD_CHARS 1
#define STATE_NUM 2
#define STATE_STR 3

int count_num = 0, count_str = 0, state;

void set_state(int s) {
	switch (s)
	{
	case STATE_INIT:
		count_num = 0;
		count_str = 0;
		break;
	case STATE_BAD_CHARS:
		break;
	case STATE_NUM:
		count_num++;
		break;
	case STATE_STR:
		count_str++;
		break;
	}
	state = s;
}


void upd_state(char c) {
	switch (state)
	{
	case STATE_INIT:
		if (isalpha(c)) {
			set_state(STATE_STR);
		}
		else if (isdigit(c))
			set_state(STATE_NUM);
		else
			set_state(STATE_BAD_CHARS);
		break;
	case STATE_BAD_CHARS:
		if (isalpha(c)) {
			set_state(STATE_STR);
		}
		else if (isdigit(c))
			set_state(STATE_NUM);
		break;
	case STATE_NUM:
		if (!isdigit(c))
			set_state(STATE_BAD_CHARS);
		break;
	case STATE_STR:
		if (!isalpha(c))
			set_state(STATE_BAD_CHARS);
		break;
	}
}


int main() {
	set_state(STATE_INIT);
	char c[200];
	printf("Input string: ");
	scanf_s("%[^\n]s", c, 199);

	for (int i = 0; i < strlen(c); i++)
		upd_state(c[i]);

	printf("Count of numbers = %d\n", count_num);
	printf("Count of strings = %d\n", count_str);

	return 0;
}