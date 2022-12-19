#ifndef _APP_HPP_
#define _APP_HPP_

//Defaults library
#include "Evnent.hpp"
// Standards library for windows
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
using namespace std;

class App
{
	public:
		HINSTANCE HInstance;
		string title;
		App()
		{
				value = __argv;
				count = __argc;
				GetCurrentModule();
				EMessages = new Evnent();
			//value=CommandLineToArgvW(GetCommandLine(),&count);
				
		};
		~App()
		{
			delete EMessages;
		};
		App(int argc,char **argv)
		{
			value=argv;
			count=argc;
			GetCurrentModule();
			//ustalanie tytu³u aplikacji
			char *t = *argv;
			char *dot =(char*)strrchr(t, 46);
			char *uk = (char*)strrchr(t, '\\');
			t = uk+1;
			int pos = dot - t;
			t[pos] = 0;
			title = t;
			EMessages = new Evnent();
		};
		char *ParamStr(int index)
		{
			return value[index];
		};
		int Return() 
		{ 
			while(GetMessage(&Msg,NULL,0,0))
			{
				TranslateMessage(&Msg);
				DispatchMessage(&Msg);
			}
			LocalFree(value);
			return Msg.wParam;			
		};
		void Exit(int code)
		{
			exitcode=code;
		};
		void Exit() 
		{
			PostQuitMessage(0);			
			exitcode=0;
		};
		int Message(Control *control, string message, int flags)
		{
			return MessageBoxA(control->Handle, message.c_str(), title.c_str(), flags);
		};
		Evnent *EMessages;
	private:
		char** value;
		int count; 
		int exitcode;
		MSG Msg;
		void GetCurrentModule()
		{
			//pobieranie uchwytu
			HMODULE hModule = NULL;
			GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)controlerror, &hModule);
			char path[MAX_PATH];
			GetModuleFileNameA(hModule, path, sizeof(path));
			HInstance = GetModuleHandleA(path);
		};			
};

#endif /* _APP_HPP_ */
