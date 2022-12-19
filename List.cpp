#include "List.hpp"

// Standards library for windows
#include <windows.h>
#include <vector>

using namespace std; //for vector

//classes library
#include "Evnent.hpp"

//class listbox
ListBox::~ListBox()
{
}

ListBox::ListBox(Control *Con, char *Title, int x, int y, int w, int h)
{
	Name = Title;
	x = x;
	y = y;
	w = w;
	h = h;
	Parent = Con;
	Handle = CreateWindowExA(0, "ListBox", Title, WS_CHILD, x, y, w, h, Con->Handle, 0, GetModuleHandle(NULL), this);
	if (Handle == 0)
	{
		MessageBoxA(0,controlerror, 0, MB_ICONERROR);
	}
	HFONT hNF = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	Evnent ev;
	ev.Message = WM_SETFONT;
	ev.Param1 = (int)hNF;
	ev.SendEvnent(this);
	Visible(SW_SHOW);
}

void ListBox::Add(char *Option)
{
	Evnent ev;
	ev.Message = LB_ADDSTRING;
	ev.Param2 = (int)Option;
	ev.SendEvnent(this);
}

int ListBox::GetIndex()
{
	Evnent ev;
	ev.Message = LB_GETCURSEL;
	return ev.GetEvnent(this);
}
