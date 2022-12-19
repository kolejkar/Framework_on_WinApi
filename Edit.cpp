#include "Edit.hpp"

// Standards library for windows
#include <windows.h>

//classes library
#include "Evnent.hpp"
#include "Application.hpp"

Edit::~Edit()
{
	delete Text;
}

Edit::Edit(Control *Con,char *Title,int x,int y,int w, int h)
{
	
	x=x;
	y=y;
	w=w;
	h=h;
	Name = Title;
	Parent=Con;
	HWND phandle;
	if (Parent == NULL)
		phandle = HWND_DESKTOP;
	else
		phandle = Parent->Handle;
	Handle = CreateWindowEx(0, "Edit", Name, WS_CHILD, x, y, w, h, Parent->Handle, 0, tapp->HInstance, this);
	if (Handle == 0)
	{
		MessageBox(0, controlerror, 0, MB_ICONERROR);
	}
	Evnent ev;
	ev.Message = EM_GETLIMITTEXT;
	int size = ev.SendEvnent(this);
	Text = new char[size];
	strcpy(Text, Name);
	Name = Text;
	HFONT hNF = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	ev.Message = WM_SETFONT;
	ev.Param1 = (int)hNF;
	ev.SendEvnent(this);
	Visible(SW_SHOW);
}

void Edit::GetText()
{
	int size=GetWindowTextLength(Handle);
	char *temp=new char[size+1];
	GetWindowText(Handle,temp,size+1);
	strcpy(Text,temp);
}
