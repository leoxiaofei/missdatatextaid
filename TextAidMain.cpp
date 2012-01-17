/***************************************************************
 * Name:      TextAidMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-01-18
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "TextAidMain.h"
#include "ArgOption.h"
#include <tr1/functional>
#include "RuleBase.h"
#include <wx/clipbrd.h>
#include <algorithm>
#include <wx/msgdlg.h>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

using namespace std::tr1::placeholders;

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }
    wxbuild << wxT("\n郭筱飞 http://www.leoxiaofei.com\n");
    wxbuild << wxT(__DATE__) << wxT(" ") << wxT(__TIME__);
    return wxbuild;
}

class TextAidDialog::TextAidDialogImpl
{
public:
    std::vector< shared_ptr<RuleBase> > m_vecRule;
};

TextAidDialog::TextAidDialog(wxDialog *dlg)
    : GUIDialog(dlg),
    m_pImpl(new TextAidDialogImpl)
{
    m_listArg->InsertColumn(0, _T("No."), wxLIST_FORMAT_LEFT, 45);
    m_listArg->InsertColumn(1, _T("规则名"), wxLIST_FORMAT_LEFT, 90);
    m_listArg->InsertColumn(2, _T("规则内容"), wxLIST_FORMAT_LEFT, m_listArg->GetSize().GetWidth()-90-50);
}

void TextAidDialog::OnArgListSize(wxSizeEvent& event)
{
    //event.GetSize().GetWidth()-90-45
    m_listArg->SetColumnWidth(2,event.GetSize().GetWidth()-90-50);
}

TextAidDialog::~TextAidDialog()
{
}

void TextAidDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void TextAidDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

/** @brief OnBtnBuildClick
  *
  * @todo: document this function
  */
void TextAidDialog::OnBtnBuildClick(wxCommandEvent& event)
{
    for_each(m_pImpl->m_vecRule.begin(),m_pImpl->m_vecRule.end(),std::tr1::mem_fn(&RuleBase::ResetState));
    std::vector<wxString> vecSrc = GetStringList(m_edtSrc->GetValue(),_T("\n"));
    std::vector<wxString> vecDes(vecSrc.size());
    int nCount = m_spCount->GetValue();
    while(nCount--)
    {
        std::vector<wxString> vecTmp(vecSrc);
        for_each(m_pImpl->m_vecRule.begin(),m_pImpl->m_vecRule.end(),std::tr1::bind(&RuleBase::RunReplace,_1,&vecTmp,1));
        for(std::vector<wxString>::size_type ix = 0; ix != vecDes.size(); ++ix)
        {
            vecDes[ix].Append(vecTmp[ix]);
            vecDes[ix].Append(nCount?_T("\n"):_T("\n\n"));
        }
    }

    if(m_cboxClear->GetValue())
    {
        m_edtResult->Clear();
    }

    wxString strResult;
    for(std::vector<wxString>::iterator itor = vecDes.begin(); itor != vecDes.end(); ++itor )
    {
        strResult.Append(*itor);
    }
    strResult = strResult.Trim();
    m_edtResult->SetValue(strResult);
    if(m_cboxCopy->GetValue())
    {
        CopyToClipboard(strResult);
    }
}

void TextAidDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("文本助手 雅静&成成 特别版"));
}

/** @brief OnBtnDelArgClick
  *
  * @todo: document this function
  */
void TextAidDialog::OnBtnDelArgClick(wxCommandEvent& event)
{
    long item = -1;
    item = m_listArg->GetNextItem(item,
                                wxLIST_NEXT_ALL,
                                wxLIST_STATE_SELECTED);
    if ( item == -1 )
        return;
    wxString strItem = m_listArg->GetItemText(item);
    std::wcout << item <<std::endl;
    m_listArg->DeleteItem(item);
    m_pImpl->m_vecRule.erase(m_pImpl->m_vecRule.begin() + item);
    ArrangeArgList(item);
    std::wcout << strItem.c_str() <<std::endl;
}

/** @brief OnBtnAddArgClick
  *
  * @todo: document this function
  */
void TextAidDialog::OnBtnAddArgClick(wxCommandEvent& event)
{
    ArgOption ArgDlg(this);
    if(ArgDlg.ShowModal() == wxID_OK)
    {
        m_pImpl->m_vecRule.push_back(ArgDlg.GetRule());
        int nRow = m_pImpl->m_vecRule.size();
        nRow = m_listArg->InsertItem(nRow-1,wxString::Format(_T("%d"),nRow));
        m_listArg->SetItem(nRow,1,m_pImpl->m_vecRule.back()->GetTitle());
        m_listArg->SetItem(nRow,2,m_pImpl->m_vecRule.back()->GetDescription());
    }
}

void TextAidDialog::OnBtnClearArgClick(wxCommandEvent& event)
{
    m_pImpl->m_vecRule.clear();
    m_listArg->DeleteAllItems();
}

void TextAidDialog::ArrangeArgList(int nStart)
{
    for(int ix = nStart; ix < m_listArg->GetItemCount(); ++ix)
    {
        m_listArg->SetItem(ix, 0, wxString::Format(_T("%d"),ix+1) );
    }
}

std::vector<wxString> TextAidDialog::GetStringList(const wxString& strDes, const wxString& strSplit)
{
    std::vector<wxString> ret;
    int nFind(0),nPreFind(0),len(0);

    while((nFind = strDes.find_first_of(strSplit,nPreFind)) != wxString::npos)
    {
        if((len = nFind - nPreFind) != 0)
        {
            ret.push_back(strDes.Mid(nPreFind,len));
        }
        nPreFind = nFind + 1;
    }
    if( nPreFind+1 != static_cast<int>(strDes.size()))
    {
        ret.push_back(strDes.Mid(nPreFind));
    }
    return ret;
}

void TextAidDialog::CopyToClipboard(const wxString& strText)
{
    wxClipboardLocker locker ;
    if ( !!locker )
    {
        if ( wxTheClipboard->Open() )
        {
            // 数据对象将被剪贴板释放,
            // 因此不在要你的应用程序中释放它们.
            wxTheClipboard->SetData( new wxTextDataObject ( strText ));
            wxTheClipboard->Close();
        }
    }
}

void TextAidDialog::OnArgListItemActivated(wxListEvent& event)
{
    //std::wcout<< event.GetIndex()<< std::endl;
    int nIndex = event.GetIndex();
    ArgOption ArgDlg(this);
    ArgDlg.SetRule(m_pImpl->m_vecRule[nIndex]);
    if(ArgDlg.ShowModal() == wxID_OK)
    {
        m_pImpl->m_vecRule[nIndex] = ArgDlg.GetRule();
        m_listArg->SetItem(nIndex,1,m_pImpl->m_vecRule[nIndex]->GetTitle());
        m_listArg->SetItem(nIndex,2,m_pImpl->m_vecRule[nIndex]->GetDescription());
    }
}
