#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> p(nums.size(), 1);
        vector<int> q(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) p[i] = max(p[i], q[j] + 1);
                else if (nums[i] < nums[j]) q[i] = max(q[i], p[j] + 1);
            }
        }
        return max(p.back(), q.back());
    }
};
int main()
{
    int n;
    while(cin>>n){
        vector<int> a(n,0);
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        Solution plan;
        cout << plan.wiggleMaxLength(a) << endl;
    }
    return 0;
}
