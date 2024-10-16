/**
 * @author  方天宇
 * @date    2024/10/16
 * @brief   静态队列的手动实现, 解决洛谷的1540
 */
#include <iostream>
const int N = 1e3 + 10;
using namespace std;

class queue{
private:
    int data[N];
    int top, end;

public:
    queue(){
        top = -1;
        end = 0;
    }
    void push(int elem){
        if ((end + 1) % N == top) return; // 队列满的时候
        data[end] = elem;
        end = (end + 1) % N;
    }
    int pop(){
        if ((top + 1) % N == end) return; //队列为空的时候
        int e = data[top];
        top = (top + 1) % N;
        return e;
    }
    int size(){
        return (end - top - 1 + N) % N;
    }
}