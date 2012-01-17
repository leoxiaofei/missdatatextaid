#ifndef INSERTSTRING_H
#define INSERTSTRING_H

#include "RuleBase.h"


class InsertString : public RuleBase
{
    public:
        InsertString();
        virtual ~InsertString();
        void SetArg(const wxString & strString, int nPer, int nStart, int nInsertRepeat);
        virtual wxString GetTitle();
        virtual wxString GetDescription();
        virtual void ResetState();
        virtual int GetType(){return 2;}

        int GetPer(){return m_nPer;}
        int GetStart(){return m_nStart;}
        int GetInsertRepeat(){return m_nInsertRepeat;}
        wxString &GetString(){return m_strString;}
    protected:
        virtual wxString GetReplaceText();

    private:
        int m_nPer;
        int m_nStart;
        int m_nInsertRepeat;
        wxString m_strString;

        int m_nCurrentPer;
        int m_nRemain;
        int m_nRepeat;
};

#endif // INSERTSTRING_H
