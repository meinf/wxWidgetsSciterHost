#ifndef SCITER_WINDOW_H
#define SCITER_WINDOW_H

#include <wx/frame.h>
#include <sciter-x.h>

class SciterWindow :
    public wxFrame,
    public sciter::host<SciterWindow>,
    public sciter::event_handler
{
public:
    SciterWindow();
    SciterWindow(wxWindow* parent,
        wxWindowID id,
        wxString const& title,
        wxPoint const& pos = wxDefaultPosition,
        wxSize const& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE,
        wxString const& name = wxFrameNameStr);
    ~SciterWindow();

    bool Create(wxWindow* parent, wxWindowID id, wxString const& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxSUNKEN_BORDER, wxString const& name = wxFrameNameStr);

    void LoadHtml(std::string const& html)
    {
        load_html((LPCBYTE)html.c_str(), UINT(html.size()));
    }

    void LoadHtmlFrom(std::string const& path)
    {
        wxString str{ path.c_str(), wxMBConvUTF8() };
        load_file(str.wchar_str());
    }

    WXLRESULT MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);

    HWINDOW get_hwnd() const { return GetHWND(); }
    HINSTANCE get_resource_instance() const { return 0; }
};

#endif //!SCITER_WINDOW_H
