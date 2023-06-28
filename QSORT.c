// QSORT.c
#include <stdio.h>

void Exchange(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void QSORT(int *nums, int left, int right){  
		
    if(left>=right) return;

    int l=left+1; //左
    int r=right; //右
    int key=nums[left];

    while(1){
    	while(l<=right){
    		if(nums[l]>key) break;
    		l++;
    	}
    	
    	while(r>left){
    		if(nums[r]<key) break;
    		r--;
    	}
    	
    	if(l>r) break;
    	Exchange(&nums[l],&nums[r]); 
    }
    
    //key 和 相遇的值 互換
    Exchange(&nums[left],&nums[r]);
		
		//分小組繼續進行
    QSORT(nums,left,r-1);
    QSORT(nums,r+1,right);
}


int main(void){

	//測試資料
	int array[10]={8,6,1,10,5,3,9,2,7,4};
	
	QSORT(array,0,9);
	
	//印出結果
	for(int i=0; i<10; i++){
		printf("%d ",array[i]);
	}
}





