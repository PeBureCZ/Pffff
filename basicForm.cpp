#include "basicForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ argh)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProgramSettings^ Settings = gcnew ProgramSettings();
	ProgramFunctions^ Functions = gcnew ProgramFunctions();
	Functions->initializeSettings(Settings);
	Pffff::basicForm^ form = gcnew Pffff::basicForm(Settings, Functions);
	Application::Run(form);
}

