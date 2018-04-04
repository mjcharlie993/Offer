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