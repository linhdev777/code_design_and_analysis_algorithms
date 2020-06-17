/*Nguyen Hoang Linh
  B1809143*/
#include<stdio.h>

typedef int keytype;
typedef float othertype;
//declare struct
typedef struct {
    keytype key;
    othertype otherfields;
}recordtype;
//swap value
void swap(recordtype *a,recordtype *b){
    recordtype temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//bubble sort 2 parameter 
void bubbleSort(recordtype arr[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>=i+1;j--){
            if(arr[j].key<arr[j-1].key){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }
}//bubblesort
int main(){
    int i,n;
    recordtype arr[100];
    FILE* f= fopen("dayso.inp","r");//open file 
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(f,"%d",&arr[i].key);
    }
   bubbleSort(arr,n);
    printf("The array was sorted : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i].key);
    }
   
    return 0;
}
