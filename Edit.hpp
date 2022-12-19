#ifndef EDIT_HPP
#define EDIT_HPP

//Defaults library
#include "Control.hpp"

class Edit : public Control
{
	public:
		Edit(App *app) :Control(app) {};
		Edit(Control *Con,char *Title,int x,int y,int w, int h);
		~Edit();
		void GetText();
	private:
		char *Text;
};

#endif /* EDIT_HPP */