#ifndef _Window_
#define _Window_

//Standards library for windows
#include <windows.h>
#include <vector>

//Defaults library
#include "Control.hpp"
#include "Evnent.hpp"

class Window : public Control
{
	private:
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
		char NK[15];
		WNDCLASSEX wc;
	 public:
	 	Window(App *app);
	 	~Window(); 
		void Show();
		void CloseWin();
		void Init();
};

#endif /* _Window_ */
