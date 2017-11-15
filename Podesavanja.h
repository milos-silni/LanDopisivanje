#ifndef PODESAVANJA_H
#define PODESAVANJA_H

//(*Headers(Podesavanja)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "LanDopisivanjeMain.h"

class Podesavanja: public wxDialog
{
	public:

		Podesavanja(wxWindow* parent, wxString p,wxString i,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Podesavanja();
		void SetOsnFrame(LanDopisivanjeFrame *f);

		//(*Declarations(Podesavanja)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxTextCtrl* port;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxStaticText* StaticText5;
		wxTextCtrl* interval;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(Podesavanja)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		//*)

	private:

		//(*Handlers(Podesavanja)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		LanDopisivanjeFrame *m_landopisivanjeframe;

		DECLARE_EVENT_TABLE()
};

#endif
