#ifndef INCREASERULE_H
#define INCREASERULE_H

#include "RuleBase.h"


class IncreaseRule : public RuleBase
{
public:
    IncreaseRule();
    virtual ~IncreaseRule();
    void SetArg(int nStart, int nBegin, int nEnd, int nSpan, int nRepeat, const wxString &strPlaceholder);
    void SetArg(char cStart, char cBegin, char cEnd, int nSpan, int nRepeat, const wxString &strPlaceholder);
    virtual wxString GetTitle();
    virtual wxString GetDescription();
    virtual void ResetState();
    virtual int GetType(){return 0;}

    int GetStart(){return m_nStart;}
    int GetBegin(){return m_nBegin;}
    int GetEnd(){return m_nEnd;}
    int GetSpan(){return m_nSpan;}
    int GetRepeat(){return m_nRepeat;}
    wxString& GetPlaceholder(){return m_strPlaceholder;}
    int IsNumber(){return m_bNumber;}

protected:
    virtual wxString GetReplaceText();

private:
    int m_nStart;
    int m_nBegin;
    int m_nEnd;
    int m_nSpan;
    int m_nRepeat;
    wxString m_strPlaceholder;

    bool m_bNumber;

    int m_nCurrent;
    int m_nCurrentRepeat;
};

#endif // INCREASERULE_H
