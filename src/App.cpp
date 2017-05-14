#include "SciterWindow.h"
#include <wx/app.h>

class MainWindow : public SciterWindow
{
public:
    MainWindow()
        : SciterWindow(0, -1, "Sciter overrides this anyway"), _debout(get_hwnd())
    {
        // F5 to reload UI without rebuild or restart.
        Bind(wxEVT_CHAR, &MainWindow::OnKeyDown, this);
    }

    void OnKeyDown(wxKeyEvent& event)
    {
        if (event.GetKeyCode() == WXK_F5)
            ReloadUI();
        else
            event.DoAllowNextEvent();
    }

    void ReloadUI()
    {
        LoadHtmlFrom("./MainWindow.htm");
        _debout.print("Reloaded");  // Prints to output window when attached to debugger
    }
private:
    sciter::debug_output _debout;
};

class App : public wxApp
{
public:
    bool OnInit() override
    {
        if (!wxApp::OnInit())
            return false;
             
        MainWindow* win = new MainWindow();
        // You need to copy this from "res" directory and place it beside binary.
        // Aslo sciter.dll from "sciter/lib64(86)".
        win->LoadHtmlFrom("./MainWindow.htm");
        win->SetSize(600, 400);
        win->Center();
        win->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);

// Need main scope? Comment line above and uncomment block below.
/*int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    wxCmdLineArgType lpCmdLine,
    int nCmdShow)
{
    App* app = new App{};
    wxApp::SetInstance(app);
    wxEntryStart(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    app->OnInit();
    app->OnRun();
    app->OnExit();
    wxEntryCleanup();
}*/
