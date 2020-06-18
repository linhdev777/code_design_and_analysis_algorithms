#include<stdio.h>
#include<stdlib.h>
void inputArray(int* arr,int *n){
	int i;
	printf("please input the lengofArray: ");
	scanf("%d",n);
	int soluong=sizeof(int)*(*n);
	arr=(int*)malloc(soluong);
	printf("%d",sizeof(arr));
	for(i=0;i<(*n);i++){
		printf("arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<(*n);i++){
		printf("arr[%d]:",arr[i]);
		
	}
}
void readFromFile(int* arr,int* n){
	FILE *f;
	int i=0;
	f=fopen("datasort.txt","r");
	fscanf(f,"%d",n);
	while(!feof(f)){
		fscanf(f,"%d",arr+i);
		i++;
	}
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void bubleSort(int * arr,int n){
	printf("\nbubble Sort\n");
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>=i+1;j--){
			if(arr[j]<arr[j-1])
				swap(arr+j,arr+j-1);
		}
	}
}
void insertionSort(int* arr,int n){
	printf("\ninsertion sort\n");
	int i,j,key;
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void selectionSort(int* arr,int n){
	printf("\nselection sort\n");
	int i,j,lowerIndex;
	for(i=0;i<n-1;i++){
		lowerIndex=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[lowerIndex])
			lowerIndex=j;
		}
		swap(arr+i,arr+lowerIndex);
	}
}
int findPivot(int begin,int end,int* arr){
	int key,k;
	key=arr[begin];
	k=begin+1;
	while(k<=end&&arr[k]==key){
		k++;
	}
	if(k>end){
		return -1;
	}else if(arr[k]>key){
		     return k;
	     }
	       else return begin;
}
int partition(int begin,int end,int pivot,int* arr){
	int l,r;
	l=begin;
	r=end;
	while(l<=r){
	while(arr[l]<pivot) l++;
	while(arr[r]>=pivot) r--;
	if(l<r){
		swap(&arr[l],&arr[r]);
		}
	}
	return l;	
}
void quickSort(int begin,int end,int* arr){
	int indexpivot,pivot,part;
	indexpivot=findPivot(begin,end,arr);
	if(indexpivot!=-1){
		pivot=arr[indexpivot];
		part=partition(begin,end,pivot,arr);
		quickSort(begin,part-1,arr);
		quickSort(part,end,arr);
	}
}
void PushDown( int first,int last,int* a)
{ int  r= first;
  while (r <= (last-1)/2)
   if (last == 2*r+1) {
     if (a[r] > a[last]) swap(&a[r],&a[last]);
     r = last;
   } else
   if ((a[r]>a[2*r+1]) && (a[2*r+1]<=a[2*r+2]))
   {
      swap(&a[r],&a[2*r+1]);
      r = 2*r+1 ;
   } else
      if ((a[r]>a[2*r+2]) && (a[2*r+2]<a[2*r+1]))
      {
	 swap(&a[r],&a[2*r+2]);
	 r = 2*r+2 ;
      }
      else
	 r = last;
}

void pushDown(int first,int last,int* arr){
	int r;
	r=first;
	while(r<=(last-1)/2)
	if(last==2*r+1){
		if(arr[r]>arr[last]){
			swap(&arr[r],&arr[last]);
		}
		r=last;		
	}		
	else 
	    if((arr[r]>arr[2*r+1])&&(arr[2*r+1]<=arr[2*r+2])){
	    	swap(&arr[r],&arr[2*r+1]);
	    	r=2*r+1;
		}
		else
			if((arr[r]>arr[2*r+2])&&(arr[2*r+1]>arr[2*r+2])){
	    		swap(&arr[r],&arr[2*r+2]);
	    		r=2*r+2;
		    }
		    else 
		        r=last;
		
}
void heapSort(int *arr,int n){
	int i;
	for(i=(n-2)/2;i>=0;i--){
		pushDown(i,n-1,arr);
	}
	for(i=n-1;i>1;i--){
		swap(arr+0,arr+i);
		pushDown(0,i-1,arr);	
	}
	swap(arr+0,arr+1);
}
	

void outputArray(int* arr,int n){
	printf("\nall elements of array: ");
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int arr[20],n;
//	inputArray(arr,&n);
	readFromFile(arr,&n);
	outputArray(arr,n);
//	insertionSort(arr,n);
//	bubleSort(arr,n);
//	selectionSort(arr,n);
//	quickSort(0,n-1,arr);
	heapSort(arr,n);
	outputArray(arr,n);
	return 0;
}
