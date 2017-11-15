#ifndef MOJCOMMANDEVENT_H_INCLUDED
#define MOJCOMMANDEVENT_H_INCLUDED

#include <wx/event.h>
#include "S_Poruka.h"

class MojCommandEvent : public  wxCommandEvent {
public:
	MojCommandEvent ( wxEventType commandType, int id )
				: wxCommandEvent( commandType, id ) { }

	wxEvent *Clone() const
		{ return new MojCommandEvent(*this); }
    void SetPoruka(S_Poruka poruka){
        m_poruka = poruka;
    }
    S_Poruka GetPoruka(){
        return m_poruka;
    }
private:
    S_Poruka m_poruka;
};

BEGIN_DECLARE_EVENT_TYPES()
	DECLARE_EVENT_TYPE(wxEVT_MOJ_COMMAND_EVENT, -1)
END_DECLARE_EVENT_TYPES()

typedef void (wxEvtHandler::*MojCommandEventFunction)
				(MojCommandEvent&);

#define EVT_MOJ_COMMAND_EVENT(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( wxEVT_MOJ_COMMAND_EVENT, id, -1, \
    (wxObjectEventFunction) (wxEventFunction) (wxCommandEventFunction) \
    wxStaticCastEvent( MojCommandEventFunction, & fn ), (wxObject *)NULL ),


#endif // MOJCOMMANDEVENT_H_INCLUDED
