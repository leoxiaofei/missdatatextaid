#include "RanRule.h"

RanRule::RanRule()
{
    //ctor
}

RanRule::~RanRule()
{
    //dtor
}

/** @brief GetReplaceText
  *
  * @todo: document this function
  */
wxString RanRule::GetReplaceText()
{
    return wxString::Format(_T("%d"),rand() % (m_nRanMax - m_nRanMin + 1) + m_nRanMin);
}

/** @brief SetRange
  *
  * @todo: document this function
  */
void RanRule::SetRange(int nMin, int nMax)
{
    assert(nMin<=nMax);
    m_nRanMin = nMin;
    m_nRanMax = nMax;
}

wxString RanRule::GetTitle()
{
    wxString ret;
    ret.Printf(_T("随机数"));
    return ret;
}

wxString RanRule::GetDescription()
{
    wxString ret;
    ret.Printf(wxT("范围%d~%d"),m_nRanMin,m_nRanMax);
    return ret;
}
