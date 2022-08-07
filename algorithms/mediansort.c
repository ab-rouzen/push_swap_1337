/**
 * In linear time, group the subarray ar[left, right] around a pivot
 * element pivot=ar[pivotIndex] by storing pivot into its proper
 * location, store, within the subarray (whose location is returned
 * by this function) and ensuring that all ar[left,store) <= pivot and
 * all ar[store+1,right] > pivot.
 */

#include "f.h"

int partition (void **ar, int(*cmp)(const void *,const void *),
               int left, int right, int pivotIndex) {
  int idx, store;
  void *pivot = ar[pivotIndex];

  /* move pivot to the end of the array */
  void *tmp = ar[right];
  ar[right] = ar[pivotIndex];
  ar[pivotIndex] = tmp;

  /* all values <= pivot are moved to front of array and pivot inserted
   * just after them. */
  store = left;
  for (idx = left; idx < right; idx++) {
    if (cmp(ar[idx], pivot) <= 0) {
      tmp = ar[idx];
      ar[idx] = ar[store];
      ar[store] = tmp;
      store++;
    }
  }

  tmp = ar[right];
  ar[right] = ar[store];
  ar[store] = tmp;
  return store;
}
/**
 * Average-case linear time recursive algorithm to find position of kth
 * element in ar, which is modified as this computation proceeds.
 * Note 1 <= k <= right-left+1. The comparison function, cmp, is
 * needed to properly compare elements. Worst-case is quadratic, O(n^2).
 */
int selectKth (void **ar, int(*cmp)(const void *,const void *),
               int k, int left, int right) {
  int idx = selectPivotIndex (ar, left, right);
  int pivotIndex = partition (ar, cmp, left, right, idx);
  if (left+k-1 == pivotIndex) { return pivotIndex; }

  /* continue the loop, narrowing the range as appropriate. If we are within
   * the left-hand side of the pivot then k can stay the same. */
  if (left+k-1 < pivotIndex) {
    return selectKth (ar, cmp, k, left, pivotIndex-1);
  } else {
    return selectKth (ar, cmp, k - (pivotIndex-left+1), pivotIndex+1, right);
  }
}

void mediansort (void **ar, int(*cmp)(const void *,const void *),
                 int left, int right) {
  /* if the subarray to be sorted has 1 (or fewer!) elements, done. */
  if (right <= left) { return; }

  /* get midpoint and median element position (1<=k<=right-left-1). */
  int mid = (right - left + 1)/2;
  int me = selectKth (ar, cmp, mid+1, left, right);

  mediansort (ar, cmp, left, left+mid-1);
  mediansort (ar, cmp, left+mid+1, right);
}

int	selectPivotIndex (void **ar, int left, int right)
{
	return(*ar[left]);
}