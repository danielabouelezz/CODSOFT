/***************************************************************
 * Name:      LibraryManagementSystemApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Daniel Abou ElEzz (abouelezzdaniel@gmail.com)
 * Created:   2024-05-24
 * Copyright: Daniel Abou ElEzz ()
 * License:
 **************************************************************/

#include "LibraryManagementSystemApp.h"

//(*AppHeaders
#include "LibraryManagementSystemMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LibraryManagementSystemApp);

bool LibraryManagementSystemApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LibraryManagementSystemFrame* Frame = new LibraryManagementSystemFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
