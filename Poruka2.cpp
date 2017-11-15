#include "Poruka2.h"

//(*InternalHeaders(Poruka2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Poruka2)
//*)

BEGIN_EVENT_TABLE(Poruka2,wxFrame)
	//(*EventTable(Poruka2)
	//*)
END_EVENT_TABLE()

Poruka2::Poruka2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Poruka2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

Poruka2::~Poruka2()
{
	//(*Destroy(Poruka2)
	//*)
}

