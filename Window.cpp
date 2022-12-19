#include "Window.hpp"

// Standards library for windows
#include <windows.h>
#include <vector>

using namespace std; //for vector

//classes library
#include "Evnent.hpp"
#include "Application.hpp"

Window::Window(App *app):Control(app) //konstruktor
{
	strcpy(NK,"Object_Window");
	wc.cbSize=sizeof(WNDCLASSEX);
	wc.style=0;
	wc.lpfnWndProc=WndProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance=GetModuleHandle(NULL);
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	wc.lpszMenuName=0;
	wc.lpszClassName=NK;
	wc.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
	if (!RegisterClassEx(&wc))
	{
		MessageBoxA(0,"B³¹d rejestracji klasy okna!",0,MB_ICONERROR);
		ExitProcess(0);
	}
	Name = (char*)"Okno";
	x = CW_USEDEFAULT;
	y = CW_USEDEFAULT;
	h = CW_USEDEFAULT;
	w = CW_USEDEFAULT;
	/*HWND phandle;
	if (Parent == NULL)
		phandle = HWND_DESKTOP;
	else
		phandle = Parent->Handle;*/
}

void Window::Init()
{
	Handle = CreateWindowEx(0, NK, Name, WS_OVERLAPPEDWINDOW, x, y, w, h, 0, 0, tapp->HInstance, this);
}

Window::~Window() //dekonstruktor
{
	//delete ev;
}


LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) //procedura okna z winapi
{
	Window *obj; //wskaŸnik
	if (Message==WM_NCCREATE)
	{
		CREATESTRUCT *cs;
		cs=(CREATESTRUCT *)lParam;
		obj=(Window *)cs->lpCreateParams;
		SetLastError(0);
		if (!SetWindowLongPtr(hwnd,GWLP_USERDATA,(int)obj))
		{
			if (GetLastError()!=0)
			{
				MessageBoxA(0,"Memory error!",0,MB_ICONERROR);
				return FALSE;
			}
		}
	}
	else
	{
		obj=(Window *)GetWindowLongPtr(hwnd,GWLP_USERDATA);
	}
	if (obj!=NULL)
	{
		obj->tapp->EMessages->Message = Message;
		obj->tapp->EMessages->Param1 = wParam;
		obj->tapp->EMessages->Param2 = lParam;
		obj->tapp->EMessages->Send(obj);
	}
	if (Message==WM_DESTROY)
		PostQuitMessage(0);
	return DefWindowProc(hwnd,Message,wParam,lParam);
}

//bool Window::Add(Window* Sender,int Message,Func Metod) //dodane metody do obs³ugi zdarzenia


void Window::Show() //pokazywanie okna
{
	Visible(SW_SHOW);
	UpdateWindow((HWND)Handle);
}

void Window::CloseWin()
{
	DestroyWindow((HWND)Handle);
}
