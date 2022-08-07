int	compare(int *a, int *b);
void mediansort (int **ar, int(*cmp)(const int *,const int *),int left, int right);
int selectKth (int **ar, int(*cmp)(const int *,const int *),int k, int left, int right);
int partition (int **ar, int(*cmp)(const int *,const int *),int left, int right, int pivotIndex);
int	selectPivotIndex (int **ar, int left, int right);
