#include <iostream>

using namespace std;

class Stack{
/*
    @author : 方天宇
    @date   : 2024.08.08
    @brief  : 实现简单的栈, 使用int数组实现
*/
private:
    int* stack = nullptr;
    int length = 0;
    int top_ = -1;
public:
    // 实现的操作集
    // 构造函数
    Stack(int len) : length(len){
        stack = new int[len]{0};
    }
    // 虚构函数
    ~Stack(){
        delete[] stack;
    }
    // PUSH
    void push(int elem){
        // 需要考虑到上溢问题
        if (this->top_ == this->length - 1){
            // cout <<  "overflow" << endl;
            throw overflow_error("overflow");
            }
        this->stack[++this->top_] = elem;
    }
    // POP
    void pop(){
        // 需要考虑到下溢问题
        if (this->top_ == -1){
            // cout <<  "underflow" << endl;
            throw underflow_error("underflow");
        }
        this->top_--;
    }
    //isEmpty
    bool isEmpty(void){
        if (this->top_ == -1)
            return true;
        else
            return false;
    }
    //top_
    int top(){
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack[top_];
    }

    void print_stack(){
        for (int i = 0; i <= this->top_; i++){
            cout << this->stack[i] << " ";
        }
    }
};

void test_stack(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(1);
    s.push(2);
    s.push(23);
    s.push(23);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print_stack();
}

// int main(){
//     test_stack();
//     return 0;
// }