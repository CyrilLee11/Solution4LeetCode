class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> seq;
        map<int,bool> bitmap;
        for(int i=0;i<nums.size();i++)
        {
            bitmap.insert(pair<int, bool>(nums[i],false));
        }

        for(int i=0;i<nums.size();i++)
        {
            if(bitmap[nums[i]] == false)
            {
                bitmap[nums[i]] = true;
                dfs(nums, result, -1, i, seq);
            }

        }

        return result;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& result,int prev, int cur, vector<int>& seq)
    {
        map<int,bool> bitmap;
        
        if(prev == -1 || nums[prev] <= nums[cur])
        {            
            seq.push_back(nums[cur]);
            
            if(seq.size() >= 2)
            {
                result.push_back(seq);
            }

            for(int i=cur+1;i<nums.size();i++)
            {
                if(bitmap.find(nums[i]) == bitmap.end())
                {
                    bitmap.insert(pair<int,bool>(nums[i],true));
                    dfs(nums,result, cur, i, seq);
                }
            }

            seq.pop_back();
        }        
    }

};