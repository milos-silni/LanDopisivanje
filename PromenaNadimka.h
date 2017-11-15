#ifndef PROMENANADIMKA_H
#define PROMENANADIMKA_H

//(*Headers(PromenaNadimka)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "LanDopisivanjeMain.h"

class PromenaNadimka: public wxDialog
{
	public:

		PromenaNadimka(wxWindow* parent, wxString n,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PromenaNadimka();
        void SetOsnFrame(LanDopisivanjeFrame *f);

		//(*Declarations(PromenaNadimka)
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxTextCtrl* novi_nadimak;
		//*)
		LanDopisivanjeFrame *osnovni_frame;

	protected:

		//(*Identifiers(PromenaNadimka)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(PromenaNadimka)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
