class Solution {
	public:
		vector<vector<int>> ans;//答案
		vector<int> tmp;//存放临时结果
		vector<int> used;//标记是否排序过的数组
		void dfs(vector<int>& nums,vector<int>& used) {
			//终止条件：临时结果长度等于给定数组长度
			if(tmp.size()==nums.size()) {
				ans.push_back(tmp);//把这次的结果放到答案数组中
				return ;
			}
			for(int i=0; i<nums.size(); i++) {
				//处理结点
				if(used[i]) continue;//如果当前数已经用过跳到下一轮
				tmp.push_back(nums[i]);//将未排序的数放到临时数组
				used[i]=1;				//标记为置1 表示这个数已经用过
				dfs(nums,used);
				//递归 对后面没排序过的数进行全排列，前面的数因为标记位置1不受递归函数影响
				tmp.pop_back();//一个完全的tmp结束后，弹出进行下一次选择
				used[i]=0;//该层数字弹出置0，回溯
			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			int n=nums.size();
			used.assign(n,0);
			dfs(nums,used);
			return ans;
		}
};

