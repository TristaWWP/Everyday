//找出一个数组中重复的数，给出一个数组共N+1个数字，数组中数字的范围在1-N之间
//方法一，二分查找法，求出mid，将数组中所有的数与mid比较，比mid小的话cnt++,最后如果cnt的值和mid比较，如果cnt小，说明重复的数在右边，依次循环

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 1;
        int high = n;
        while(low < high){
            int count = 0;
            int mid = (high + low) / 2;
            for (int num : nums){
                if(num <= mid)
                    ++count; 
            }
             if(count <= mid)
                    low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

//方法二：利用快慢指针，找到这个环的入口并找到入口节点
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int t = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            slow = nums[slow];
            t = nums[t];
            if(slow == t) break;
        }
        return slow;
    }
};
