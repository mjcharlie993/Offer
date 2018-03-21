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

