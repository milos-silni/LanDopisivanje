#ifndef PORUKA2_H
#define PORUKA2_H

//(*Headers(Poruka2)
#include <wx/frame.h>
//*)

class Poruka2: public wxFrame
{
	public:

		Poruka2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Poruka2();

		//(*Declarations(Poruka2)
		//*)

	protected:

		//(*Identifiers(Poruka2)
		//*)

	private:

		//(*Handlers(Poruka2)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
