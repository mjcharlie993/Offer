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