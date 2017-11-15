#include "PromenaNadimka.h"

//(*InternalHeaders(PromenaNadimka)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PromenaNadimka)
const long PromenaNadimka::ID_STATICTEXT1 = wxNewId();
const long PromenaNadimka::ID_TEXTCTRL1 = wxNewId();
const long PromenaNadimka::ID_BUTTON1 = wxNewId();
const long PromenaNadimka::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PromenaNadimka,wxDialog)
	//(*EventTable(PromenaNadimka)
	//*)
END_EVENT_TABLE()

PromenaNadimka::PromenaNadimka(wxWindow* parent, wxString n, wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PromenaNadimka)
	Create(parent, id, _("Promena nadimka"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(200,98));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ukucaj novi nadimak i potvrdi:"), wxPoint(24,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	novi_nadimak = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(16,32), wxSize(160,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Potvrdi"), wxPoint(16,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetFocus();
	Button2 = new wxButton(this, ID_BUTTON2, _("Poništi"), wxPoint(104,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PromenaNadimka::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PromenaNadimka::OnButton2Click);
	//*)
    novi_nadimak->SetValue(n);
}

PromenaNadimka::~PromenaNadimka()
{
	//(*Destroy(PromenaNadimka)
	//*)
}


void PromenaNadimka::OnButton1Click(wxCommandEvent& event)
{
    osnovni_frame->SetNadimak( novi_nadimak->GetValue() );
    Close();
}

void PromenaNadimka::SetOsnFrame(LanDopisivanjeFrame *f)
{
    osnovni_frame = f;
}

void PromenaNadimka::OnButton2Click(wxCommandEvent& event)
{
    Close();
}
