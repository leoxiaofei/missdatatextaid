/***************************************************************
 * Name:      TextAidApp.cpp
 * Purpose:   Code for Application Class
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

#include "TextAidApp.h"
#include "TextAidMain.h"

IMPLEMENT_APP(TextAidApp);

bool TextAidApp::OnInit()
{
    
    TextAidDialog* dlg = new TextAidDialog(0L);
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
