///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDialog__
#define __GUIDialog__

#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/choicebk.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			idBtnAbout = 1000,
			idBtnQuit,
		};
		
		wxTextCtrl* m_edtSrc;
		wxButton* m_btnAddArg;
		wxButton* m_btnDelArg;
		
		wxButton* m_btnClearArg;
		wxListCtrl* m_listArg;
		wxTextCtrl* m_edtResult;
		wxStaticText* m_txtCount;
		wxSpinCtrl* m_spCount;
		wxButton* m_btnBuild;
		wxCheckBox* m_cboxClear;
		wxCheckBox* m_cboxCopy;
		
		wxButton* BtnAbout;
		wxButton* BtnQuit;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnBtnAddArgClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnDelArgClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnClearArgClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnArgListItemActivated( wxListEvent& event ) { event.Skip(); }
		virtual void OnArgListSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnBtnBuildClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("文本助手 雅静&成成 特别版"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 611,500 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~GUIDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ArgOptionBase
///////////////////////////////////////////////////////////////////////////////
class ArgOptionBase : public wxDialog 
{
	private:
	
	protected:
		wxChoicebook* m_choiceArg;
		wxPanel* m_panel1;
		wxRadioButton* m_rbtnNumber;
		
		wxRadioButton* m_rbtnChar;
		wxCheckBox* m_chCapital;
		wxStaticText* m_txtMStart;
		wxBoxSizer* m_sizerStart;
		wxSpinCtrl* m_spMStart;
		wxChoice* m_chCStart;
		wxStaticText* m_txtPlaceholder;
		wxTextCtrl* m_edtPlaceholder;
		wxStaticText* m_txtBegin;
		wxBoxSizer* m_sizerBegin;
		wxSpinCtrl* m_spBegin;
		wxChoice* m_chBegin;
		wxStaticText* m_txtEnd;
		wxBoxSizer* m_sizerEnd;
		wxSpinCtrl* m_spEnd;
		wxChoice* m_chEnd;
		wxStaticText* m_txtSpan;
		wxSpinCtrl* m_spSpan;
		wxStaticText* m_txtRepeat;
		wxSpinCtrl* m_spRepeat;
		wxPanel* m_panel2;
		wxStaticText* m_txtRanMin;
		wxSpinCtrl* m_spRanMin;
		wxStaticText* m_txtRanMax;
		wxSpinCtrl* m_spRanMax;
		wxPanel* m_panel3;
		wxStaticText* m_txtFrom;
		wxSpinCtrl* m_spStart;
		wxStaticText* m_txtStart;
		wxStaticText* m_txtPer;
		wxSpinCtrl* m_spPer;
		wxStaticText* m_txtDescription1;
		wxStaticText* m_txtDescription2;
		wxSpinCtrl* m_spInsertRepeat;
		wxStaticText* m_txtDescription3;
		wxTextCtrl* m_edtInsert;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioNumberClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRadioCharClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinBegin( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnCharChoice( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ArgOptionBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Option"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 349,260 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~ArgOptionBase();
	
};

#endif //__GUIDialog__
