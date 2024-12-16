#include<stdio.h>
int main(){
	int arr[4]={4,1,3,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=1;i<n;i++){
		int temp = arr[i];
		int j=i-1;
		for(;j>=0;j--){
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
		}
		arr[j+1]=temp;
	}
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
