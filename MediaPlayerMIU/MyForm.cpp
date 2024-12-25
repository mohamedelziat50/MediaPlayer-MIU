#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MediaPlayerMIU;

[STAThreadAttribute]
int main(cli::array<String^>^ args)
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm mf;

    Application::Run(% mf);
    return 0;
}