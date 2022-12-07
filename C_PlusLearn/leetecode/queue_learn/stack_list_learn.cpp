#include <iostream>

struct MyListNode
{
    int value;
    MyListNode *next;
    MyListNode() : next(nullptr) {}
};

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = new MyListNode();
        min_head = new MyListNode();
    }
    ~MinStack()
    {
        delete head;
        delete min_head;
    }
    void push(int x)
    {
        MyListNode *tmp_node = new MyListNode();
        tmp_node->value = x;
        tmp_node->next = head;
        head = tmp_node;
        if (min_head->next != nullptr)
        {
            if (x < min_head->value)
            {
                MyListNode *tmp_min_node = new MyListNode();
                tmp_min_node->value = x;
                tmp_min_node->next = min_head;
                min_head = tmp_min_node;
            }
            else
            {
                std::cout << "-----------------"<< std::endl;
                MyListNode *tmp_min_node = new MyListNode();
                tmp_min_node->value = min_head->value;
                tmp_min_node->next = min_head;
                min_head = tmp_min_node;
            }
        }
        else
        {
            MyListNode *tmp_min_node = new MyListNode();
            tmp_min_node->value = x;
            tmp_min_node->next = min_head;
            min_head = tmp_min_node;
        }
    }

    void pop()
    {
        MyListNode *tmp_node = new MyListNode();
        tmp_node->value = head->next->value;
        tmp_node->next = head->next->next;
        head = tmp_node;
        MyListNode *tmp_min_node = new MyListNode();
        tmp_min_node->value = min_head->next->value;
        tmp_min_node->next = min_head->next->next;
        min_head = tmp_min_node;
    }

    int top()
    {
        if (head->next == nullptr)
        {
            return -1;
        }
        return head->value;
    }

    int min()
    {
        if (min_head->next == nullptr)
        {
            return -1;
        }
        return min_head->value;
    }

private:
    MyListNode *head;
    MyListNode *min_head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(int argc, const char **argv)
{

    MinStack *minStack = new MinStack();
    minStack->push(2);
    minStack->push(0);
    minStack->push(3);
    minStack->push(0);
    std::cout << minStack->min() << std::endl; 
    minStack->pop();
    std::cout << minStack->min() << std::endl; 
    minStack->pop();
    std::cout << minStack->min() << std::endl;
    minStack->pop();
    std::cout << minStack->min() << std::endl;
    std::cout << minStack->top() << std::endl;
    return 0;
}