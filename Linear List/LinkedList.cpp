#include <iostream>

using namespace std;

template<class T>
class LinkedList{

private:
    // 双向结点, 使迭代器支持双向遍历
    struct Node{ 
        T data;
        Node* next;
        Node* prev; 
        Node(const &T d) : data(d), next(nullptr), prev(nullptr) {};
        Node(): next(nullptr), prev(nullptr) {};
        
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int length;

public: 
    // 构造函数
    LinkedList(){
        this->head = new Node();  
        this->end = nullptr;
        this->length = 0;
    }
    // 析构函数, 用于释放内存
    ~LinkedList(){
        // 没有结点的时候
        if(this->begin)
        // 有结点的时候
        
    }

public: 
    // 迭代器类的定义, 用于遍历链表, 迭代器是对于指针的再一次封装, 
    // 为外部提供一个统一的访问接口, 在C++的STL库中, 是为了容器和STL算法的兼容
    
public: // 操作集 -> 基础操作集
    Node* begin(){
        return head;
    }  
    // 返回head结点地址
    Node* end(){
        return tail;
    };
    // 返回tail结点地址

    void Clear();  
    // 删除线性表中的所有元素
    void ListInsert(const &T elem, int idx);  
    // 插入元素, index为int的时候, 在序号为idx的后面插入, 返回插入的结点的地址, 插入失败, 返回end()
    void ListInsert(const &T elem, *Node idx);
    // 插入元素, index为某个结点迭代器, 在该结点的后面插入, 返回插入的结点的地址, 插入失败, 返回end()
    void push_back(const &T elem);
    // 尾插入元素
    void push_front(const &T elem);
    // 头插入元素
};

template<class T> void 

void unit_test_base_operation(){

}

int main(){

    return 0;
}
