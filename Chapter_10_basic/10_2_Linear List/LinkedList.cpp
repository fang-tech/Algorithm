#include <iostream>

using namespace std;

template<class T>
class LinkedList{
/*
    @author: 方天宇
    @date: 2024.07.29 - 2024.07.31
    @brief: 实现了双向带有头尾结点的链式存储, 并实现了该类的一些基础操作集和进阶操作集(合并, 反转, 是否有环)
    @todo: 迭代器, 符号重载, Travel函数
*/
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
    int len;

public: 
    // 构造函数
    LinkedList(){
        this->head = new Node();  
        this->tail = head;
        this->len = 0;
    }
    // 析构函数, 用于释放内存
    ~LinkedList(){
        Node* p = head;
        while (p){
            Node* q = p->next;
            delete p;
            p = q;
        }
    }

public: 
    // 迭代器类的定义, 用于遍历链表, 迭代器是对于指针的再一次封装, 
    // 为外部提供一个统一的访问接口, 在C++的STL库中, 是为了容器和STL算法的兼容
    // 这里懒得实现迭代器了, 写的有点累了, 点到为止, 不优化了
    
public: // 操作集 -> base operation
    Node* begin() const {
        return head;
    }  
    // 返回head结点地址
    Node* end() const {
        return tail;
    };
    bool isEmpty() const {
        if(head->next == nullptr)
            return true;
        else 
            return false;
    }
    int length() const {
        return len;
    }
    // 返回tail结点地址

    // 删除线性表中的所有元素
    void clear();  
    // 插入元素, index为int的时候, 在序号为idx的前面插入, 返回插入的结点的地址, 插入失败, 返回False
    bool insert(const T& elem, int idx);  
    // 尾插入元素
    void push_back(const T& elem);
    // 头插入元素
    void push_front(const T& elem);
    // 在链表中查找元素, 如果元素存在, 则返回idx, 如果不存在则返回-1, 这个只能返回第一个查找到的第一个结点的位置
    int find(const T& elem);
    // 删除指定位置的元素
    bool del(int idx);
    // 获取指定位置的元素的值
    T& at(int idx);
    // 打印所有元素
    void print_list(){
        Node* p = head;
        Node* q = p->next;
        if (isEmpty())
            cout << "链表为空" << endl;
        else
            cout << "链表不为空" << endl;
        cout << "链表长度为 : " << len << endl;
        cout << "链表内容 : "; 
        while(q){
            p = q->next;
            cout << q->data << " ";
            q = p;
        }
        cout << endl;
    }
public: // 操作集 -> advanced operation
    // 合并两个有序链表
    LinkedList<T> merge(const LinkedList<T>& other);
    // 反转链表
    void reverse();
    // 判断链表是不是环状的
    bool hasCircle();
};

template<class T> void LinkedList<T>::clear(){
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
    len = 0;
}

template<class T> void LinkedList<T>::push_back(const T& elem){
/*
    尾插法, 在最后一个元素的位置添加新的结点
*/
    Node* newNode = new Node(elem);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    len++;
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
    len++;
}

template<class T> bool LinkedList<T>::insert(const T& elem, int idx){
/*
    根据idx, 插入元素, 会将元素插入到idx位置的前面
*/
    // 给出idx超出范围
    if (idx < 0 || idx > len){
        // for test
        // {cout << "idx=" << idx << " 越界" << ", 当前len为" << len << endl;
        // cout << "插入失败" << endl;}
        return false;
    }
    // 找到idx位置的前一个结点
    Node* p = head;
    for (int i = 0; i < idx; i++, p=p->next){}
    // 如果该结点是最后一个结点
    if (p == tail)
        this->push_back(elem);
    // 如果是第一个结点
    else if (p == head){
        this->push_front(elem);
    }
    else {
        Node* newNode = new Node(elem);
        Node* q = p->next;
        p->next = newNode;
        newNode->next = q;
        q->prev = newNode;
        newNode->prev = p;
        len++;
    }
    // for test
    // {cout << elem <<"插入成功" << endl;}
    return true;
}

template<class T> bool LinkedList<T>::del(int idx){
/*
    根据idx, 删除元素, 处理越界
*/
    // 给出idx超出范围
    if (idx < 0 || idx >= len){
        // for test
        {cout << "idx=" << idx << " 越界" << ", 当前len为" << len << endl;
        cout << "删除失败" << endl;}
        return false;
    }
    // 链表为空
    if (this->isEmpty())
        return false;
    // 找到idx位置的结点
    Node* p = head;
    for (int i = 0; i <= idx; i++, p=p->next){}
    // 如果该结点是最后一个结点
    if (p == tail){
        Node* q = p->prev;
        delete p;
        q->next = nullptr;
        tail = q;
    }
    // 如果是第一个结点
    else if (p == head->next){
        head->next = p->next;
        delete p;
    }
    else {
        Node* q = p->prev;
        q->next = p->next;
        delete p;
        q->next->prev = q;
    }
    len--;
    // for test
    {this->print_list();}
    return true;
}

template<class T> int LinkedList<T>::find(const T& elem){
/*
    根据结点的值查找结点的索引
*/
    int idx = -1;
    Node* p = head->next;
    for (int i = 0; p; i++, p = p->next){
        if (p->data == elem){
            idx = i;
            break;
        }
    }
    return idx;
}

template<class T> T& LinkedList<T>::at(int idx){
/*
    根据结点的索引查找结点的数据, 该函数处理越界采取了异常处理模式
*/
    if (idx < 0 || idx >= len){
        // for test
        {cout << "idx=" << idx << " 越界" << ", 当前len为" << len << endl;
        cout << "查找失败" << endl;}
        throw std::out_of_range("Index out of range");
    }
    Node* p = head;
    for (int i = 0; i <= idx; i++, p=p->next){}
    return p->data;
}

template<class T> LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other){
/*
    将两个有序链表合并为一个链表, 时间复杂度 : O(m+n)
*/
    LinkedList<T> list;
    Node* p = this->head->next;
    Node* q = other.begin()->next;
    // 两个链表都没有被比较完的时候
    while (p && q){
        if (p->data >= q->data){
            list.push_back(q->data);
            q = q->next;
        } else {
            list.push_back(p->data);
            p = p->next;
        }
    }

    // 处理剩下的结点
    while (p){
        list.push_back(p->data);
        p = p->next;
    }

    while (q){
        list.push_back(q->data);
        q = q->next;
    }

    return list;
}

template<class T> void LinkedList<T>::reverse(){
/*
    反转链表, 使用效率最高的迭代法, 在这里, 假设链表的实现是单向的
    因为在双向链表上这个操作的实现很简单
*/
    // 空链表或者只有一个结点
    if (isEmpty() || len == 1)
        return;
    Node* prev = nullptr;
    Node* current = head->next;
    Node* next = current->next;

    tail = current;

    while (current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head->next = prev;
}

template<class T> bool LinkedList<T>::hasCircle(){
/*
    用于检测链表中是否出现了环, 使用快慢指针法
*/
    // 处理空链表的情况 
    if (head->next) return false;

    Node* fast = head->next;
    Node* slow = head->next;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow){
            return true;
        }
    }

    return false;
}

void unit_test_base_operation(){
    LinkedList<int> list;
    cout << "*******测试Push*******" <<endl;
    list.push_front(1);
    list.push_back(4);
    list.push_front(3);
    list.print_list();
    cout << "*******测试删除*******" <<endl;
    list.clear();
    list.print_list();
    cout << "*******测试插入与查找*******" << endl;
    list.push_front(1);
    list.push_back(4);
    list.push_front(3);
    list.insert(5, 4);
    list.insert(5, 3);
    list.insert(19, 0);
    list.print_list();
    cout << "元素19的idx为" << list.find(19) << endl;
    cout << "元素5的idx为" << list.find(5) << endl;
    cout << "元素80的idx为" << list.find(80) << endl;
    list.clear();
    list.print_list();
    list.insert(19, 0);
    list.print_list();
    cout << "*******测试删除*******" << endl;
    list.del(0);
    list.del(1);
    list.push_front(1);
    list.push_back(4);
    list.push_front(3);
    list.insert(5, 3);
    list.insert(19, 0);
    list.del(4);
    list.del(0);
    list.del(1);
    cout << "*******测试at*******" << endl;
    cout << list.at(0) << endl;
    cout << list.at(1) << endl;
    cout << "*******基础操作集测试完成*******\n" << endl;
}

void unit_test_advanced_operation(){
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(6);
    list.push_back(14);
    list.push_back(19);
    list.push_back(120);

    LinkedList<int> other;
    other.push_back(-1);
    other.push_back(0);
    other.push_back(0);
    other.push_back(18);
    
    cout << "*******测试合并有序链表*******" << endl;
    LinkedList<int> mergeList = list.merge(other);
    list.print_list();
    other.print_list();
    mergeList.print_list();

    mergeList.reverse();
    mergeList.print_list();
    cout << mergeList.hasCircle();
}

int main(){
    unit_test_base_operation();
    unit_test_advanced_operation();
    return 0;
}
