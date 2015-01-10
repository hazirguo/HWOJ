#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "oj.h"

void CalcNN(int n, char *pOut)
{
	char res[1000] = { 0 };
	int i, j=1;
	int cur;
	int carry = 0;
	res[0] = 1+'0';

	for (i = 2; i <= n; i++)
	{
		for (j = 0; res[j] != '\0'; j++)
		{
			cur = (res[j] - '0') * i + carry;
			res[j] = (cur % 10) + '0';
			carry = cur / 10;
		}
		while (carry != 0)
		{
			res[j++] = (carry % 10) + '0';
			carry /= 10;
		}
	}
	i = 0;
	while (j--)
	{
		pOut[i++] = res[j];
	}
	pOut[i] = '\0';
	return;
}