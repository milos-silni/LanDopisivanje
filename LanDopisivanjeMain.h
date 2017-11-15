/***************************************************************
 * Name:      LanDopisivanjeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Milos Milovanovic (milos_silni@yahoo.com)
 * Created:   2008-08-18
 * Copyright: Milos Milovanovic (milosm.awardspace.com)
 * License:
 **************************************************************/

#ifndef LANDOPISIVANJEMAIN_H
#define LANDOPISIVANJEMAIN_H

#include "MojCommandEvent.h"
//(*Headers(LanDopisivanjeFrame)
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/statusbr.h>
//*)
#include "Poruka.h"
#include <wx/imaglist.h>
#include "S_Poruka.h"
#include <wx/file.h>

struct Kontakt{
    wxString ipadresa;
    wxString nadimak;
    wxTreeItemId id;
};

class LanDopisivanjeFrame: public wxFrame
{
    public:

        LanDopisivanjeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LanDopisivanjeFrame();
        void SetNadimak( wxString n );
        void SetPodesavanja(int p, int i);
        bool PosaljiFajl();

    private:
        //(*Handlers(LanDopisivanjeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onlista_klijenataItemActivated(wxTreeEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)
        void Novi_prozor(MojCommandEvent &event);
		void dodaj_novi_kontakt( wxString nadimak, wxString ipadresa );
		int zahtev_tudji_nadimak( wxString ipadresa );
		void novi_prozor( wxCommandEvent &event );
		void Posalji(wxString ip, S_Poruka por);
		void citaj_podesavanja_reg();
		void Zatvori(wxCloseEvent& event);
		void OtvoriPodesavanja();
		void TogleStartup();
		void Pronadji_klijente();

        //(*Identifiers(LanDopisivanjeFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TREECTRL1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(LanDopisivanjeFrame)
        wxStaticText* nadimak_gore;
        wxMenuItem* MenuItem5;
        wxMenu* Menu3;
        wxButton* Button1;
        wxMenuItem* MenuItem4;
        wxBitmapButton* BitmapButton1;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxTreeCtrl* lista_klijenata;
        wxTimer Timer1;
        //*)
        Poruka *poruka[256];
        int br_p;
        int PORT;
        wxString Nadimak;
        Kontakt kontakt[256];
        int br_k;
        wxTreeItemId tiid;
        wxImageList *im_l;
        bool DodajNoviKontakt;
        int interval;
        wxMenuBar* m_menubar1;

        DECLARE_EVENT_TABLE()
};

#endif // LANDOPISIVANJEMAIN_H
