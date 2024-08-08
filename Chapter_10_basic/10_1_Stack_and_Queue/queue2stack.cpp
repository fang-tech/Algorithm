#include <iostream>
#include <cassert>
#include "queue.hpp"

using namespace std;

class Stack{
    /*
    @author : 方天宇
    @date   : 2024.08.08
    @brief  : 使用两个队列实现一个栈, 并分析相关操作的时间复杂度, 关键点在于倒序存放
*/
private:
    Queue* q1;
    Queue* q2;
    int length;

public:
    // 构造函数
    Stack(int len): length(len + 1){
        q1 = new Queue(length);
        q2 = new Queue(length);
    }
    // 析构函数
    ~Stack(){
        delete q1;
        delete q2;
    }
    // PUSH 时间复杂度O(n)
    void push(int elem){
        q2->enqueue(elem);
        // 将q1全部放进q2中 
        while (!q1->isEmpty()){
            q2->enqueue(q1->front());
            q1->dequeue();
        }

        // 再将q2全部放进q1中
        while (!q2->isEmpty()){
            q1->enqueue(q2->front());
            q2->dequeue();
        }
    }

    // Top
    int top(){
        if (q1->isEmpty()){
            throw out_of_range("Stack is empty");
        }
        return q1->front();
    }

    //POP 时间复杂度O(1)
    void pop(){
        q1->dequeue();
    }

    bool isEmpty(){
        return q1->isEmpty();
    }
};

void test_stack(){
    std::cout << "开始测试栈...\n";

    // 测试1: 基本的push和top操作
    {
        Stack s(5);
        s.push(1);
        s.push(2);
        s.push(3);
        assert(s.top() == 3);
        std::cout << "测试1通过: 基本的push和top操作正常\n";
    }

    // 测试2: pop操作
    {
        Stack s(5);
        s.push(1);
        s.push(2);
        s.pop();
        assert(s.top() == 1);
        std::cout << "测试2通过: pop操作正常\n";
    }

    // 测试3: isEmpty操作
    {
        Stack s(5);
        assert(s.isEmpty());
        s.push(1);
        assert(!s.isEmpty());
        s.pop();
        assert(s.isEmpty());
        std::cout << "测试3通过: isEmpty操作正常\n";
    }

    // 测试4: 栈满时的行为
    {
        Stack s(3);
        s.push(1);
        s.push(2);
        s.push(3);
        try {
            s.push(4);  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::overflow_error& e) {
            std::cout << "测试4通过: 栈满时正确抛出异常\n";
        }
    }

    // 测试5: 空栈时的pop和top操作
    {
        Stack s(3);
        try {
            s.pop();  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::underflow_error& e) {
            std::cout << "测试5a通过: 空栈pop时正确抛出异常\n";
        }

        try {
            s.top();  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::out_of_range& e) {
            std::cout << "测试5b通过: 空栈top时正确抛出异常\n";
        }
    }

    // 测试6: 大量操作的正确性
    {
        Stack s(1000);
        for (int i = 0; i < 1000; i++) {
            s.push(i);
        }
        for (int i = 999; i >= 0; i--) {
            assert(s.top() == i);
            s.pop();
        }
        assert(s.isEmpty());
        std::cout << "测试6通过: 大量操作后栈的行为正确\n";
    }

    std::cout << "所有测试通过!\n";
}


int main(){
    test_stack();
    return 0;
}