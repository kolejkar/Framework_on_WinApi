#include "Control.hpp"

// Standards library for windows
#include <windows.h>

//classes library
#include "Evnent.hpp"
#include "Application.hpp"

//string for control error
const char *controlerror = "B³¹d tworzenia kontrolki!";

//class Control
Control::Control(App *app)
{
		tapp = app;
}

Control::Control()
{
	tapp = new App;
}

Control::~Control()
{
	//delete tapp;
}

void Control::Visible(int Show)
{
	ShowWindow((HWND)this->Handle,Show);
}

bool Control::Update(int nx,int ny,int nw,int nh,char *Title)
{
	x=nx;
	y=ny;
	w=nw;
	h=nh;
	if (Title!=NULL)
	{
		Name = Title;
		SetWindowTextA((HWND)Handle, Title);
	}
	MoveWindow((HWND)Handle,nx,ny,nw,nh,false);
	return true;
}

//class Static
Static::Static(Control *Con,char *Title,int x,int y,int w, int h)
{
	Name=Title;
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
	Handle = CreateWindowExA(0, "Static", Name, WS_CHILD, x, y, w, h, Parent->Handle, 0, tapp->HInstance, this);
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
}

Static::~Static()
{
}

int Static::SetImage(StaticType Typ,char *Text,HINSTANCE hInst)
{
	Visible(SW_HIDE);
	if (Typ==Icon)
	{
		SetWindowLongPtr(Handle,GWL_STYLE,WS_CHILD+SS_ICON);
		Visible(SW_SHOW);
		return SendMessage(Handle,STM_SETIMAGE,IMAGE_ICON,(LPARAM)LoadIconA(hInst,Text));
	}
	else
	if (Typ==Bitmap)
	{
		SetWindowLongPtr(Handle,GWL_STYLE,WS_CHILD+SS_BITMAP);
		Visible(SW_SHOW);
		return SendMessage(Handle, STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)LoadBitmapA(hInst, Text));
	}
	else
	{
		SetWindowLongPtr(Handle,GWL_STYLE,WS_CHILD);
		Visible(SW_SHOW);
		SetWindowTextA(Handle,Text);
		return 1;
	}
}