#include "InsertString.h"

InsertString::InsertString()
{
    //ctor
}

InsertString::~InsertString()
{
    //dtor
}
wxString InsertString::GetTitle()
{
    wxString ret;
    ret.Printf(wxT("插入字符串"));
    return ret;
}

wxString InsertString::GetDescription()
{
    wxString ret;
    ret.Printf(wxT("从%d条记录开始，每隔%d条记录重复插入%d个%s "),m_nStart,m_nPer,m_nInsertRepeat,m_strString.c_str());
    return ret;
}

void InsertString::SetArg(const wxString& strString, int nPer, int nStart, int nInsertRepeat)
{
    m_strString = strString;
    m_nPer = nPer;
    m_nStart = nStart;
    m_nInsertRepeat = nInsertRepeat;
    ResetState();
}

wxString InsertString::GetReplaceText()
{
    wxString ret;
    if(m_nCurrentPer == m_nPer)
    {
        ret = m_strString;
        if( --m_nRepeat < 1 )
        {
            m_nCurrentPer = 0;
            m_nRepeat = m_nInsertRepeat;
        }

    }
    else
    {
        ++m_nCurrentPer;
    }

    return ret;
}

void InsertString::ResetState()
{
    m_nCurrentPer = m_nPer - m_nStart + 1;
    m_nRepeat = m_nInsertRepeat;
}
