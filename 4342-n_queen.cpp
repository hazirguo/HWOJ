
#include "OJ.h"
#include <math.h>
#include <stdlib.h>

/*
功能: 求解放置8皇后方案的个数。
输入：
    无
返回：
    int：放置8皇后方案的个数
*/

#define MAX_NUM	  10000000

bool isVaild(int x, int y, int n, int *queen)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (queen[i] == y || abs(i - x) == abs(queen[i] - y))
			return false;
	}
	return true;
}

int PlaceQueenMethodNum(int n)
{
	int i = 0, curQueen, j = 0;
	int total = 0;
	int *queenArr = (int *)malloc(n*sizeof(int));

	for (j = 0; j < n; j++)
		queenArr[j] = MAX_NUM;
	
	for (curQueen = 0; curQueen < n;)
	{
		while (i<n)
		{
			if (isVaild(curQueen, i, n, queenArr))
			{
				queenArr[curQueen] = i;
				i = 0;
				break;
			}
			else
			{
				i++;
			}
		}

		if (queenArr[curQueen] == MAX_NUM)
		{
			if (curQueen == 0)
				break;
			else
			{
				curQueen--;
				i = queenArr[curQueen] + 1;
				queenArr[curQueen] = MAX_NUM;
				continue;
			}
		}

		if (curQueen == n - 1)
		{
			total++;
			i = queenArr[curQueen] + 1;
			queenArr[curQueen] = MAX_NUM;
			continue;
		}

		curQueen++;
	}

	return total;
}