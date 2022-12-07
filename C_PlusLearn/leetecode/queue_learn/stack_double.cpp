#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int count = 0;
        bool flag = false;

        int num_pused = pushed.size();
        for (int j = 0; j < num_pused; j++)
        {
            stack<int> test_stack;
            stack<int> test_stack1;
            for (int i = 0; i < j + 1; i++)
            {
                test_stack.push(pushed[i]);
                test_stack1 = test_stack;
                count = 0;
                while (test_stack1.top() == popped[count])
                {
                    test_stack1.pop();
                    count++;
                    if (count == popped.size())
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};