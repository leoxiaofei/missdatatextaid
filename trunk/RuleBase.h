#ifndef RULEBASE_H
#define RULEBASE_H
#include <wx/string.h>

class RuleBase
{
    public:
        RuleBase();
        virtual ~RuleBase();
        void RunReplace(std::vector<wxString>* pVecSrc, int& order);
        virtual void ResetState();
        virtual wxString GetTitle() = 0;
        virtual wxString GetDescription() = 0;

        virtual int GetType(){return -1;}

    protected:
        virtual wxString GetReplaceText() = 0;

    private:

};

#endif // RULEBASE_H
