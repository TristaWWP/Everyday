// 题目描述：一组数组的数字范围是1-n，共n个数，求其中重复出现的所有数

//  input：【4，3，2，7，8，2，3，1】output:[2,3]

//思路：因为数组的范围是数字的范围，那么每个数字减1就是数组的下标，根据这个新的下标来标记原来的数字，将下标对应的数字取相反数
// 如果某个下标的数字已经小于0，那么证明这个下标已经出现了一次，所以就是重复的数


class Solution{
    public:
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                res.push_back(index + 1);
            }
            nums[index] = -nums[index];
        }
        return res;
}
