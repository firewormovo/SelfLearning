#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*  
    用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 
    appendTail 和 deleteHead ，分别完成在队列尾部插入整
    数和在队列头部删除整数的功能。(若队列中没有元素，
    deleteHead 操作返回 -1 )
*/

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        while (!values1.empty())
        {
            values2.push(values1.top());
            values1.pop();
        }
        values1.push(value);
        while (!values2.empty())
        {
            values1.push(values2.top());
            values2.pop();
        }
    }

    int deleteHead()
    {
        if (values1.empty())
        {
            return -1;
        }
        int top_value = values1.top();
        values1.pop();
        return top_value;
    }

private:
    stack<int> values1;
    stack<int> values2;
};

int main(int argc, const char **argv)
{
    vector<string> arr1 = {"CQueue", "deleteHead", "appendTail", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead", "deleteHead", "appendTail", "deleteHead", "appendTail", "appendTail", "appendTail", "appendTail", "appendTail", "appendTail", "deleteHead", "deleteHead", "deleteHead", "deleteHead"};
    vector<int> arr2 = {-1, -1, 12, -1, 10, 9, -1, -1, -1, 20, -1, 1, 8, 20, 1, 11, 2, -1, -1, -1, -1};

    CQueue my_cqueue;
    int num_arr2 = arr2.size();
    std::cout << "null" << std::endl;
    for (int i = 1; i < num_arr2; i++)
    {
        std::cout << arr1[i] << ":" << arr2[i] << std::endl;
        if (arr1[i] == "deleteHead" && arr2[i] == -1)
        {
            std::cout << my_cqueue.deleteHead() << std::endl;
        }
        else if (arr1[i] == "deleteHead" && arr2[i] != -1)
        {
            std::cout << my_cqueue.deleteHead() << std::endl;
        }
        else if (arr1[i] == "appendTail" && arr2[i] != -1)
        {
            my_cqueue.appendTail(arr2[i]);
            std::cout << "null" << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }
    }

    return 0;
}