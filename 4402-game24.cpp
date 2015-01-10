/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int operate(int a, int op, int b)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

bool Game24Points(int a, int b, int c, int d)
{
	int arr[] = { a, b, c, d };
	
	int i, j, k;
	int res;

	vector<int> vNumbers;
	vNumbers.push_back(a); vNumbers.push_back(b); vNumbers.push_back(c); vNumbers.push_back(d);

	//列出所有数的排列
	while (next_permutation(vNumbers.begin(), vNumbers.end()))
	{
		a = vNumbers[0]; b = vNumbers[1]; c = vNumbers[2]; d = vNumbers[3];
		//在四个数中插入三个运算符，共有64种情况
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				for (k = 0; k < 4; k++)
				{
					res = operate(operate(operate(a, i, b), j, c), k, d);
					if (res == 24)
						return true;
				}
			}
		}
	}

	return false;
}


