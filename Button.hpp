#ifndef BUTTON_H
#define BUTTON_H

//Standards library for windows
#include <vector>

//Defaults library
#include "Control.hpp"

class Button : public Control
{
	public:
		Button(App *app) : Control(app) {};
		Button(Control *Con,char *Title,int x,int y,int w, int h);
		~Button();
	private:
};

class CheckBox : public Button
{
public:
	CheckBox(App *app) : Button(app) {};
	CheckBox(Control *Con, char *Title, int x, int y, int w, int h);
	bool Checked();
private:
	int id;
};

class RadioBtn : public Button
{
public:
	RadioBtn(App *app) : Button(app) {};
	RadioBtn(Control *Con, char *Title, int x, int y, int w, int h);
	bool Checked();
private:
	int id;
};


class Frame : public Button
{
public:
	Frame(App *app) :Button(app) {}
	Frame(Control *Con, char *Title, int x, int y, int w, int h);
	~Frame();
	void Insert(Control *Con);
private:
	Control *Wsk;
	std::vector <Control*> tab;
};

#endif /* BUTTON_H */
