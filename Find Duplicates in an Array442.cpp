/* 找到数组中的重复元素，之前有说过有序数组去重，是删除重复元素（快慢指针），现在是找到重复元素
题目描述：input=[4,3,2,7,8,2,3,1]，输出 [2,3],关键在于1<= A[i]<=n
思路：正数变负数的方法，关键在于找到数组中的数和下标之间的关系，数组中的数字-1就是新下标
根据新下标遍历原数组，将其取相反数
下次再遍历到相同的下标，如果已经<0,证明之前访问过，就把这个下标对应的原来数组的数push，即index+1

 */
#include<iostream>
#include<vector>

using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i)
    {
        int index = abs(nums[i])-1;//因为数字范围是1-n，那么下标就是0-n-1
        if(nums[index] < 0)
        {
            res.push_back(index+1);//数组内真正的数字是index+1，因为之前减去1
        }
        nums[index] = -nums[index];//每次遍历过的index的对应的数字置为相反数，那么一旦小于0证明之前已经访问过
    }
    return res;
}
int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    vector<int> res;
    res = findDuplicates(v);
    for(auto c:res)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
