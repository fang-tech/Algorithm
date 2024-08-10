#include <iostream>
#include <cassert>

using namespace std;

/*
    @author : 方天宇
    @date   : 2024.08.09
    @brief  : 使用多个数组实现一个基础的链表, 包含部分最基础操作集和垃圾收集器(用于内存分配与释放), 均以int为数据类型
                接下来的实现中, 不允许使用指针和对象(class and struct)
                链表的结构为|prev|key|next|
*/

const int MEMORY_SIZE = 300;  // 必须是3的倍数, 因为链表的一个结点占用三个int
const int BLOCK_SIZE = 3;   //  一个内存块的大小
int memoryPool[MEMORY_SIZE]{};  // 内存池

int freeList = 1;  // 自由表中的第一个可用内存
int root = -3;  // 链表的根节点, -3时表示为空的链表

// 垃圾收集器(内存管理)
// 初始化自由表
void initializeMemory(){
    for (int i = 2; i < MEMORY_SIZE - BLOCK_SIZE; i += BLOCK_SIZE){
        memoryPool[i] = i + BLOCK_SIZE - 1;  // 内存池中每个Block指向下一个Block的key
    }
    memoryPool[MEMORY_SIZE - 1] = -3;  // 对终止位置的标定
}
// 分配内存
int allocate(){
/*
    @return : 返回可用的内存的key位置的索引
*/
    // 上溢的检查 : 分配已经满了的内存池, 内存分配失败
    if (freeList == -3){
        throw overflow_error("allocate failed");
    }
    int retKey = freeList;
    // freeList = freeList -> next
    freeList = memoryPool[freeList + 1];
    return retKey;
}
// 回收内存
void deallocate(int key_index){
/*
    @param  : 
        x : 需要回收的结点的key的索引
*/  
    memoryPool[key_index + 1] = freeList;
    memoryPool[key_index - 1] = -3;
    freeList = key_index;
    return;
}
// 打印自由表
// void printFreeList(){
//     cout << "Print the FreeList : " << endl;
//     for (int i = 2; i < MEMORY_SIZE; i += BLOCK_SIZE){
//         cout << memoryPool[i];
//     }
//     cout << "now the head pointer is : " << freeList << endl;
// }

// 链表相关

//判断是否为空
bool isEmpty(){
    if (root == -3){
        return true;
    }
    return false;
}

//插入一个元素, 使其成为头结点
void push_front(int elem){
    int newNode = allocate();
    //newNode.data = elem
    memoryPool[newNode] = elem;
    //newNode.next = nullptr
    memoryPool[newNode + 1] = -3;
    //newNode.prev = nullptr
    memoryPool[newNode - 1] = -3;
    //head.prev = newNode
    if (!isEmpty()){
        //newNode->next = head
        memoryPool[newNode + 1] = root;
        // head->prev = newNode
        memoryPool[root - 1] = newNode;
        // head->prev = newNode
        memoryPool[root - 1] = newNode;
    }
    //head = newNode
    root = newNode;
}

// 删除第一个结点
void pop_front(){
    // 空链表
    if (isEmpty()){
        throw underflow_error("pop failed");
    }
    // 只有一个结点的时候
    if (memoryPool[root + 1] == -3){
        deallocate(root);
        root = -3;
        return;
    }
    // 正常情况
    // q = head
    int oldRoot = root;
    // head = q->next
    root = memoryPool[root + 1];
    // head->perv = nullptr
    memoryPool[root - 1] = -3;
    // delete q
    deallocate(oldRoot);
}

void printList() {
    cout << "List: ";
    int current = root;
    while (current != -3) {
        cout << memoryPool[current] << " ";
        current = memoryPool[current + 1];
    }
    cout << std::endl;
}

void test_linked_list() {
    cout << "Starting comprehensive linked list tests...\n";

    // 初始化
    initializeMemory();

    // 测试1: 空链表操作
    cout << "\nTest 1: Empty list operations\n";
    if (isEmpty()) {
        cout << "List is initially empty.\n";
    } else {
        cout << "Error: List should be empty.\n";
    }
    try {
        pop_front();
        cout << "Error: pop_front() should throw an exception on empty list.\n";
    } catch (const underflow_error& e) {
        cout << "Caught expected exception: " << e.what() << "\n";
    }

    // 测试2: 基本的push和pop操作
    cout << "\nTest 2: Basic push and pop operations\n";
    push_front(1);
    push_front(2);
    push_front(3);
    cout << "After pushing 3, 2, 1: ";
    printList();

    pop_front();
    cout << "After popping once: ";
    printList();

    pop_front();
    cout << "After popping twice: ";
    printList();

    pop_front();
    cout << "After popping thrice: ";
    printList();

    if (isEmpty()) {
        cout << "List is empty after all pops.\n";
    } else {
        cout << "Error: List should be empty after all pops.\n";
    }

    // 测试3: 大量push操作
    cout << "\nTest 3: Massive push operations\n";
    const int LARGE_N = MEMORY_SIZE / BLOCK_SIZE;
    for (int i = 0; i < LARGE_N; ++i) {
        push_front(i);
        if ((i+1) % 50 == 0) {
            cout << "After pushing " << i << " elements: ";
            printList();
        }
    }

    // 测试4: 内存耗尽
    cout << "\nTest 4: Memory exhaustion\n";
    try {
        push_front(LARGE_N);
        cout << "Error: push_front() should throw an exception when memory is full.\n";
    } catch (const overflow_error& e) {
        cout << "Caught expected exception: " << e.what() << "\n";
    }

    // 测试5: 大量pop操作
    cout << "\nTest 5: Massive pop operations\n";
    for (int i = 0; i < LARGE_N; ++i) {
        pop_front();
        if (i % 50 == 0) {
            cout << "After popping " << i << " elements: ";
            printList();
        }
    }

    if (isEmpty()) {
        cout << "List is empty after all pops.\n";
    } else {
        cout << "Error: List should be empty after all pops.\n";
    }

    // 测试6: 交替push和pop
    cout << "\nTest 6: Alternating push and pop operations\n";
    for (int i = 0; i < 198; ++i) {
        cout << i+1 << " ";
        if ((i+1) % 2 == 0) {
            pop_front();
        }
        push_front(i+1);
        if ((i+1) % 100 == 0) {
            cout << "After " << i+1 << " operations: ";
            printList();
        }
        
    }

    // 测试7: 内存重用
    cout << "\nTest 7: Memory reuse\n";
    while (!isEmpty()) {
        pop_front();
    }
    for (int i = 0; i < LARGE_N; ++i) {
        push_front(i);
        if (i % 50 == 0) {
            cout << "After pushing " << i << " elements: ";
            printList();
        }
    }

    cout << "All tests completed!\n";
}

int main(){
    test_linked_list();
    return 0;
}