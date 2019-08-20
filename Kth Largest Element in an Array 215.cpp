题目描述：
Example 1:

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

Example 2:

```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```




==思路：好像没啥特殊的，就是排序就可以了，本博客选取的是快排，当然也有堆排==
==快排可以使用库里面自带的sort函数，速度较快，自己写的很慢，我的是88ms，让我想起来研一的时候手写Kmeans比自带的kmeans的效果差太多，果然还是造好的轮子好用啊==
==不过普通快排很慢，这里用了随机快排，28ms效率立马上去了，虽然也不是很快，勉强能看==

关于快排的概念性问题，参考博客[什么是快速排序](https://blog.csdn.net/Trista_wang/article/details/99717074)



#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &v, int low, int high) {
        srand(time(NULL));
        int randIndex = rand()%(high-low+1)+low;
        swap(v[low], v[randIndex]);//随机选取基准元素，效率更高,
        
        int key = v[low];//记录划分点的值,选第一个元素
		while (low < high){
			while (low < high && key <= v[high])//从后往前找到第一个小于key
            {
				--high;
            }
			v[low] = v[high];
			while (low < high && key >= v[low])//从前往后找到第一个大于key
            {
				++low;
            }
			v[high] = v[low];
		}
		v[low] = key;//此时low=high
        return low;
}
void QuickSort(vector<int> &v, int low, int high){
	if (low < high){
        int index = partition(v,low,high);
		QuickSort(v, low,  index- 1);
		QuickSort(v, index + 1, high);//因为low=high，所以写哪个都可以
	}
}
int findKthLargest(vector<int> &v,int k){
    int n = v.size();
    QuickSort(v,0,n-1);
    return v[n-k];
}
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    
   int res;
   res =findKthLargest(v,2);
   cout << res<<endl;;
    
   // cout << "快排的结果"<< endl;
     for(auto c : v)
    {
        cout << c<< " ";
    } 
    return 0;
}

