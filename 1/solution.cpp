class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexs;
        for(int i=0;i<nums.size();i++)
        {
            indexs.push_back(i);
        }
        
        quicksort(nums, indexs, 0, nums.size()-1);
        
        int a=0;
        int b=0;
        int low = 0;
        int high = nums.size()-1;

        
        while(low < high)
        {
            if(nums[indexs[low]]+nums[indexs[high]] == target)
            {
                a = indexs[low];
                b = indexs[high];
                break;
            }

            if(nums[indexs[low]]+nums[indexs[high]] > target)
            {
                high--;
            }

            if(nums[indexs[low]]+nums[indexs[high]] < target)
            {
                low++;
            }            
        }

        vector<int> result = {a,b};
        return result;
    }

    void quicksort(vector<int>& nums, vector<int>& indexs, int low, int high)
    {
        if(low >= high)
        {
            return;
        }

        int index = sort(nums, indexs, low, high);

        quicksort(nums,indexs, low, index-1);
        quicksort(nums,indexs, index+1, high);
    }

    int sort(vector<int>& nums, vector<int>& indexs, int low, int high)
    {
        int pivot = nums[indexs[low]];
        int index = indexs[low];
        int i = low;
        int j = high;
        while(i<j)
        {
            while(i<j && nums[indexs[j]] >= pivot)
            {
                j--;
            }
            
            if(i<j)
            {
                indexs[i] = indexs[j];
            }

            while(i<j && nums[indexs[i]] <= pivot)
            {
                i++;
            }
            if(i<j)
            {
                indexs[j] = indexs[i];
            }

        }
        
        indexs[i] = index;
        return i;
    }
};