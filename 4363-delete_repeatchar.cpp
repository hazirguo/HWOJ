
#include "OJ.h"
#include <string.h>


/*
功能:计算字符串的最小周期。
原型：
    int GetMinPeriod(char *string);

输入参数：
    char * string：字符串。

返回值：
    int 字符串最小周期。

*/

int GetMinPeriod(char *inputstring)
{
	/*在这里实现功能*/
	int stringLen = strlen(inputstring);
	int i, j;

	for (i = 1; i < stringLen; i++)
	{
		if (stringLen % i == 0)
		{
			for (j = 1; j < stringLen/i; j++)
			{
				if (strncmp(inputstring, inputstring + j*i, i) != 0)	//not equal
					break;
			}
			if (j == stringLen / i)
				return i;
		}
	}

	return i;
}
