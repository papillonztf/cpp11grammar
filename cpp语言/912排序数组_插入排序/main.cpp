/*插入排序：<超时>
    复杂度：
        时间复杂度：最好O(N)-最坏O(N^2)-平均O(N^2).
        空间复杂度：O(1)
    分析：
        通过将后面未排序的元素与已排序的元素进行比较，确定该元素在已排序元素中
        的插入位置并进行插入。
    实现：c++
* /
#include<vector>

vector<int> sortArray(vector<int>& nums) {
    int temp=0;
        for(int i=1;i<nums.size();i++){ 
            for(int j=i-1;j>=0;j--){
                if(nums[j+1]<nums[j]){
                    temp=nums[j+1];
                    nums[j+1]=nums[j];
                }
                else
                    break;
                nums[j]=temp;
            }
            
        }
            
    return nums;
                
    }

