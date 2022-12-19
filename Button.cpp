#include "Button.hpp"

// Standards library for windows
#include <windows.h>
#include <vector>

using namespace std; //for vector

//classes library
#include "Evnent.hpp"
#include "Application.hpp"

//class button
Button::~Button()
{
}

Button::Button(Control *Con,char *Title,int x,int y,int w, int h)
{
	Name = Title;
	x=x;
	y=y;
	w=w;
	h=h;
	Parent=Con;
	HWND phandle;
	if (Parent == NULL)
		phandle = HWND_DESKTOP;
	else
		phandle = Parent->Handle;
	Handle = CreateWindowEx(0, "Button", Name, WS_CHILD, x, y, w, h, phandle, 0, tapp->HInstance, this);
	if (Handle == 0)
	{
		MessageBoxA(0, controlerror, 0, MB_ICONERROR);
	}
	HFONT hNF = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	Evnent ev;
	ev.Message = WM_SETFONT;
	ev.Param1 = (int)hNF;
	ev.SendEvnent(this);
	Visible(SW_SHOW);
	UpdateWindow(Handle);
}

//class checkbox

CheckBox::CheckBox(Control *Con, char *Title, int x, int y, int w, int h):Button(Con, Title, x, y, w, h)
{
	SetWindowLong((HWND)Handle, GWL_STYLE, BS_AUTOCHECKBOX + GetWindowLongPtr((HWND)Handle, GWL_STYLE));
	id = GetDlgCtrlID((HWND)Handle);
}

bool CheckBox::Checked()
{
	Evnent Msg;
	Msg.Message = BM_GETCHECK;
	return Msg.SendEvnent(this);
}

//class radiobtn
RadioBtn::RadioBtn(Control *Con, char *Title, int x, int y, int w, int h) :Button(Con, Title, x, y, w, h)
{
	SetWindowLong((HWND)Handle, GWL_STYLE, BS_AUTORADIOBUTTON + GetWindowLongPtr((HWND)Handle, GWL_STYLE));
	id = GetDlgCtrlID((HWND)Handle);
}

bool RadioBtn::Checked()
{
	Evnent Msg;
	Msg.Message = BM_GETCHECK;
	return Msg.SendEvnent(this);
}

//class frame
Frame::Frame(Control *Con, char *Title, int x, int y, int w, int h) :Button(Con, Title, x, y, w, h)
{
	SetWindowLong((HWND)Handle, GWL_STYLE, BS_GROUPBOX + GetWindowLongPtr((HWND)Handle, GWL_STYLE));
}

void Frame::Insert(Control *Con)
{
	Wsk = Con;
	SetWindowLong((HWND)Wsk->Handle, GWL_STYLE, WS_GROUP + GetWindowLongPtr((HWND)Wsk->Handle, GWL_STYLE));
	tab.push_back(Wsk);
}

Frame::~Frame()
{
	for (int i = 0; i<(int)tab.size(); i++)
	{
		Wsk = tab[i];
		delete Wsk;
	}
	tab.clear();
}