#include "Podesavanja.h"

//(*InternalHeaders(Podesavanja)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Podesavanja)
const long Podesavanja::ID_STATICTEXT1 = wxNewId();
const long Podesavanja::ID_TEXTCTRL1 = wxNewId();
const long Podesavanja::ID_STATICTEXT2 = wxNewId();
const long Podesavanja::ID_BUTTON1 = wxNewId();
const long Podesavanja::ID_BUTTON2 = wxNewId();
const long Podesavanja::ID_STATICTEXT3 = wxNewId();
const long Podesavanja::ID_TEXTCTRL2 = wxNewId();
const long Podesavanja::ID_STATICTEXT4 = wxNewId();
const long Podesavanja::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Podesavanja,wxDialog)
	//(*EventTable(Podesavanja)
	//*)
END_EVENT_TABLE()

Podesavanja::Podesavanja(wxWindow* parent, wxString p, wxString i, wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Podesavanja)
	Create(parent, id, _("Podešavanje"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(232,171));
	Move(wxDefaultPosition);
	SetFocus();
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Broj udp porta preko koga æe se slati i"), wxPoint(16,16), wxSize(208,13), 0, _T("ID_STATICTEXT1"));
	port = new wxTextCtrl(this, ID_TEXTCTRL1, _("port"), wxPoint(96,32), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ukoliko neznaš šta radiš nemoj ništa menjati."), wxPoint(8,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Potvrdi"), wxPoint(24,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetDefault();
	Button2 = new wxButton(this, ID_BUTTON2, _("Poništi"), wxPoint(120,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Automatski osveži kontakt listu na svakih"), wxPoint(16,64), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	interval = new wxTextCtrl(this, ID_TEXTCTRL2, _("interval"), wxPoint(16,80), wxSize(40,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("minuta."), wxPoint(64,88), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("primati poruke."), wxPoint(16,40), wxDefaultSize, 0, _T("ID_STATICTEXT5"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Podesavanja::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Podesavanja::OnButton2Click);
	//*)
	port->SetValue(p);
	interval->SetValue(i);
}

Podesavanja::~Podesavanja()
{
	//(*Destroy(Podesavanja)
	//*)
}

void Podesavanja::SetOsnFrame(LanDopisivanjeFrame *f)
{
    m_landopisivanjeframe = f;
}


void Podesavanja::OnButton1Click(wxCommandEvent& event)
{
    int p;
    port->GetValue().ToLong((long*)&p);
    int i;
    interval->GetValue().ToLong((long*)&i);
    m_landopisivanjeframe->SetPodesavanja(p, i);
    Close();
}

void Podesavanja::OnButton2Click(wxCommandEvent& event)
{
    Close();
}
