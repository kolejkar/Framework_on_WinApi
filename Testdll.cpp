#include "WinApi.hpp"

App *app;

class main : public Window
{
	public:
		Button * exit;
		main()
		{
			exit = new Button(this, (char*)"Zamknij", 5, 5, 75, 25);
			char text[40];
			LoadString(app->HInstance, 1, text, 40);
			app->Message(this, text, MB_OK);
		};
	private:
};

__declspec(dllexport) int RunDll()
{
	app = new App();
	main gl;
	gl.Show();
	return app->Return();
};

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
	return 1;
}

