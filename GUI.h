#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/frame.h>


/**
* Klasa Frame u�ywana przy tworzeniu g��wnego okna programu.
*/
class Frame : public wxFrame 
{
public:
	/**
	* Konstruktor. Ustawia parametry okna, dodaje display_panel, sizery, ��czy niekt�re eventy.
	* @param parent wska�nik na obiekt wxWindow b�d�cy nadrz�dnym oknem
	* @param id id okna
	* @param title napis wy�wietlany u g�ry okna
	* @param pos pozycja okna
	* @param size rozmiar okna
	* @param style styl okna
	*/
	Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1280, 720), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	
	/**
	* Destruktor.
	*/
	~Frame();

protected:
	wxPanel* display_panel; /**< wska�nik na g��wny panel na oknie */
};
