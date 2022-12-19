#ifndef _EVNENT_
#define _EVNENT_

//Defaults library
#include "Control.hpp"


// Standards library for windows
#include <windows.h>
#include <vector>
#include <iostream>
#include <process.h>

using namespace std; //for vector and streams

class Evnent;


typedef void (Control::*Func)(Evnent *Msg); //function for evnents;

class Evnent
{
	public:
		Evnent()
		{};
		int Message;
		int Param1;
		int Param2;
		bool SendEvnent(Control *Con)
		{
			return SendMessage(Con->Handle,Message,Param1,Param2);
		};
		int GetEvnent(Control *Con) {
			MSG Msg;
			int ret=GetMessage(&Msg,Con->Handle,0,0);
			Message=Msg.message;
			Param1=Msg.wParam;
			Param2=Msg.lParam;
			DispatchMessage(&Msg);
			return ret;
		}
	// dodanie obs³ugi komunikatu
	void AddMessage(Control* Sender, int Message, Func Metod);
	//wysy³anie komunikatu do obs³ugi (bez interakccji z API)
	void Send(Control *Handle);
};
#endif /* _EVNENT_ */
