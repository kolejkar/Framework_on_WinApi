#include <windows.h>
#include "WinApi.hpp"

App *app;


class B : public Window
{
	public:
		B(App *app):Window(app)
		{
			app->EMessages->AddMessage(this, WM_CLOSE, (Func)&B::Funkcja);
			app->EMessages->AddMessage(this, WM_CREATE, (Func)&B::Gt);
			app->EMessages->AddMessage(this, WM_COMMAND, (Func)&B::Test);
			Init();
			btn=new Button(this,(char*)"Przycisk",0,50,65,30);
			edit=new Edit(this,(char*)"",0,25,80,20);
			lab=new Static(this,(char*)"Podaj Text:",0,0,100,20);
			lab1 = new Static(this, (char*)"Abcd", 0, 170, 50, 50);
			fr = new Frame(this,(char*)"Ramka",85,25,80,50);
			cb=new CheckBox(this, (char*)"CheckBox", 90, 50, 70, 20);
			listbox = new ListBox(this, (char*)"Lista wyboru", 450, 0, 50, 100);
			int ret = lab1->SetImage(Icon, IDI_HAND, NULL);
			if (ret != 0 && ret)
				DeleteObject((HGDIOBJ)ret);
			listbox->Add((char *)"Test");
			listbox->Add((char *)"1234");
		}
		Button *btn;
		Edit *edit;
		Static *lab;
		Static *lab1;
		CheckBox *cb;
		ListBox *listbox;
		Frame *fr;
		void Gt(Evnent *Msg)
		{
			MessageBox(0,"Tworzê",0,0);
		}
		void Test(Evnent *Msg)
		{
			if (Msg->Param2==(int)btn->Handle && cb->Checked())
			{
				edit->GetText();
				app->Message(this, edit->Name, MB_OK);
			}
			/*if (Msg->Param2 == (int)listbox->Handle)
			{
				char text[20];
				char msg[20];
				LoadString(app->HInstance, 1, msg, sizeof(msg));
				wsprintf(text, msg, listbox->GetIndex());
				app->Message(this, text, MB_ICONINFORMATION);
			}*/
			//Update(0,0,100,100,"Moje okno");
		};
		void Funkcja(Evnent *Msg)
		{
			char msg[10];
			LoadString(app->HInstance, 2, msg, sizeof(msg));
			app->Message(this, msg, MB_OK);
		};
	private:
};

int main(int argc,char *argv[])
{
	app=new App(argc, argv);
	B *test;
	test= new B(app);
	test->Show();
    return app->Return();
}
