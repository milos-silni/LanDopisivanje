/***************************************************************
 * Name:      LanDopisivanjeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Milos Milovanovic (milos_silni@yahoo.com)
 * Created:   2008-08-18
 * Copyright: Milos Milovanovic (milosm.awardspace.com)
 * License:
 **************************************************************/

#include "LanDopisivanjeMain.h"
#include <wx/msgdlg.h>
#include <wx/icon.h>
#include <wx/msw/registry.h>
#include <wx/stdpaths.h>

//(*InternalHeaders(LanDopisivanjeFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(LanDopisivanjeFrame)
const long LanDopisivanjeFrame::ID_BITMAPBUTTON1 = wxNewId();
const long LanDopisivanjeFrame::ID_BUTTON1 = wxNewId();
const long LanDopisivanjeFrame::ID_STATICTEXT1 = wxNewId();
const long LanDopisivanjeFrame::ID_TREECTRL1 = wxNewId();
const long LanDopisivanjeFrame::ID_MENUITEM2 = wxNewId();
const long LanDopisivanjeFrame::ID_MENUITEM4 = wxNewId();
const long LanDopisivanjeFrame::ID_MENUITEM5 = wxNewId();
const long LanDopisivanjeFrame::ID_MENUITEM3 = wxNewId();
const long LanDopisivanjeFrame::ID_MENUITEM1 = wxNewId();
const long LanDopisivanjeFrame::idMenuAbout = wxNewId();
const long LanDopisivanjeFrame::ID_STATUSBAR1 = wxNewId();
const long LanDopisivanjeFrame::ID_TIMER1 = wxNewId();
//*)

DECLARE_EVENT_TYPE(wxEVT_NOVPROZOR_EVENT, -1)
DEFINE_EVENT_TYPE(wxEVT_NOVPROZOR_EVENT)

DECLARE_EVENT_TYPE(wxEVT_MOJ_COMMAND_EVENT, -1)
DEFINE_EVENT_TYPE(wxEVT_MOJ_COMMAND_EVENT)

BEGIN_EVENT_TABLE(LanDopisivanjeFrame,wxFrame)
    //(*EventTable(LanDopisivanjeFrame)
    //*)
    EVT_COMMAND  (7778, wxEVT_NOVPROZOR_EVENT, LanDopisivanjeFrame::novi_prozor)
    EVT_MOJ_COMMAND_EVENT  (7779, LanDopisivanjeFrame::Novi_prozor)

END_EVENT_TABLE()

#include "NitSlusaj.h"
NitSlusaj *nit1;
#include "TaskBarikonica.h"
TaskBarIkonica *sysikonica;
#include "PromenaNadimka.h"
#include "Podesavanja.h"

LanDopisivanjeFrame::LanDopisivanjeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LanDopisivanjeFrame)
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuItem* MenuItem2;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Lan dopisivanje"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetDefault();
    FlexGridSizer2->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(2, 1, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Promeni nadimak"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    nadimak_gore = new wxStaticText(this, ID_STATICTEXT1, _("Miloš"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer3->Add(nadimak_gore, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    lista_klijenata = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(186,172), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    FlexGridSizer1->Add(lista_klijenata, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Izlaz"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Fajl"));
    Menu3 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Osveži kontakt listu"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Pokreni program u pozadini"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Pokreni Dopisivanje pri paljenju raèunara"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuItem4);
    Menu3->AppendSeparator();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Podešavanja"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuBar1->Append(Menu3, _("Alati"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("O programu"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Pomoæ"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(1000, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LanDopisivanjeFrame::OnBitmapButton1Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LanDopisivanjeFrame::OnButton1Click);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&LanDopisivanjeFrame::Onlista_klijenataItemActivated);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanDopisivanjeFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&LanDopisivanjeFrame::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&LanDopisivanjeFrame::OnClose);
    //*)
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanDopisivanjeFrame::Zatvori);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanDopisivanjeFrame::OtvoriPodesavanja);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanDopisivanjeFrame::Pronadji_klijente);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanDopisivanjeFrame::TogleStartup);
    //nadimak
    m_menubar1 = MenuBar1;
    citaj_podesavanja_reg();
    nadimak_gore->SetLabel(Nadimak);
    //nit run
    nit1 = new NitSlusaj(this);
    nit1->Set_PORT( PORT );
    nit1->Run();
    //elementi three
    wxIcon ikonica(wxString::FromAscii("aaaa"),wxBITMAP_TYPE_ICO_RESOURCE);
    wxIcon ikonica2(wxString::FromAscii("users"),wxBITMAP_TYPE_ICO_RESOURCE);
    im_l = new wxImageList(16,16);
    im_l->Add((wxIcon) ikonica );
    im_l->Add(ikonica2);
    lista_klijenata->SetImageList(im_l);
    tiid = lista_klijenata->AddRoot(_("Svi kontakti"),1);
    lista_klijenata->Expand(tiid);
    //init prozore
    br_p = 0;
    //ikonica
    SetIcon(wxICON(aaaa));
    //zag
    br_k = 0;
    //pron kl
    Pronadji_klijente();
    BitmapButton1->SetBitmapLabel(wxBitmap(_("slika"),wxBITMAP_TYPE_BMP_RESOURCE));
    //dodaje ikonicu u systray
    sysikonica = new TaskBarIkonica(this);
    sysikonica->SetIcon(ikonica, wxString::FromAscii("Lan dopisivanje"));
    //interval timer
    Timer1.Start(interval*60000,false);
    PosaljiFajl();
}

LanDopisivanjeFrame::~LanDopisivanjeFrame()
{
    //(*Destroy(LanDopisivanjeFrame)
    //*)
    nit1->Kill();
    sysikonica->~wxTaskBarIcon();
}

void LanDopisivanjeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LanDopisivanjeFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(_("Autor: Miloš Milovanoviæ\nemail: milos_silni@yahoo.com\nweb: milosm.awardspace.com"),
        _("O programu"));
}

void LanDopisivanjeFrame::Onlista_klijenataItemActivated(wxTreeEvent& event)
{
    int i;
    for(i=0;i<256;i++){
        if(kontakt[i].id == event.GetItem()){
            wxCommandEvent event1( wxEVT_NOVPROZOR_EVENT, 7778 );
            event1.SetString( kontakt[i].ipadresa );
            //wxString temp =  kontakt[i].nadimak + ZAG_POR;
            char *p = new char[256]; strcpy(p, kontakt[i].nadimak.mb_str(wxConvUTF8));
            event1.SetClientData((void*)p);
            wxPostEvent(this, event1);
            break;
        }
    }
}

void LanDopisivanjeFrame::novi_prozor( wxCommandEvent &event )
{
    wxString ip = event.GetString();
    wxString n = wxString::FromUTF8((char*)event.GetClientData());
    int i = 0;
    bool ok = false;
    for (i=1;i<br_p+1;i++){
        if( !poruka[i]->GetIpAdresu().CompareTo( ip ) ){
            poruka[i]->Show();
            poruka[i]->SetFocus();
            poruka[i]->SetLabel( n + _(" - Dopisivanje") );
            poruka[i]->Set_ipadresu( ip );
            poruka[i]->Set_PORT( PORT );
            poruka[i]->Set_moj_nadimak( Nadimak );
            poruka[i]->Set_tudji_nadimak(n);
            ok = true;
            break;
        }
    }
    if(!ok){
        br_p++;
        poruka[br_p] = new Poruka(this);
        poruka[br_p]->Show();
        poruka[br_p]->SetFocus();
        poruka[br_p]->SetLabel( n + _(" - Dopisivanje") );
        poruka[br_p]->Set_ipadresu( ip );
        poruka[br_p]->Set_PORT( PORT );
        poruka[br_p]->Set_moj_nadimak( Nadimak );
        poruka[br_p]->Set_tudji_nadimak(n);
    }
}

void LanDopisivanjeFrame::Novi_prozor( MojCommandEvent &event )
{
    S_Poruka p = event.GetPoruka();
    wxString poslao = wxString::FromUTF8((char*) p.nadimak ) ;
    wxString por = wxString::FromUTF8((char*) p.poruka);
    Tip tip = p.tip;
    wxString ip = event.GetString();
    //proveri da li je pitao kosi
    if(poslao.Length()>0 && tip==KoSi){
        S_Poruka temp;
        strcpy(temp.nadimak,Nadimak.mb_str(wxConvUTF8));
        strcpy(temp.poruka,"");
        temp.tip = JaSam;
        Posalji(ip, temp);
    }else
    if(poslao.Length()>0 && por.Length()>0 && tip == Normalna){
        int i = 0;
        bool ok = false;
        for (i=1;i<br_p+1;i++){
            if( !poruka[i]->GetIpAdresu().CompareTo( event.GetString() ) ){
                poruka[i]->Show();
                poruka[i]->SetFocus();
                poruka[i]->SetLabel( poslao );
                poruka[i]->Set_tudji_nadimak(poslao+ _(" - Dopisivanje"));
                poruka[i]->Set_ipadresu( ip );
                poruka[i]->Set_PORT( PORT );
                poruka[i]->Set_moj_nadimak( Nadimak );
                poruka[i]->dodaj_poruku( poslao, por );
                ok = true;
                break;
            }
        }
        if(!ok){
            br_p++;
            poruka[br_p] = new Poruka(this);
            poruka[br_p]->Show();
            poruka[br_p]->SetFocus();
            poruka[br_p]->SetLabel( poslao);
            poruka[br_p]->Set_tudji_nadimak(poslao+ _(" - Dopisivanje"));
            poruka[br_p]->Set_ipadresu( ip );
            poruka[br_p]->Set_PORT( PORT );
            poruka[br_p]->Set_moj_nadimak( Nadimak );
            poruka[br_p]->dodaj_poruku( poslao, por );
        }
    }else if(poslao.Length()>0 && tip==JaSam){
        dodaj_novi_kontakt(poslao, ip);
    }
    //uvek treba proveriti da li se menjao nadimak
    if(poslao.Length()>0 && ip.Length()>0){
        dodaj_novi_kontakt(poslao,ip);
    }
}

void LanDopisivanjeFrame::dodaj_novi_kontakt( wxString nadimak, wxString ipadresa )
{
    if(DodajNoviKontakt){
        int i;
        bool ok = false;
        for(i=0;i<4;i++){
            if(kontakt[i].ipadresa.CompareTo(ipadresa)==0){
                kontakt[i].nadimak = nadimak;
                lista_klijenata->SetItemText(kontakt[i].id, nadimak);
                ok = true;
            }
        }
        if(!ok){
            kontakt[br_k].ipadresa = ipadresa;
            kontakt[br_k].nadimak = nadimak;
            kontakt[br_k].id = lista_klijenata->AppendItem(tiid, nadimak, 0);
            br_k++;
            lista_klijenata->Expand(tiid);
        }
        StatusBar1->SetStatusText(_("Kontakti: ")+wxString::Format(_("%i"), lista_klijenata->GetCount()-1));
    }
}

void LanDopisivanjeFrame::Pronadji_klijente( )
{
    DodajNoviKontakt = false;
    int i = 0;
    for(i=0;i<256;i++){
        kontakt[i].ipadresa = _("");
        kontakt[i].nadimak = _("");
        kontakt[i].id = NULL;
    }
    DodajNoviKontakt = true;
    if(lista_klijenata->ItemHasChildren(tiid)){
        lista_klijenata->DeleteChildren(tiid);
        br_k = 0;
    }
    for(i=1;i<256;i++){
        wxString temp = wxString::FromAscii("192.168.0.") + wxString::Format(_("%i"),i);
        zahtev_tudji_nadimak( temp );
    }
}

int LanDopisivanjeFrame::zahtev_tudji_nadimak( wxString ipadresa )
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1, 1), &wsaData);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0){
       return -1;
    }
    struct sockaddr_in adresa;
    adresa.sin_family = AF_INET;
    adresa.sin_port = htons(PORT);
    adresa.sin_addr.s_addr = inet_addr( ipadresa.mb_str(wxConvUTF8) );
    S_Poruka p;
    strcpy(p.nadimak,Nadimak.mb_str(wxConvUTF8));
    p.tip = KoSi;
    if (sendto(sock, (char*)&p, sizeof(S_Poruka), 0, (struct sockaddr *)&adresa, sizeof(struct sockaddr))<0){
        return -1;
    }
    closesocket(sock);
    WSACleanup();
    return 0;
}

void LanDopisivanjeFrame::OnButton1Click(wxCommandEvent& event)
{
    PromenaNadimka *p = new PromenaNadimka(this,Nadimak);
    p->SetOsnFrame(this);
    p->ShowModal();
}

void LanDopisivanjeFrame::SetNadimak( wxString n )
{
    Nadimak = n;
    nadimak_gore->SetLabel( Nadimak );
    //upisi u reg
    wxRegKey *pRegKey = new wxRegKey(_("HKEY_CURRENT_USER\\Software\\Lan dopisivanje"));
    if( !pRegKey->Exists() )
        pRegKey->Create();
    pRegKey->SetValue(_("Nadimak"),Nadimak);
    //refresh
    Pronadji_klijente();
}

void LanDopisivanjeFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
    Pronadji_klijente();
}

void LanDopisivanjeFrame::Posalji(wxString ip, S_Poruka por)
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1, 1), &wsaData);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0){
        //break;
    }
    struct sockaddr_in adresa;
    adresa.sin_family = AF_INET;
    adresa.sin_port = htons(PORT);
    adresa.sin_addr.s_addr = inet_addr( ip.mb_str(wxConvUTF8) );
    if (sendto(sock, (char*)&por, sizeof(S_Poruka), 0, (struct sockaddr *)&adresa, sizeof(struct sockaddr))<0){
        //return 1;
    }
    closesocket(sock);
    WSACleanup();
    //return 0;
}

void LanDopisivanjeFrame::citaj_podesavanja_reg()
{
    wxRegKey *pRegKey = new wxRegKey(_("HKEY_CURRENT_USER\\Software\\Lan dopisivanje"));
    if( !pRegKey->Exists() ){
        pRegKey->Create();
    }
    if( pRegKey->HasValue(_("Nadimak")) ){
        pRegKey->QueryValue(_("Nadimak"),Nadimak);
    }
    if(Nadimak.CompareTo(_(""))==0)
        Nadimak = _("Dopisivanje");
    nadimak_gore->SetLabel(Nadimak);
    if( pRegKey->HasValue(_("PORT")) ){
        pRegKey->QueryValue(_("PORT"),(long*)&PORT);
    }else{
        PORT = 8889;
    }
    if( pRegKey->HasValue(_("INTERVAL")) ){
        pRegKey->QueryValue(_("INTERVAL"),(long*)&interval);
    }else{
        interval = 30;
    }
    //start up
    wxRegKey *pKey = new wxRegKey(
        _("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"));
    if( pKey->HasValue(_("LDOPISIVANJE")) ){
        m_menubar1->Check(ID_MENUITEM3,true);
    }
}

void LanDopisivanjeFrame::OnClose(wxCloseEvent& event)
{
    Hide();
}

void LanDopisivanjeFrame::Zatvori(wxCloseEvent& event)
{
    delete this;
}

void LanDopisivanjeFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    Pronadji_klijente();
}

void LanDopisivanjeFrame::OtvoriPodesavanja()
{
    wxRegKey *pRegKey = new wxRegKey(_("HKEY_CURRENT_USER\\Software\\Lan dopisivanje"));
    if( !pRegKey->Exists() ){
        pRegKey->Create();
    }
    int port = 8889;
    if( pRegKey->HasValue(_("PORT")) ){
        pRegKey->QueryValue(_("PORT"),(long*)&port);
    }
    Podesavanja *p = new Podesavanja(this,wxString::Format(_("%i"),port),
        wxString::Format(_("%i"),interval));
    p->SetOsnFrame(this);
    p->ShowModal();
}

void LanDopisivanjeFrame::SetPodesavanja(int p, int i)
{
    interval =  i;
    wxRegKey *pRegKey = new wxRegKey(_("HKEY_CURRENT_USER\\Software\\Lan dopisivanje"));
    if( !pRegKey->Exists() ){
        pRegKey->Create();
    }
    pRegKey->SetValue(_("INTERVAL"),i);
    if(p!=PORT){
        pRegKey->SetValue(_("PORT"),p);
        wxMessageBox(_("Morate ponovo pokrenuti program da bi izmene imale efekat."),
            _("Dopisivanje"),wxICON_INFORMATION);
    }
    Timer1.Start(interval*60000,false);
}

void LanDopisivanjeFrame::TogleStartup()
{
    wxRegKey *pRegKey = new wxRegKey(
        _("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"));

    if( pRegKey->HasValue(_("LDOPISIVANJE")) ){
        pRegKey->DeleteValue(_("LDOPISIVANJE"));
    }else{
        wxStandardPaths * sp = new wxStandardPaths();
        pRegKey->SetValue(_("LDOPISIVANJE"),sp->GetExecutablePath());
    }
}

bool LanDopisivanjeFrame::PosaljiFajl()
{
    wxFile f(_("c:pesma.mp3"),wxFile::read);
    if(!f.IsOpened()){
        wxMessageBox(_("greska"));
        return false;
    }
    char m[1024];
    int i = 0;
    while(!f.Eof()){
        i++;
        f.Read(m,1024);

    }
    return true;
}
