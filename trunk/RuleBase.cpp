#include "RuleBase.h"
#include <iostream>

RuleBase::RuleBase()
{
    //ctor
}

RuleBase::~RuleBase()
{
    //dtor
}

/** @brief RunReplace
  *
  * @todo: document this function
  */
void RuleBase::RunReplace(std::vector<wxString>* pVecSrc, int& order)
{
    wxString strArgSrc,strArgDes;
    strArgSrc.Printf(_T("{%d}"),order++);

    bool bFind(false);
    for(std::vector<wxString>::iterator itor = pVecSrc->begin(); itor != pVecSrc->end(); ++itor)
    {
        if( wxNOT_FOUND != itor->Find(strArgSrc))
        {
            bFind = true;
            break;
        }
    }
    if(bFind)
    {
        strArgDes = GetReplaceText();
        for(std::vector<wxString>::iterator itor = pVecSrc->begin(); itor != pVecSrc->end(); ++itor)
        {
            itor->Replace(strArgSrc,strArgDes);
        }
    }
}

void RuleBase::ResetState()
{
}
