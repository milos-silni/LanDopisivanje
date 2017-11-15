#include <wx/richtext/richtextctrl.h>
#include "Poruka.h"

//(*InternalHeaders(Poruka)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <winsock.h>
#include <wx/msgdlg.h>
#include <wx/icon.h>


//(*IdInit(Poruka)
const long Poruka::ID_TEXTCTRL1 = wxNewId();
const long Poruka::ID_BUTTON1 = wxNewId();
const long Poruka::ID_STATICTEXT1 = wxNewId();
const long Poruka::ID_STATICTEXT2 = wxNewId();
const long Poruka::ID_RICHTEXTCTRL1 = wxNewId();
const long Poruka::ID_PANEL1 = wxNewId();
const long Poruka::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Poruka,wxFrame)
	//(*EventTable(Poruka)
	//*)
END_EVENT_TABLE()

#include "S_Poruka.h"

Poruka::Poruka(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Poruka)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(215,346));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(168,304), wxSize(224,312), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	poruka = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,248), wxSize(144,48), wxTE_MULTILINE|wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	poruka->SetFocus();
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Pošalji"), wxPoint(152,248), wxSize(56,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetDefault();
	Button1->SetFocus();
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Nadimak:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	nadimak_gore = new wxStaticText(Panel1, ID_STATICTEXT2, _("Miroslav <192.168.0.3>"), wxPoint(72,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	rt = new wxRichTextCtrl(Panel1,ID_RICHTEXTCTRL1,wxEmptyString,wxPoint(8,32),wxSize(200,216));
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	FD = new wxFileDialog(this, _("Izaberi fajl"), _("c:\\"), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&Poruka::OnporukaTextEnter);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Poruka::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Poruka::OnClose);
	//*)
	//ikonica
    SetIcon(wxICON(aaaa));
    rt->SetEditable(false);
}

Poruka::~Poruka()
{
	//(*Destroy(Poruka)
	//*)
}

void Poruka::dodaj_poruku( wxString poslao, wxString por )
{
    if(poslao.Length()>0 && por.Length()>0){
        wxString msg;
        wxDateTime now = wxDateTime::Now();
        msg = _("[") + now.FormatTime() + _("] ") + poslao + _(":\n");
        rt->BeginTextColour(wxColour(_("red")));
        rt->BeginBold();
        rt->AppendText( msg );
        rt->EndBold();
        rt->BeginTextColour(wxColour(_("black")));
        //--
        while(1){
            if(por.Left(3).CompareTo(_(":))"))==0){
                rt->WriteImage(wxBitmap(_("veliki_smesak"),wxBITMAP_TYPE_BMP_RESOURCE));
                por = por.Mid(3);
            }else if(por.Left(2).CompareTo(_(";)"))==0){
                rt->WriteImage(wxBitmap(_("smesak_namignuo"),wxBITMAP_TYPE_BMP_RESOURCE));
                por = por.Mid(2);
            }else if(por.Left(2).CompareTo(_(":("))==0){
                rt->WriteImage(wxBitmap(_("tuzan"),wxBITMAP_TYPE_BMP_RESOURCE));
                por = por.Mid(2);
            }else if(por.Left(2).CompareTo(_(":)"))==0){
                rt->WriteImage(wxBitmap(_("smesak"),wxBITMAP_TYPE_BMP_RESOURCE));
                por = por.Mid(2);
            }else{
                rt->AppendText(por.Left(1));
                por = por.Mid(1);
            }
            if(por.CompareTo(_(""))==0)
                break;
        }
        //--
        StatusBar1->SetStatusText(_("Poslednja poruka: ")+now.FormatTime());
        rt->Scroll(0,LONG_MAX);
        poruka->SetFocus();
    }
}

void Poruka::OnClose(wxCloseEvent& event)
{
    Hide();
}

void Poruka::Set_ipadresu( wxString ip )
{
    ipadresa = ip;
    nadimak_gore->SetLabel( Tudji_nadimak + _(" <") + ipadresa + _(">"));
}

void Poruka::OnButton1Click(wxCommandEvent& event)
{
    Posalji(poruka->GetValue()+_("\n"));
    dodaj_poruku( Moj_nadimak, poruka->GetValue()+_("\n") );
    poruka->Clear();
}

void Poruka::Set_PORT( int port )
{
    PORT = port;
}

void Poruka::Set_moj_nadimak( wxString n )
{
    Moj_nadimak = n;
}

void Poruka::Set_tudji_nadimak( wxString n )
{
    Tudji_nadimak = n;
    nadimak_gore->SetLabel( n + _(" <") + ipadresa + _(">"));
}

wxString Poruka::GetIpAdresu(){
    return ipadresa;
}


void Poruka::OnporukaTextEnter(wxCommandEvent& event)
{
    Posalji(poruka->GetValue());
    dodaj_poruku( Moj_nadimak, poruka->GetValue() );
    poruka->Clear();
    poruka->SetFocus();
}

bool Poruka::Posalji(wxString por)
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1, 1), &wsaData);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0){
        return false;
    }
    struct sockaddr_in adresa;
    adresa.sin_family = AF_INET;
    adresa.sin_port = htons(PORT);
    adresa.sin_addr.s_addr = inet_addr( ipadresa.mb_str(wxConvUTF8) );
    S_Poruka p;
    strcpy(p.nadimak,Moj_nadimak.mb_str(wxConvUTF8));
    strcpy(p.poruka,por.mb_str(wxConvUTF8));
    p.tip = Normalna;
    if (sendto(sock, (char*)&p, sizeof(S_Poruka), 0, (struct sockaddr *)&adresa, sizeof(struct sockaddr))<0){
        return false;
    }
    closesocket(sock);
    WSACleanup();
    return true;
}


void Poruka::OnBitmapButton1Click1(wxCommandEvent& event)
{
    FD->ShowModal();
    wxMessageBox(FD->GetPath());
}
