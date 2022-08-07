#include "f.h"
#define N 10

main()
{
	int	i;
	int ar[]={1,3,2,4,5,10,9};

	i = 0;
	mediansort(&ar, compare, 0, 6);
	while(i < 6)
	{
		printf("%d\n", ar[i]);
		i++;
	}  
}

int	compare(int *a, int *b)
{
	int	aa;
	int	bb;

	aa = (int) (a);
	bb = (int) (b);
	if (aa < bb)
		return (0);
	return (1);
}