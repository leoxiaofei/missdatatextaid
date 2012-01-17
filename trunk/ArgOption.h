#ifndef ARGOPTION_H
#define ARGOPTION_H

#include "GUIDialog.h"

class RuleBase;

class ArgOption : public ArgOptionBase
{
    public:
        ArgOption(wxDialog *dlg);
        virtual ~ArgOption();
        shared_ptr<RuleBase> GetRule();
        void SetRule(shared_ptr<RuleBase> & pRule);
    protected:
        virtual void OnRadioNumberClicked( wxCommandEvent& event );
		virtual void OnRadioCharClicked( wxCommandEvent& event );
		virtual void OnSpinBegin( wxSpinEvent& event );
		virtual void OnCharChoice( wxCommandEvent& event );
    private:
};

#endif // ARGOPTION_H
