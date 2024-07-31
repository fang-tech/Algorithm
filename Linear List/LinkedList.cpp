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
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {};
        Node(): next(nullptr), prev(nullptr) {};
        
    };

    Node* head = nullptr;
    // 尾结点并不是一个特殊的结点, 只是用来标记最后一个结点便于一些操作
    Node* tail = nullptr;
    int length;

public: 
    // 构造函数
    LinkedList(){
        this->head = new Node();  
        this->tail = head;
        this->length = 0;
    }
    // 析构函数, 用于释放内存
    // ~LinkedList(){
    //     // 没有结点的时候
    //     if(this->begin){}
    //     // 有结点的时候
        
    // }

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
    bool Empty(){
        if(head->next == nullptr)
            return true;
        else 
            return false;
    }
    // 返回tail结点地址

    // 删除线性表中的所有元素
    void Clear();  
    // 插入元素, index为int的时候, 在序号为idx的后面插入, 返回插入的结点的地址, 插入失败, 返回end()
    void ListInsert(const T& elem, int idx);  
    // 插入元素, index为某个结点迭代器, 在该结点的后面插入, 返回插入的结点的地址, 插入失败, 返回end()
    void ListInsert(const T& elem, Node* idx);
    // 尾插入元素
    void push_back(const T& elem);
    // 头插入元素
    void push_front(const T& elem);
    // 打印所有元素
    void print_list(){
        Node* p = head;
        Node* q = p->next;
        if (Empty())
            cout << "链表为空" << endl;
        else
            cout << "链表不为空" << endl;
        cout << "链表长度为 : " << length << endl;
        cout << "链表内容 : "; 
        while(q){
            p = q->next;
            cout << q->data << " ";
            q = p;
        }
        cout << endl;
    }
};

template<class T> void LinkedList<T>::Clear(){
/*
    删除所有Node, 不包括头结点, 尾结点
    两种方式 :
        1. 从前往后遍历链表, 通过下一个位置的是否为空, 或者下一个结点是否为尾结点来标志着遍历结束
        2. 从后往前遍历链表, 通过尾结点和头结点是否重合, 来标志遍历结束
*/
    // Node* p = head;
    // Node* q = p->next;

    // // 通过下一个结点是否为空结点来遍历链表, 从前往后删除链表
    // while(q){
    //     p = q->next;
    //     delete q;
    //     q = p;
    // }


    // 通过尾结点是否和头结点重合来遍历整个链表, 从后往前删除链表
    while(head != tail){
        Node* p = tail->prev;
        delete tail;
        tail = p;
    }

    head->next = nullptr;
    tail = head;
    length = 0;
}

template<class T> void LinkedList<T>::push_back(const T& elem){
/*
    尾插法, 在最后一个元素的位置添加新的结点
*/
    Node* newNode = new Node(elem);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    length++;
}

template<class T> void LinkedList<T>::push_front(const T& elem){
/*
    头插法, 在第一个结点与头结点之间的位置添加新的结点
*/
    Node* newNode = new Node(elem);
    newNode->next = head->next;
    head->next = newNode;
    newNode->prev = head;
    // 如果链表不是空的, 则让原先第一个结点的前驱指向当前结点
    // 链表为空的时候则需要移动尾结点
    if(newNode->next)
        newNode->next->prev = newNode;
    else
        tail = newNode;
    length++;
}

void unit_test_base_operation(){
    LinkedList<int> list;
    cout << "*******测试Push*******" <<endl;
    list.push_front(1);
    list.push_back(4);
    list.push_front(3);
    list.print_list();
    cout << "*******测试删除*******" <<endl;
    list.Clear();
    list.print_list();
    cout << "*******基础操作集测试完成*******\n" << endl;

}

int main(){
    unit_test_base_operation();
    return 0;
}
