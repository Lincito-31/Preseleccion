void bitsort(vector<int>&a,int pos,int size){
	//Our base case:
	//When the size of this array is 1 or 0, then we don't have to sort it since it is already sorted.
	//When the position=-1, then we don't have to sort it since theres no position -1.
	if(size<2 || pos==-1){
		return;
	}
	//x=size of array left and y=size of array right
	int x=0,y=0;
	vector<int> left,right;
	for(int i=0;i<size;i++){
		//Checking if the bit on position pos is 1 or 0
		if(a[i]&(1<<pos)){
			right.push_back(a[i]);
			y++;
			}else{
			left.push_back(a[i]);
			x++;
		}
	}
	//sorting left and right independently
	bitsort(left,pos-1,x);
	bitsort(right,pos-1,y);
	//Joining these two arrays
	for(int i=0;i<x;i++){
		a[i]=left[i];
	}
	for(int i=0;i<y;i++){
		a[i+x]=right[i];
	}
	//So we have done
	return;
}
vector<int> sortArray(vector<int>& nums) {
	int n=nums.size();
	//Calling the function
	bitsort(nums,30,nums.size());
	return nums;
}