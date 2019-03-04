/*
 * =====================================================================================
 *
 *       Filename:  atoi.c
 *
 *    Description:  atoi implementation.
 *
 *        Version:  1.0
 *        Created:  11/24/2016 12:38:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (), prakashkurup7@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Function to implement atoi */
int Atoi(const char *str)
{
	int sign = 1;
	int res = 0;
	int i = 0;

	/* If space occurs, move to the next char */
	while (str[i] == ' ') {
		i++;
	}

	/* Check for + and - sign*/
	if (str[i] == '-' || str[i] == '+') {
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}

	/* Store res for number characters */
	while (str[i] >= '0' && str[i] <= '9') {
		res = res * 10 + (str[i++] - '0');
	}

	return res * sign;
}

/* Function to check test cases */
bool testCases(const char *str)
{
	if (atoi(str) == Atoi(str)) {
		return true;
	} else {
		return false;
	}
}

int main(void)
{
#if 0
	int test_case = 0;

	const char *str[10] = {"12345", "  12345", "number 12345", "12345 number", "-12345", "- 12345", "+-12345", "-+12345", "12 345", "+12345"};
	int count = sizeof(str) / sizeof(str[0]);

	while (test_case < count) {
		printf("Running test case %d:'%s'\n", test_case, str[test_case]);
		testCases(str[test_case]) ? puts("PASSED!") : puts("FAILED :(");
		puts("\r");
		test_case++;
	}
#endif

#if 1
	char *p = "1234";

	int i;
	i = Atoi(p);

	printf("i %d\n",i);

#endif

	return 0;
}

