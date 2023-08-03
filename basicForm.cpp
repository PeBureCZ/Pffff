#include "basicForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ argh)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Pffff::basicForm form;
	Application::Run(% form);
}

