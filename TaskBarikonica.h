#ifndef TASKBARIKONICA_H_INCLUDED
#define TASKBARIKONICA_H_INCLUDED

#include <wx/taskbar.h>
#include "LanDopisivanjeMain.h"

class TaskBarIkonica: public wxTaskBarIcon{
    public:
        TaskBarIkonica(LanDopisivanjeFrame *f) {m_landopframe = f;};
        virtual wxMenu *CreatePopupMenu();
        void Klik_Izlaz(wxCommandEvent&);
        void Klik_Otvori(wxCommandEvent&);
        void TaskBarIkonica::DupliKlikOtvori(wxTaskBarIconEvent&);
    private:
        LanDopisivanjeFrame *m_landopframe;

    DECLARE_EVENT_TABLE()
};

#endif // TASKBARIKONICA_H_INCLUDED
