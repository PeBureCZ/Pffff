#include "basicForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading::Tasks;
[STAThreadAttribute]

int main(array<String^>^ argh)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProgramSettings^ Settings = gcnew ProgramSettings();
	ProgramFunctions^ Functions = gcnew ProgramFunctions();
	CustomTimer^ MyTimer = gcnew CustomTimer();
	Functions->initializeSettings(Settings);
	Pffff::basicForm^ form = gcnew Pffff::basicForm(Settings, Functions, MyTimer);
	Application::Run(form);

}

