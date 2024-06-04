/***************************************************************
 * Name:      LibraryManagementSystemMain.h
 * Purpose:   Defines Application Frame
 * Author:    Daniel Abou ElEzz (abouelezzdaniel@gmail.com)
 * Created:   2024-05-24
 * Copyright: Daniel Abou ElEzz ()
 * License:
 **************************************************************/

#ifndef LIBRARYMANAGEMENTSYSTEMMAIN_H
#define LIBRARYMANAGEMENTSYSTEMMAIN_H

//(*Headers(LibraryManagementSystemFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class LibraryManagementSystemFrame: public wxFrame
{
    public:

        LibraryManagementSystemFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LibraryManagementSystemFrame();

    private:

        //(*Handlers(LibraryManagementSystemFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(LibraryManagementSystemFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(LibraryManagementSystemFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LIBRARYMANAGEMENTSYSTEMMAIN_H
