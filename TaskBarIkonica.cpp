#include "TaskBarikonica.h"
#include <wx/menu.h>

enum{
    PU_IZLAZ,
    PU_OTVORI
};

BEGIN_EVENT_TABLE(TaskBarIkonica, wxTaskBarIcon)
    EVT_MENU(PU_IZLAZ, TaskBarIkonica::Klik_Izlaz)
    EVT_MENU(PU_OTVORI, TaskBarIkonica::Klik_Otvori)
    EVT_TASKBAR_LEFT_DCLICK(TaskBarIkonica::DupliKlikOtvori)
END_EVENT_TABLE()

wxMenu *TaskBarIkonica::CreatePopupMenu()
{
    wxMenu *menu = new wxMenu();
    menu->Append(PU_OTVORI, _("&Otvori"));
    menu->AppendSeparator();
    menu->Append(PU_IZLAZ, _("&Izlaz"));
    return menu;
}

void TaskBarIkonica::Klik_Izlaz(wxCommandEvent&)
{
    m_landopframe->~LanDopisivanjeFrame();
}

void TaskBarIkonica::Klik_Otvori(wxCommandEvent&)
{
    m_landopframe->Show();
}

void TaskBarIkonica::DupliKlikOtvori(wxTaskBarIconEvent&)
{
    m_landopframe->Show();
}
