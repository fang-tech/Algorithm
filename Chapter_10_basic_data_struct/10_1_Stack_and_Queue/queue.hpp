#include <iostream>

using namespace std;

class Queue{
    /*
    @author : 方天宇
    @date   : 2024.08.08
    @brief  : 简单的队列的实现, 使用int数组实现, 环形的队列导致必定会有一个位置空出来, 用于区分空与满
*/
private:
    int* queue = nullptr;
    int head;
    int tail;
    int length;

public:
    // 构造函数
    Queue(int len): length(len) {
        head = tail = 0;
        queue = new int[length]{0};
    }
    // 虚构函数
    ~Queue(){
        delete[] queue;
    }
    // ENQUEUE
    void enqueue(int elem){
        // 上溢的检查
        if ((tail + 1) % length == head){
            // cout << "overflow" << endl;
            throw overflow_error("overflow");
        }
        queue[tail] = elem;
        tail = (tail + 1) % length;
    }
    // DEQUEUE
    void dequeue(){
        // 下溢的检查
        if (head == tail){
            // cout << "underflow" << endl;
            throw underflow_error("underflow");
        }
        head = (head + 1) % length;
    }
    // isEmpty
    bool isEmpty(){
        if (head % length == tail){
            return true;
        }
        return false;
    }
    // front
    int front(){
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return queue[head];
    }
    
    void print_queue(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return; 
        }
        int begin = head;
        int end = tail;
        while(begin != end){
            cout << queue[begin] << " ";
            begin = (begin + 1) % length;
        } 
        cout << endl;
    }
};

void test_queue(){
    Queue q(5);
    q.print_queue();
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(4);
    q.print_queue();
    q.dequeue();
    q.print_queue();
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.print_queue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print_queue();
}


// int main(){
//     test_queue();
//     return 0;
// }