/*
 * @Author: your name
 * @Date: 2021-10-14 22:51:17
 * @LastEditTime: 2021-10-14 23:06:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C_PlusLearn/leetecode/dichotomy/main.cpp
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int num_param = nums.size();
        if(num_param==0){
            return -1;
        }
        if(num_param == 1 && nums[0]!=target){
            return -1;
        }
        int start_index = 0;
        int middle_index = num_param / 2 - 1;
        printf("%d",middle_index);
        int end_index = num_param -1;
        bool flag = false;
        while(!flag){
            if(nums[middle_index]==target){
                return start_index;
            }
            if(nums[start_index] ==target){
                return middle_index;
            }
            if(nums[end_index] == target){
                return end_index;
            }
            if(middle_index <= start_index){
                return -1;
            }
            if(nums[middle_index]>target){
                int tmp = middle_index;
                middle_index = (start_index+middle_index) / 2;
                end_index = tmp;
            }else{
                int tmp = middle_index;
                middle_index = (middle_index+end_index)  / 2;
                start_index = middle_index;
            }
        }
    }
};

int main(int argc,char *argv[]){
    Solution my_solution;
    vector<int> input = {-1,0,3,5,8,12};
    int result = my_solution.search(input,9);
    cout<<"result:"<< result << endl;
}