#ifndef _LIST_HPP_
#define _LIST_HPP_

//Defaults library
#include "Control.hpp"

class ListBox :public Control
{
public:
	ListBox(App *app) :Control(app) {};
	ListBox(Control *Con, char *Title, int x, int y, int w, int h);
	void Add(char *Option);
	int GetIndex();
	~ListBox();
};

#endif // !_LIST_HPP_

