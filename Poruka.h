#ifndef PORUKA_H
#define PORUKA_H

//(*Headers(Poruka)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)


class Poruka: public wxFrame
{
	public:

		Poruka(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Poruka();
		void dodaj_poruku( wxString poslao, wxString poruka );
		void Set_ipadresu( wxString ip );
		void Set_PORT( int port );
        void Set_tudji_nadimak( wxString n );
        void Set_moj_nadimak( wxString n );
        wxString GetIpAdresu();

		//(*Declarations(Poruka)
		wxStaticText* nadimak_gore;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxRichTextCtrl* rt;
		wxTextCtrl* poruka;
		wxStatusBar* StatusBar1;
		wxFileDialog* FD;
		//*)

	protected:

		//(*Identifiers(Poruka)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_RICHTEXTCTRL1;
		static const long ID_PANEL1;
		static const long ID_STATUSBAR1;
		//*)
	private:

		//(*Handlers(Poruka)
		void OnClose(wxCloseEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnporukaTextEnter(wxCommandEvent& event);
		void OnCustom1Paint(wxPaintEvent& event);
		void OnBitmapButton1Click(wxCommandEvent& event);
		void OnBitmapButton1Click1(wxCommandEvent& event);
		//*)
		bool Poruka::Posalji(wxString por);

		wxString ipadresa;
		wxString Tudji_nadimak;
		wxString Moj_nadimak;
        int PORT;

		DECLARE_EVENT_TABLE()
};

#endif
