#ifndef __MainFrame__
#define __MainFrame__

/**
@file
Subclass of Frame, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <vector>
#include <iostream>

#include "Triangle.h"
#include "Quadrangle.h"

bool isInside(const Shape& shape, wxPoint& mouse, bool on_display);
bool Intersect(const wxPoint& p1, const wxPoint& q1, const wxPoint& p2, const wxPoint& q2);
int Orientation(const wxPoint& p, const wxPoint& q, const wxPoint& r);
bool Segment(const wxPoint& p, const wxPoint& q, const wxPoint& r);

/** Implementing Frame */
class MainFrame : public Frame
{
	protected:
		// Handlers for Frame events.
		void OnClick( wxMouseEvent& event );
		void Render( wxPaintEvent& event );
	public:
		/** Constructor */
		MainFrame( wxWindow* parent );
	//// end generated class members

		void OnClickUp(wxMouseEvent& event);
		void Mouse_Move(wxMouseEvent& event);
		~MainFrame();
protected:
	std::vector<std::unique_ptr<Shape>> container;
	std::vector<std::unique_ptr<Shape>> display;

	Shape* moving = nullptr;
	wxPoint mouse_pos;
	wxPoint mouse_prev;
	bool dragging = false;
};

#endif // __MainFrame__
