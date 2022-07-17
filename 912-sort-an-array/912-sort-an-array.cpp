class Solution {
public:
    void bubble(vector<int>&nums){
        for(int i=0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i] > nums[j])
                    swap(nums[i] , nums[j]);
            }
        }
    }
    
    // Randomized QUick
int partitionArray(vector<int> &nums, int low, int high) {
	if (low >= high) return -1;
	int pivot = low, l = pivot + 1, r = high;
	while (l <= r)
		if (nums[l] < nums[pivot]) l++;
		else if (nums[r] >= nums[pivot]) r--;
		else swap(nums[l], nums[r]);
	swap(nums[pivot], nums[r]);
	return r;
}

void quickSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	swap(nums[low + rand() % (high - low + 1)], nums[low]);
	int pivot = partitionArray(nums, low, high);
	quickSort(nums, low, pivot);
	quickSort(nums, pivot + 1, high);
}
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        quickSort(nums , 0 , nums.size()-1);
        return nums ; 
    }
};