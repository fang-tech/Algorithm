# Introduction to Algorithm

##  Chapter 10 : 基础数据结构

### 10.1 : 栈和队列

#### 栈

- 上溢 : 栈的上溢为栈满的时候, 仍然PUSH元素

  - ```
    Stack.top + 1 == length
    ```

- 下溢 : 栈为空的时候仍然POP元素

  - ```
    Stack.isEmpty == True
    ```

#### 队列

- 上溢 : 队列满的时候, 仍然ENQUEUE元素

  - ```
    (Q.tail + 1) % length == Q.head

- 下溢 : 队列为空的时候, 仍然DEQUEUE元素

  - ```
    Q.head == Q.tail
    ```

#### 使用栈实现队列与使用队列实现栈

- 两个栈实现队列

  1. 先将s1的数据逐个pop至s2
  2. 将新元素push入s2
  3. 将s2的数据pop至s1

- 两个队列实现栈

  1. 将新元素enqueue入q2

  2. 先将q1的数据逐个enqueue至q2
  3. 将q2的数据逐个enqueue至q1

- 本质 :

  - 不改变POP, 改变PUSH
  - 通过Stack将数据"灌入"另一个容器的时候, 数据的顺序倒置, Queue将数据"灌入"另一个容器的时候, 数据的顺序不变, 从而将新的数据插入到头(尾)

### 链表

- 