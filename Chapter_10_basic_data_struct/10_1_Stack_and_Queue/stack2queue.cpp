#include <iostream>
#include "stack.hpp"
#include <cassert>

using namespace std;

class Queue{
    /*
    @author : 方天宇
    @date   : 2024.08.08
    @brief  : 使用两个栈实现了一个队列, 关键 -> 倒序存储
*/
private:
    Stack* s1;
    Stack* s2;

public:
    Queue(int length){
        s1 = new Stack(length);
        s2 = new Stack(length);
    }
    ~Queue(){
        delete s1;
        delete s2;
    }
    // ENQUEUE 时间复杂度尾 O(n)
    void enqueue(int elem){
        while (!s1->isEmpty()){
            s2->push(s1->top());
            s1->pop();
        }

            s2->push(elem);

        while (!s2->isEmpty()){
            s1->push(s2->top());
            s2->pop();
        }
    }
    // DEQUEUE 时间复杂度尾 O(1)
    void dequeue(){
        s1->pop();
    }
    // Front
    int front(){
        return s1->top();
    }
    // Empty
    bool isEmpty(){
        return s1->isEmpty();
    }
};

void test_queue(){
    std::cout << "开始测试队列...\n";

    // 测试1: 基本的enqueue和front操作
    {
        Queue q(5);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        assert(q.front() == 1);
        std::cout << "测试1通过: 基本的enqueue和front操作正常\n";
    }

    // 测试2: dequeue操作
    {
        Queue q(5);
        q.enqueue(1);
        q.enqueue(2);
        q.dequeue();
        assert(q.front() == 2);
        std::cout << "测试2通过: dequeue操作正常\n";
    }

    // 测试3: isEmpty操作
    {
        Queue q(5);
        assert(q.isEmpty());
        q.enqueue(1);
        assert(!q.isEmpty());
        q.dequeue();
        assert(q.isEmpty());
        std::cout << "测试3通过: isEmpty操作正常\n";
    }

    // 测试4: 队列满时的行为
    {
        Queue q(3);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        try {
            q.enqueue(4);  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::overflow_error& e) {
            std::cout << "测试4通过: 队列满时正确抛出异常\n";
        }
    }

    // 测试5: 空队列时的dequeue和front操作
    {
        Queue q(3);
        try {
            q.dequeue();  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::underflow_error& e) {
            std::cout << "测试5a通过: 空队列dequeue时正确抛出异常\n";
        }

        try {
            q.front();  // 这应该抛出异常
            assert(false);  // 如果没有抛出异常,测试失败
        } catch (const std::out_of_range& e) {
            std::cout << "测试5b通过: 空队列front时正确抛出异常\n";
        }
    }

    // 测试6: FIFO顺序
    {
        Queue q(5);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        assert(q.front() == 1);
        q.dequeue();
        assert(q.front() == 2);
        q.dequeue();
        assert(q.front() == 3);
        std::cout << "测试6通过: 队列保持FIFO顺序\n";
    }

    // 测试7: 大量操作的正确性
    {
        Queue q(1000);
        for (int i = 0; i < 1000; i++) {
            q.enqueue(i);
        }
        for (int i = 0; i < 1000; i++) {
            assert(q.front() == i);
            q.dequeue();
        }
        assert(q.isEmpty());
        std::cout << "测试7通过: 大量操作后队列的行为正确\n";
    }

    std::cout << "所有测试通过!\n";
}


int main(){
    test_queue();
    return 0;
}