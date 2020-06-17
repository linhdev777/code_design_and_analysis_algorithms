#include<stdio.h>
typedef struct {
    int column1;
    float column2;
}recordtype;
void merge(recordtype arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i].column1; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j].column1; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k].column1 = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k].column1 = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k].column1 = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k].column1 = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(recordtype arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(recordtype A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i].column1); 
    printf("\n"); 
    for (i=0; i < size; i++) 
        printf("%f ", A[i].column2); 
    printf("\n"); 
} 
int main(){
    recordtype arr[100];
    int n,i;
    char * filePath="D:\\Information_Technology\\Design_And_Analyisis_Algorithms\\datamergesort.txt";
    FILE *file=fopen(filePath,"r");
    rewind(file);
    fscanf(file,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(file,"%d %f",&arr[i].column1,&arr[i].column2);
    }
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    if(file==EOF)
       fclose(file);
    return 0;
}
  
