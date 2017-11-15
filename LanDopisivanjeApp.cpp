/***************************************************************
 * Name:      LanDopisivanjeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Milos Milovanovic (milos_silni@yahoo.com)
 * Created:   2008-08-18
 * Copyright: Milos Milovanovic (milosm.awardspace.com)
 * License:
 **************************************************************/

#include "LanDopisivanjeApp.h"

//(*AppHeaders
#include "LanDopisivanjeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LanDopisivanjeApp);

bool LanDopisivanjeApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LanDopisivanjeFrame* Frame = new LanDopisivanjeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
