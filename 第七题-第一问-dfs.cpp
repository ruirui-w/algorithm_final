class Solution {
	public:
		vector<vector<int>> ans;//��
		vector<int> tmp;//�����ʱ���
		vector<int> used;//����Ƿ������������
		void dfs(vector<int>& nums,vector<int>& used) {
			//��ֹ��������ʱ������ȵ��ڸ������鳤��
			if(tmp.size()==nums.size()) {
				ans.push_back(tmp);//����εĽ���ŵ���������
				return ;
			}
			for(int i=0; i<nums.size(); i++) {
				//������
				if(used[i]) continue;//�����ǰ���Ѿ��ù�������һ��
				tmp.push_back(nums[i]);//��δ��������ŵ���ʱ����
				used[i]=1;				//���Ϊ��1 ��ʾ������Ѿ��ù�
				dfs(nums,used);
				//�ݹ� �Ժ���û�������������ȫ���У�ǰ�������Ϊ���λ��1���ܵݹ麯��Ӱ��
				tmp.pop_back();//һ����ȫ��tmp�����󣬵���������һ��ѡ��
				used[i]=0;//�ò����ֵ�����0������
			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			int n=nums.size();
			used.assign(n,0);
			dfs(nums,used);
			return ans;
		}
};

