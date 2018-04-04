# 07 用两个栈实现队列
## 题目
> 用两个栈实现队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。 

## 思路
* 队尾插入结点 

在stack1中直接压入结点。

* 队头删除结点

当stack2中不为空时，在stack2的栈顶元素是最先进入队列的元素，可以弹出。  
如果stack2为空，我们把stack1中的元素逐个压入stack2，由于先进入队列的元素被压到stack1的底端，经弹出和压入之后就处于stack2的顶端了，又可以直接弹出。

## 注意
* 模板类及模板函数的编写

## 参考代码
```C++
// QueueWithTwoStacks.h
template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
```
```C++
#include "QueueWithTwoStacks.h"

template <typename T>
void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (!stack1.empty())
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.size() == 0)
        throw new exception("Queue is empty");
    T head = stack2.top();
    stack2.pop();
    
    return head;
}
```
# 拓展
> 用两个队列实现一个栈

## 思路
* 入栈

如果两个queue都为空，则把新元素压入queue1

如果两个queue中其一为空，则把新元素压入非空的那个queue

不存在两个queue都非空的情况

* 出栈

将非空queue中的前n-1个元素放入另一个空queue中，将最后一个元素弹出后返回其值。

## 参考代码
```C++
// QueueWithTwoStacks.h
template <typename T>
class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void appendElement(const T& node);
    T popElement();
private:
    queue<T> queue1;
    queue<T> queue2;
};
```
```C++
#include "QueueWithTwoStacks.h"
template <typename T>
void CStack<T>::appendElement(const T& element)
{
	if (queue1.empty() && queue2.empty())
		queue1.push(element);
	else if (queue1.empty() && !queue2.empty())
		queue2.push(element);
	else if (queue2.empty() && !queue1.empty())
		queue1.push(element);
}

template <typename T>
T CStack<T>::popElement()
{
    T node;
    if (queue2.size() <= 0)
    {
        while (queue1.size() > 1)
        {
            T& data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }
        node = queue1.front();
        queue1.pop();
    }
    else if (queue1.size() <= 0)
    {
        while (queue2.size() > 1)
        {
            T& data = queue2.front();
            queue2.pop();
            queue1.push(data);
        }
        node = queue2.front();
        queue2.pop(); 
    }
    return node;
}
```
