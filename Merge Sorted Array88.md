//分别给出两个有序的数组，nums1跟Nums2,合并这两个数组，变成一个nums1，假设数组1中有足够的空间容纳很多的元素

//Input: nums1 = [1, 2, 3, 0, 0, 0] m = 3; 

//nums2 = [2, 5, 6] n = 3

//output = [1, 2, 2, 3, 5, 6]

**思路:本方法速度很快，从后往前，先比较两个数组的最后一个元素，谁大，谁就放入数组1 的第k个位置，中括号里面的用的后缀递减，因为减去1之间的kij都需要用，最后如果数组1没有元素，数组2还有，就把剩下的数组全部放入数组1，因为本身就是有序的**

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else 
                nums1[k--] = nums2[j--];
        }
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};
```
