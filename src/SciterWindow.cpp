#include "SciterWindow.h"

SciterWindow::SciterWindow()
{
}

SciterWindow::SciterWindow(wxWindow* parent, wxWindowID id, wxString const& title, wxPoint const& pos, wxSize const& size, long style, wxString const& name)
{
    Create(parent, id, title, pos, size, style, name);
}

SciterWindow::~SciterWindow()
{
}

bool SciterWindow::Create(wxWindow* parent, wxWindowID id, wxString const& title, wxPoint const& pos, wxSize const& size, long style, wxString const& name)
{
    if (!wxFrame::Create(parent, id, title, pos, size, style, name))
        return false;

    setup_callback();
    sciter::attach_dom_event_handler(GetHWND(), this);

    Refresh();

    return true;
}

WXLRESULT SciterWindow::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam)
{
    LRESULT lResult;
    BOOL    handled;

    lResult = SciterProcND(GetHWND(), nMsg, wParam, lParam, &handled);
    if (handled)        // if it was handled by the Sciter
        return lResult; // then no further processing is required.

                        // calling default win proc:
    return wxFrame::MSWWindowProc(nMsg, wParam, lParam);
}
