# 单例模式
## 定义
* 确保一个特定类的一个对象，只能创建一次
## 示例代码
> 创造单例，要确保构造函数私有化，复制构造，复制赋值应该禁用，创造一个静态变量来存此单例。
```C++
#include <iostream>
#include <string>
#include <cassert>

class President
{
public:
    static President& getInstance()
    {
        static President instance;
        return instance;
    }
    President(const President&) = delete;
    President& operator=(const President&) = delete;
private:
    President() {}
};
```
> 测试代码
```C++
#include "Singleton.h"

int main()
{
    const President& president1 = President::getInstance();
    const President& president2 = President::getInstance();

    // same address, point to same object.
    assert(&president1 == &president2);
}
```
