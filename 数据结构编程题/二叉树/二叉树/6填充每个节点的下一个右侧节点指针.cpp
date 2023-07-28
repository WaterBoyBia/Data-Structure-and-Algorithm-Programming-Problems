#include <stdio.h>
#include <math.h>
#include <iostream>
#define MAXSIZE 1000
using namespace std;

int fun_log2(int x)
{
	int ret = 0;
	while(x/2 != 0)
	{
		x = x/2;
		ret++;
	}
	return ret;
}
int main(int argc, char **argv)
{
	int data[MAXSIZE] = {0}, j, e=99,len = 0;
//	scanf("%d", &e);
	cin>>e;
	if(e == 99) data[len++] = 250;
	else 
	{
		data[len++] = e;
		j = getchar();
		while(j != '\n')
		{
			e = 99;
			scanf("%d", &e);
			if(e == 99)
			{
				for(int i = 4; i > 0; i--) getchar();
				data[len++] = 255;
			}
			else data[len++] = e;
			j = getchar();
		}
	}
	int depth = fun_log2(len) + 1;
	if(data[0] != 250)
	{
		for(int i = 0; i < depth; i++)
		{
			for(int j = (int)pow(2, i) - 1; j < (int)pow(2, i+1) - 1; j++)
			{
				if(data[j] != 255) printf("%d,", data[j]);
				else if(j != (int)pow(2, i) - 1) printf("#,");
			}
			if(i < depth - 1) printf("#,");
		}
		printf("#");
	}
	return 0;
}

