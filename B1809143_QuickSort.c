/*Nguyen Hoang Linh
  B1809143*/
#include<stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct {
    keytype key;
    othertype otherfields;
}recordtype;//declare struct 
//swap value
void swap(recordtype *a,recordtype *b){ 
    recordtype temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//find pivot
int findPivot(recordtype a[ ], int i,int j){  
   keytype  firstkey;
   int k ;
   k = i+1;
   firstkey = a[i].key;
   while ( (k <= j) && (a[k].key == firstkey) ) k++;
   if (k > j)  return -1;
   else
      if (a[k].key>firstkey)
        return k;
          else 
            return i;
}
//find parttion
int partition(recordtype a[], int i,int j, keytype pivot){ 
    int L,R;
	L = i;
	R = j;
 	while (L <= R) {
	   while (a[L].key < pivot)  L++;
	   while (a[R].key >= pivot) R--;
 	       if (L<R) swap(&a[L],&a[R]);
	    }
	return L;  
    }

void quickSort(recordtype a[], int i,int j)//quick sort 3 parameter struct , begin and end
{ keytype pivot;
  int pivotindex, k;
  pivotindex = findPivot(a,i,j);
  if (pivotindex != -1) {
      pivot = a[pivotindex].key;
      k = partition(a,i,j,pivot);
      quickSort(a,i,k-1);
      quickSort(a,k,j);
  }
}

int main(){
    int i,n;
    recordtype arr[100];
    FILE* f= fopen("dayso.inp","r");//open file
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(f,"%d",&arr[i].key);
    }
    quickSort(arr,0,n);
    printf("The array was sorted : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i].key);
    }
   
    return 0;
}//main
