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
//insertion sort 2 parameter 
void insertionSort( recordtype arr[], int n){
    int i,j;
    keytype k;
    for(i=1;i<n;i++){
        j=i;
        while((j>0)&&(arr[j].key<arr[j-1].key)){
            swap(&arr[j],&arr[j-1]);
            j--;
        }
    }
    
}//insertion sort

int main(){
    int i,n;
    recordtype arr[100];
    FILE* f= fopen("dayso.inp","r");//open file 
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(f,"%d",&arr[i].key);
    }
    insertionSort(arr,n);
    printf("The array was sorted : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i].key);
    }
   
    return 0;
}
