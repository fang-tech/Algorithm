#include <iostream>

using namespace std;

class Deque{
/*
    @author : 方天宇
    @date   : 2024.08.08
    @brief  : 双端队列的简单实现(插入操作和删除操作均可在两端进行), 使用数组实现
*/
private:
    int* deque = nullptr;
    int length = 0;
    int head;
    int tail;
public:
    // 构造函数
    Deque(int len): length(len + 1){
        head = tail = 0;
        deque = new int[length]{0};
    }
    // 虚构函数
    ~Deque(){
        delete[] deque;
    }
    // 是否为空
    bool isEmpty(){
        if (head == tail)
            return true;
        return false;
    }
    // 是否为满
    bool isFull(){
        if ((tail + 1) % length == head)
            return true;
        return false;
    }
    // 头插入
    void push_front(int elem){
        // 上溢的检查
        if (isFull()){
            cout << "overflow" << endl;
            return;
        }
        head = (head - 1 + length) % length;
        deque[head] = elem;
    }
    // 尾插入
    void push_back(int elem){
        // 上溢的检查
        if (isFull()){
            cout << "overflow" << endl;
            return;
        }
        deque[tail] = elem;
        tail = (tail + 1) % length;
    }
    // 头删除
    void pop_front(){
        // 下溢的检查
        if (isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        head  = (head + 1) % length;
    }
    // 尾删除
    void pop_back(){
        // 下溢的检查
        if (isEmpty()){
            cout << "underflow" << endl;
            return;
        }
        tail = (tail - 1 + length) % length;
    }
    // travel
    void print_deque(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return; 
        }
        int begin = head;
        int end = tail;
        while(begin != end){
            cout << deque[begin] << " ";
            begin = (begin + 1) % length;
        } 
        cout << endl;
    }
};

void test_deque(){
    Deque d(5);
    d.push_front(1);
    d.push_back(2);
    d.push_front(5);
    d.print_deque();
    d.push_back(1);
    d.push_front(23);
    d.push_front(23);
    d.print_deque();
    d.pop_back();
    d.pop_front();
    d.pop_back();
    d.pop_front();
    d.print_deque();
    // d.pop_back();
    // d.pop_front();
    d.pop_front();
    d.pop_back();
    d.print_deque();
}

int main(){
    test_deque();
    return 0;
}
