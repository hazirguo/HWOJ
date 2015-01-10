
#include "OJ.h"
#include <string.h>


/*
����:�����ַ�������С���ڡ�
ԭ�ͣ�
    int GetMinPeriod(char *string);

���������
    char * string���ַ�����

����ֵ��
    int �ַ�����С���ڡ�

*/

int GetMinPeriod(char *inputstring)
{
	/*������ʵ�ֹ���*/
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
