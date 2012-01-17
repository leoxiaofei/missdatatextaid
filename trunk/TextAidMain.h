/***************************************************************
 * Name:      TextAidMain.h
 * Purpose:   Defines Application Frame
 * Author:    leoxiaofei (fox88324@yahoo.com.cn)
 * Created:   2011-01-18
 * Copyright: leoxiaofei (http://www.leoxiaofei.com)
 * License:
 **************************************************************/

#ifndef TEXTAIDMAIN_H
#define TEXTAIDMAIN_H

#include "TextAidApp.h"

#include "GUIDialog.h"


class TextAidDialog: public GUIDialog
{
    class TextAidDialogImpl;
    public:
        TextAidDialog(wxDialog *dlg);
        ~TextAidDialog();
        static std::vector<wxString> GetStringList(const wxString &strDes,
                                                    const wxString & strSplit);
        static void CopyToClipboard(const wxString &strText);

    protected:
        void ArrangeArgList(int nStart = 0);

    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnBtnBuildClick( wxCommandEvent& event );
        virtual void OnBtnAddArgClick( wxCommandEvent& event );
		virtual void OnBtnDelArgClick( wxCommandEvent& event );
		virtual void OnBtnClearArgClick( wxCommandEvent& event );
        virtual void OnArgListItemActivated( wxListEvent& event );
        virtual void OnArgListSize( wxSizeEvent& event );

    private:
        shared_ptr<TextAidDialogImpl> m_pImpl;
};
#endif // TEXTAIDMAIN_H
