#ifndef RANRULE_H
#define RANRULE_H

#include "RuleBase.h"

class RanRule : public RuleBase
{
    public:
        RanRule();
        virtual ~RanRule();
        void SetRange(int nMin, int nMax);
        virtual wxString GetTitle();
        virtual wxString GetDescription();
        virtual int GetType(){return 1;}

        int GetRanMin(){return m_nRanMin;}
        int GetRanMax(){return m_nRanMax;}
    protected:
        virtual wxString GetReplaceText();

    private:
        int m_nRanMin;
        int m_nRanMax;
};

#endif // RANRULE_H
