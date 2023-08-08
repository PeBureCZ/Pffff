#include "basicForm.h"
//#include "Loader.h"
#include "ProgramSettings.h"
#include "ScanControl.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ argh)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Pffff::basicForm form;
	Application::Run(% form);
	//ProgramSettings^ Settings;
	//Settings->testFunction2();
	/*Pffff::ScanControl^ ScanCotnrol = form.GetS*/



	
	
	//Loader LoaderClass(Settings); //Need seting object reference

}

