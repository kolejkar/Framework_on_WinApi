#include "Evnent.hpp"

//komunikaty aplikacji (przetwarzanie)
struct TEvnent
{
	Control *Klasa;
	Func Metoda;
	Evnent *Msg;
};

std::vector <TEvnent*> evnents;

void Evnent::Send(Control *Con)
{
		for (int i = 0; i < evnents.size(); i++)
		{
			if (evnents[i]->Klasa == Con)
			{
				if (Message == evnents[i]->Msg->Message)
				{
					(evnents[i]->Klasa->*evnents[i]->Metoda)(this);
				}
			}
		}
}

void Evnent::AddMessage(Control* Sender, int Message, Func Metod)
{
	//if (Message!=WM_CREATE && Message!=WM_NCCREATE)
	TEvnent *Ev = NULL;
	Ev = new TEvnent;
	Ev->Klasa = Sender;
	Ev->Metoda = Metod;
	//Ev->Handle = Sender;
	Ev->Msg = new Evnent();
	Ev->Msg->Message = Message;
	evnents.push_back(Ev);
	//}
	/*else
	{
	MessageBoxA(0,"Don't use Add Method with message WN_CREATE or WM_NCCREATE!!!",0,MB_ICONERROR);
	return false;
	}*/
	//return true;
}