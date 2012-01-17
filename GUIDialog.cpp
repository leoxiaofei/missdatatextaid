///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIDialog.h"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("输入") ), wxVERTICAL );
	
	m_edtSrc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	sbSizer1->Add( m_edtSrc, 2, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("参数") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_btnAddArg = new wxButton( this, wxID_ANY, wxT("添加参数"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnAddArg, 0, wxALL, 5 );
	
	m_btnDelArg = new wxButton( this, wxID_ANY, wxT("删除参数"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnDelArg, 0, wxALL, 5 );
	
	
	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnClearArg = new wxButton( this, wxID_ANY, wxT("清空参数"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnClearArg, 0, wxALL, 5 );
	
	sbSizer3->Add( bSizer6, 0, wxEXPAND, 5 );
	
	m_listArg = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL );
	sbSizer3->Add( m_listArg, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer1->Add( sbSizer3, 3, wxEXPAND, 5 );
	
	bSizer3->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer3, 2, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("输出") ), wxVERTICAL );
	
	m_edtResult = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	sbSizer2->Add( m_edtResult, 1, wxALL|wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_txtCount = new wxStaticText( this, wxID_ANY, wxT("记录数："), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtCount->Wrap( -1 );
	bSizer2->Add( m_txtCount, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spCount = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 200000000, 15 );
	bSizer2->Add( m_spCount, 1, wxALL, 5 );
	
	m_btnBuild = new wxButton( this, wxID_ANY, wxT("生成"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnBuild, 0, wxALL, 5 );
	
	m_cboxClear = new wxCheckBox( this, wxID_ANY, wxT("自动清空"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cboxClear->SetValue(true); 
	bSizer2->Add( m_cboxClear, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_cboxCopy = new wxCheckBox( this, wxID_ANY, wxT("自动复制"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cboxCopy->SetValue(true); 
	bSizer2->Add( m_cboxCopy, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	BtnAbout = new wxButton( this, idBtnAbout, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnAbout, 0, wxALL, 5 );
	
	BtnQuit = new wxButton( this, idBtnQuit, wxT("&Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( BtnQuit, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	m_btnAddArg->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnAddArgClick ), NULL, this );
	m_btnDelArg->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnDelArgClick ), NULL, this );
	m_btnClearArg->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnClearArgClick ), NULL, this );
	m_listArg->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( GUIDialog::OnArgListItemActivated ), NULL, this );
	m_listArg->Connect( wxEVT_SIZE, wxSizeEventHandler( GUIDialog::OnArgListSize ), NULL, this );
	m_btnBuild->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnBuildClick ), NULL, this );
	BtnAbout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	m_btnAddArg->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnAddArgClick ), NULL, this );
	m_btnDelArg->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnDelArgClick ), NULL, this );
	m_btnClearArg->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnClearArgClick ), NULL, this );
	m_listArg->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( GUIDialog::OnArgListItemActivated ), NULL, this );
	m_listArg->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GUIDialog::OnArgListSize ), NULL, this );
	m_btnBuild->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnBtnBuildClick ), NULL, this );
	BtnAbout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnAbout ), NULL, this );
	BtnQuit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIDialog::OnQuit ), NULL, this );
	
}

ArgOptionBase::ArgOptionBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_choiceArg = new wxChoicebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panel1 = new wxPanel( m_choiceArg, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 2, 4, 0, 0 );
	
	m_rbtnNumber = new wxRadioButton( m_panel1, wxID_ANY, wxT("数值类型"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbtnNumber->SetValue( true ); 
	gSizer3->Add( m_rbtnNumber, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_rbtnChar = new wxRadioButton( m_panel1, wxID_ANY, wxT("字母类型"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_rbtnChar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_chCapital = new wxCheckBox( m_panel1, wxID_ANY, wxT("大写"), wxDefaultPosition, wxDefaultSize, 0 );
	m_chCapital->SetValue(true); 
	m_chCapital->Hide();
	
	gSizer3->Add( m_chCapital, 0, wxALL, 5 );
	
	m_txtMStart = new wxStaticText( m_panel1, wxID_ANY, wxT("开始值"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtMStart->Wrap( -1 );
	gSizer3->Add( m_txtMStart, 0, wxALL, 5 );
	
	m_sizerStart = new wxBoxSizer( wxVERTICAL );
	
	m_spMStart = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -2000000000, 2000000000, 1 );
	m_sizerStart->Add( m_spMStart, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_chCStartChoices[] = { wxT("A"), wxT("B"), wxT("C"), wxT("D"), wxT("E"), wxT("F"), wxT("G"), wxT("H"), wxT("I"), wxT("J"), wxT("K"), wxT("L"), wxT("M"), wxT("N"), wxT("O"), wxT("P"), wxT("Q"), wxT("R"), wxT("S"), wxT("T"), wxT("U"), wxT("V"), wxT("W"), wxT("X"), wxT("Y"), wxT("Z") };
	int m_chCStartNChoices = sizeof( m_chCStartChoices ) / sizeof( wxString );
	m_chCStart = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chCStartNChoices, m_chCStartChoices, 0 );
	m_chCStart->SetSelection( 0 );
	m_chCStart->Hide();
	
	m_sizerStart->Add( m_chCStart, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( m_sizerStart, 1, wxEXPAND, 5 );
	
	m_txtPlaceholder = new wxStaticText( m_panel1, wxID_ANY, wxT("占位符"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtPlaceholder->Wrap( -1 );
	gSizer3->Add( m_txtPlaceholder, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_edtPlaceholder = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_edtPlaceholder, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( bSizer14, 1, wxEXPAND, 5 );
	
	m_txtBegin = new wxStaticText( m_panel1, wxID_ANY, wxT("起始值"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtBegin->Wrap( -1 );
	gSizer3->Add( m_txtBegin, 0, wxALL, 5 );
	
	m_sizerBegin = new wxBoxSizer( wxVERTICAL );
	
	m_spBegin = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -2000000000, 2000000000, 1 );
	m_sizerBegin->Add( m_spBegin, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_chBeginChoices[] = { wxT("A"), wxT("B"), wxT("C"), wxT("D"), wxT("E"), wxT("F"), wxT("G"), wxT("H"), wxT("I"), wxT("J"), wxT("K"), wxT("L"), wxT("M"), wxT("N"), wxT("O"), wxT("P"), wxT("Q"), wxT("R"), wxT("S"), wxT("T"), wxT("U"), wxT("V"), wxT("W"), wxT("X"), wxT("Y"), wxT("Z") };
	int m_chBeginNChoices = sizeof( m_chBeginChoices ) / sizeof( wxString );
	m_chBegin = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chBeginNChoices, m_chBeginChoices, 0 );
	m_chBegin->SetSelection( 0 );
	m_chBegin->Hide();
	
	m_sizerBegin->Add( m_chBegin, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( m_sizerBegin, 1, wxEXPAND, 5 );
	
	m_txtEnd = new wxStaticText( m_panel1, wxID_ANY, wxT("终止值"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtEnd->Wrap( -1 );
	gSizer3->Add( m_txtEnd, 0, wxALL, 5 );
	
	m_sizerEnd = new wxBoxSizer( wxVERTICAL );
	
	m_spEnd = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -2000000000, 2000000000, 1 );
	m_sizerEnd->Add( m_spEnd, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_chEndChoices[] = { wxT("A"), wxT("B"), wxT("C"), wxT("D"), wxT("E"), wxT("F"), wxT("G"), wxT("H"), wxT("I"), wxT("J"), wxT("K"), wxT("L"), wxT("M"), wxT("N"), wxT("O"), wxT("P"), wxT("Q"), wxT("R"), wxT("S"), wxT("T"), wxT("U"), wxT("V"), wxT("W"), wxT("X"), wxT("Y"), wxT("Z") };
	int m_chEndNChoices = sizeof( m_chEndChoices ) / sizeof( wxString );
	m_chEnd = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chEndNChoices, m_chEndChoices, 0 );
	m_chEnd->SetSelection( 25 );
	m_chEnd->Hide();
	
	m_sizerEnd->Add( m_chEnd, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( m_sizerEnd, 1, wxEXPAND, 5 );
	
	m_txtSpan = new wxStaticText( m_panel1, wxID_ANY, wxT("跨度"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtSpan->Wrap( -1 );
	gSizer3->Add( m_txtSpan, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_spSpan = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -2000000000, 2000000000, 1 );
	bSizer11->Add( m_spSpan, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( bSizer11, 1, wxEXPAND, 5 );
	
	m_txtRepeat = new wxStaticText( m_panel1, wxID_ANY, wxT("重复"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtRepeat->Wrap( -1 );
	gSizer3->Add( m_txtRepeat, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_spRepeat = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 2000000000, 1 );
	bSizer12->Add( m_spRepeat, 0, wxALL|wxEXPAND, 5 );
	
	gSizer3->Add( bSizer12, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( gSizer3 );
	m_panel1->Layout();
	gSizer3->Fit( m_panel1 );
	m_choiceArg->AddPage( m_panel1, wxT("递增序列"), true );
	m_panel2 = new wxPanel( m_choiceArg, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_txtRanMin = new wxStaticText( m_panel2, wxID_ANY, wxT("最小值"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtRanMin->Wrap( -1 );
	gSizer1->Add( m_txtRanMin, 0, wxALL, 5 );
	
	m_spRanMin = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	gSizer1->Add( m_spRanMin, 0, wxALL, 5 );
	
	m_txtRanMax = new wxStaticText( m_panel2, wxID_ANY, wxT("最大值"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtRanMax->Wrap( -1 );
	gSizer1->Add( m_txtRanMax, 0, wxALL, 5 );
	
	m_spRanMax = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 65535 );
	gSizer1->Add( m_spRanMax, 0, wxALL, 5 );
	
	m_panel2->SetSizer( gSizer1 );
	m_panel2->Layout();
	gSizer1->Fit( m_panel2 );
	m_choiceArg->AddPage( m_panel2, wxT("随机数"), false );
	m_panel3 = new wxPanel( m_choiceArg, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_txtFrom = new wxStaticText( m_panel3, wxID_ANY, wxT("从"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtFrom->Wrap( -1 );
	bSizer10->Add( m_txtFrom, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spStart = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 2000000000, 1 );
	bSizer10->Add( m_spStart, 1, wxALL, 5 );
	
	m_txtStart = new wxStaticText( m_panel3, wxID_ANY, wxT("开始"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtStart->Wrap( -1 );
	bSizer10->Add( m_txtStart, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txtPer = new wxStaticText( m_panel3, wxID_ANY, wxT("每隔"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtPer->Wrap( -1 );
	bSizer10->Add( m_txtPer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spPer = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 2000000000, 3 );
	bSizer10->Add( m_spPer, 1, wxALL, 5 );
	
	m_txtDescription1 = new wxStaticText( m_panel3, wxID_ANY, wxT("条记录"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtDescription1->Wrap( -1 );
	bSizer10->Add( m_txtDescription1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer7->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_txtDescription2 = new wxStaticText( m_panel3, wxID_ANY, wxT("重复"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtDescription2->Wrap( -1 );
	bSizer6->Add( m_txtDescription2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spInsertRepeat = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 2000000000, 1 );
	bSizer6->Add( m_spInsertRepeat, 0, wxALL, 5 );
	
	m_txtDescription3 = new wxStaticText( m_panel3, wxID_ANY, wxT("次 插入以下字符"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtDescription3->Wrap( -1 );
	bSizer6->Add( m_txtDescription3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer7->Add( bSizer6, 0, 0, 5 );
	
	m_edtInsert = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer7->Add( m_edtInsert, 1, wxALL|wxEXPAND, 5 );
	
	m_panel3->SetSizer( bSizer7 );
	m_panel3->Layout();
	bSizer7->Fit( m_panel3 );
	m_choiceArg->AddPage( m_panel3, wxT("插入字符"), false );
	bSizer5->Add( m_choiceArg, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	bSizer5->Add( m_sdbSizer1, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_rbtnNumber->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ArgOptionBase::OnRadioNumberClicked ), NULL, this );
	m_rbtnChar->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ArgOptionBase::OnRadioCharClicked ), NULL, this );
	m_spBegin->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ArgOptionBase::OnSpinBegin ), NULL, this );
	m_chBegin->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ArgOptionBase::OnCharChoice ), NULL, this );
	m_spEnd->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ArgOptionBase::OnSpinBegin ), NULL, this );
	m_chEnd->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ArgOptionBase::OnCharChoice ), NULL, this );
}

ArgOptionBase::~ArgOptionBase()
{
	// Disconnect Events
	m_rbtnNumber->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ArgOptionBase::OnRadioNumberClicked ), NULL, this );
	m_rbtnChar->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ArgOptionBase::OnRadioCharClicked ), NULL, this );
	m_spBegin->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ArgOptionBase::OnSpinBegin ), NULL, this );
	m_chBegin->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ArgOptionBase::OnCharChoice ), NULL, this );
	m_spEnd->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ArgOptionBase::OnSpinBegin ), NULL, this );
	m_chEnd->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ArgOptionBase::OnCharChoice ), NULL, this );
	
}
