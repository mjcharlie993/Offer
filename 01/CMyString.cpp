#include "CMyString.h"

CMyString::CMyString(const char* pData)
{
    if (pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData); 
    }
}

CMyString::CMyString(const CMyString& str)
{
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

// Junior
CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(rhs.m_pData) + 1];
    strcpy(m_pData, rhs.m_pData);
    return *this;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this == &rhs)
        return *this;
    char* pTemp = new char[strlen(rhs.m_pData) + 1];
    delete[] m_pData;
    m_pData = NULL;
    m_pData = pTemp;
    strcpy(m_pData, rhs.m_pData);
    return *this;
}

// Senior
CMyString& CMyString::operator=(const CMyString& rhs)
{
    if (this != &rhs)
    {
        CMyString tempStr(rhs);
        char* pStr = tempStr.m_pData;
        tempStr.m_pData = m_pData;
        m_pData = pStr;
    }
    return *this;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{

}
CMyString::~CMyString()
{
	delete[] m_pData;
}