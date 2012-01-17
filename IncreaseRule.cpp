#include "IncreaseRule.h"

IncreaseRule::IncreaseRule()
{
    //ctor
}

IncreaseRule::~IncreaseRule()
{
    //dtor
}

void IncreaseRule::SetArg(char cStart, char cBegin, char cEnd, int nSpan, int nRepeat, const wxString &strPlaceholder)
{
    m_bNumber = false;
    m_nStart = cStart;
    m_nBegin = cBegin;
    m_nEnd = cEnd;
    m_nSpan = nSpan;
    m_nRepeat = nRepeat;
    m_strPlaceholder = strPlaceholder;
    ResetState();
}

void IncreaseRule::SetArg(int nStart, int nBegin, int nEnd, int nSpan, int nRepeat, const wxString &strPlaceholder)
{
    m_bNumber = true;
    m_nStart = nStart;
    m_nBegin = nBegin;
    m_nEnd = nEnd;
    m_nSpan = nSpan;
    m_nRepeat = nRepeat;
    m_strPlaceholder = strPlaceholder;
    ResetState();
}

void IncreaseRule::ResetState()
{
    m_nCurrent = m_nStart;
    m_nCurrentRepeat = 1;
}

wxString IncreaseRule::GetReplaceText()
{
    wxString ret;
    ret.Printf(m_bNumber?_T("%d"):_T("%c"),m_nCurrent);
    int nLeft = m_strPlaceholder.size() - ret.size();
    if( nLeft > 0)
    {
        ret.Prepend(m_strPlaceholder.Left(nLeft));
    }
    if(m_nBegin == m_nEnd && m_bNumber)
    {
        if(m_nCurrentRepeat == m_nRepeat)
        {
            m_nCurrent += m_nSpan;
            m_nCurrentRepeat = 1;
        }
        else
        {
            ++m_nCurrentRepeat;
        }
    }
    else
    {
        if(m_nCurrentRepeat == m_nRepeat)
        {
            m_nCurrent += m_nSpan;
            if( m_nBegin > m_nEnd ? m_nCurrent < m_nEnd : m_nCurrent > m_nEnd)
            {
                m_nCurrent = m_nBegin;
            }
            m_nCurrentRepeat = 1;
        }
        else
        {
            ++m_nCurrentRepeat;
        }
    }
    return ret;
}

wxString IncreaseRule::GetTitle()
{
    wxString ret;
    ret.Printf(wxT("递增序列"));
    return ret;
}


wxString IncreaseRule::GetDescription()
{
    wxString ret;
    ret.Printf(wxT("%s类型 每%d条记录%s%d，范围%s"),
               m_bNumber?wxT("数字"):wxT("字母"),
               m_nRepeat,
               m_nSpan>0?wxT("递增"):wxT("递减"),
               m_nSpan,
               wxString::Format(m_bNumber?wxT("%d~%d"):wxT("%c~%c"),m_nBegin,m_nEnd).c_str());
    return ret;
}

