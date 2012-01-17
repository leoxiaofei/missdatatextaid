#include "ArgOption.h"
#include "RanRule.h"
#include "IncreaseRule.h"
#include "InsertString.h"

ArgOption::ArgOption(wxDialog *dlg):
ArgOptionBase(dlg)
{
    //ctor
}

ArgOption::~ArgOption()
{
    //dtor
}

shared_ptr<RuleBase> ArgOption::GetRule()
{
    shared_ptr<RuleBase> pRule;
    switch(m_choiceArg->GetSelection())
    {
    case 0:
        pRule = shared_ptr<RuleBase>(new IncreaseRule);
        if(m_rbtnNumber->GetValue())
        {
            static_cast<IncreaseRule *>(pRule.get())->
            SetArg(m_spMStart->GetValue(),
               m_spBegin->GetValue(),
               m_spEnd->GetValue(),
               m_spSpan->GetValue(),
               m_spRepeat->GetValue(),
               m_edtPlaceholder->GetValue());
        }
        else
        {
            char cBase = m_chCapital->GetValue()?'A':'a';
            char cStart = cBase + m_chCStart->GetCurrentSelection();
            char cBegin = cBase + m_chBegin->GetCurrentSelection();
            char cEnd = cBase + m_chEnd->GetCurrentSelection();
            static_cast<IncreaseRule *>(pRule.get())->
            SetArg(cStart, cBegin, cEnd,
               m_spSpan->GetValue(),
               m_spRepeat->GetValue(),
               m_edtPlaceholder->GetValue());
        }
        break;
    case 1:
        pRule = shared_ptr<RuleBase>(new RanRule);
        static_cast<RanRule *>(pRule.get())->SetRange(m_spRanMin->GetValue(),m_spRanMax->GetValue());
        break;
    case 2:
        pRule = shared_ptr<RuleBase>(new InsertString);
        static_cast<InsertString *>(pRule.get())->
        SetArg(m_edtInsert->GetValue(),
               m_spPer->GetValue(),
               m_spStart->GetValue(),
               m_spInsertRepeat->GetValue());
        break;
    }
    return pRule;
}

void ArgOption::OnRadioNumberClicked(wxCommandEvent& event)
{
    m_chBegin->Hide();
    m_spBegin->Show();
    m_sizerBegin->RecalcSizes();

    m_spEnd->Show();
    m_chEnd->Hide();
    m_sizerEnd->RecalcSizes();

    m_spMStart->Show();
    m_chCStart->Hide();
    m_sizerStart->RecalcSizes();

    m_chCapital->Hide();
}

void ArgOption::OnRadioCharClicked(wxCommandEvent& event)
{
    m_spBegin->Hide();
    m_chBegin->Show();
    m_sizerBegin->RecalcSizes();

    m_spEnd->Hide();
    m_chEnd->Show();
    m_sizerEnd->RecalcSizes();

    m_spMStart->Hide();
    m_chCStart->Show();
    m_sizerStart->RecalcSizes();

    m_chCapital->Show();
}
void ArgOption::OnSpinBegin(wxSpinEvent& event)
{
    if(m_spBegin->GetValue() > m_spEnd->GetValue())
    {
        int nValue = m_spSpan->GetValue();
        m_spSpan->SetRange(-2000000000,-1);
        if(nValue > 0)
        {
            m_spSpan->SetValue(-nValue);
        }
    }
    else if(m_spBegin->GetValue() < m_spEnd->GetValue())
    {
        int nValue = m_spSpan->GetValue();
        m_spSpan->SetRange(1,2000000000);
        if(nValue < 0)
        {
            m_spSpan->SetValue(-nValue);
        }
    }
    else
    {
        m_spSpan->SetRange(-2000000000,2000000000);
    }
}

void ArgOption::OnCharChoice(wxCommandEvent& event)
{
    if(m_chBegin->GetSelection() > m_chEnd->GetSelection())
    {
        int nValue = m_spSpan->GetValue();
        m_spSpan->SetRange(-2000000000,-1);
        if(nValue > 0)
        {
            m_spSpan->SetValue(-nValue);
        }
    }
    else if(m_chBegin->GetSelection() < m_chEnd->GetSelection())
    {
        int nValue = m_spSpan->GetValue();
        m_spSpan->SetRange(1,2000000000);
        if(nValue < 0)
        {
            m_spSpan->SetValue(-nValue);
        }
    }
    else
    {
        m_spSpan->SetRange(-2000000000,2000000000);
    }
}

void ArgOption::SetRule(shared_ptr<RuleBase>& pRule)
{
    int nType = pRule->GetType();
    m_choiceArg->SetSelection(nType);
    switch(nType)
    {
    case 0:
        {
            IncreaseRule *p = static_cast<IncreaseRule *>(pRule.get());
            wxCommandEvent event;
            if(p->IsNumber())
            {
                m_rbtnNumber->SetValue(true);
                OnRadioNumberClicked(event);
                m_spMStart->SetValue(p->GetStart());
                m_spBegin->SetValue(p->GetBegin());
                m_spEnd->SetValue(p->GetEnd());
                m_edtPlaceholder->SetValue(p->GetPlaceholder());
            }
            else
            {
                m_rbtnChar->SetValue(true);
                OnRadioCharClicked(event);
                m_chCapital->SetValue(p->GetBegin() < 'a');
                char Base = p->GetBegin() < 'a'?'A':'a';
                m_chCStart->SetSelection(p->GetStart() - Base);
                m_chBegin->SetSelection(static_cast<int>(p->GetBegin() - Base));
                m_chEnd->SetSelection(static_cast<int>(p->GetEnd() - Base));
                m_edtPlaceholder->SetValue(p->GetPlaceholder());
            }
            m_spSpan->SetValue(p->GetSpan());
            m_spRepeat->SetValue(p->GetRepeat());
        }
        break;
    case 1:
        {
            RanRule *p = static_cast<RanRule *>(pRule.get());
            m_spRanMin->SetValue(p->GetRanMin());
            m_spRanMax->SetValue(p->GetRanMax());
        }
        break;
    case 2:
        {
            InsertString *p = static_cast<InsertString *>(pRule.get());
            m_edtInsert->SetValue(p->GetString());
            m_spPer->SetValue(p->GetPer());
            m_spStart->SetValue(p->GetStart());
            m_spInsertRepeat->SetValue(p->GetInsertRepeat());
        }
        break;
    }

}
