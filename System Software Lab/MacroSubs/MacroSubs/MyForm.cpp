#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void Main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MacroSubs::MyForm form;
	Application::Run(%form);
}
