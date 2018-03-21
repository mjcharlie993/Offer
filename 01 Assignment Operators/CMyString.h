#include <string.h>

class CMyString
{
public:
    CMyString(const char* pData = NULL);
    CMyString(const CMyString& str);
    CMyString& operator=(const CMyString& rhs);
    ~CMyString();

private:
    char* m_pData;
};
