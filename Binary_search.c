#include<stdio.h>
int main(){
	int arr[]= {1,13,23,34,56,78,98};
	int target, pos = -1,i,size,lb,ub;
	
	size = sizeof(arr)/sizeof(arr[0]);
	lb = 0;
	ub = size-1;
	
	printf("ENTER THE NUMBER: ");
	scanf("%d",&target);
	
	while(lb<=ub){
		int mid;
		mid = (lb+ub)/2;
		if(target == arr[mid]){
			pos = mid;
			break;
		}
		if(target > arr[mid]){
			lb = mid+1;
		}
		else{
			ub = mid-1;
		}
	}
	if(pos == -1){
		printf("element not found");
	}
	else{
		printf("%d FOUND AT %d",target,pos+1);
	}
	
}
