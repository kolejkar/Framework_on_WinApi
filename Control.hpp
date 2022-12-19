#ifndef CONTROL_HPP
#define CONTROL_HPP

// Standards library for windows
#include <windows.h>

//const library
#include "Consts.h"

//Defaults library
//nclude "Objekt.hpp"

//string for control error
extern const char *controlerror;

#ifndef _APP_HPP_
class App;
#endif

class Control
{
	public:
		Control(App *app);
		int x,y,w,h;
		Control *Parent;
		Control();
		~Control();
		char *Name;
		HWND Handle;
		void Visible(int Show);
		bool Update(int nx,int ny,int nw,int nh,char *Title);
		App * tapp;
	private:
};

enum StaticType {Text, Icon, Bitmap};

class Static: public Control
{
	public:
		Static(App *app) : Control(app) {};
		Static(Control *Con,char *Title,int x,int y,int w, int h);
		int SetImage(StaticType Typ,char *Text, HINSTANCE hInst);
		~Static();
	private:
};

#endif /* CONTROL_HPP */
