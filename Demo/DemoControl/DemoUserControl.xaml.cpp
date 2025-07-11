#include "pch.h"
#include "DemoControl/DemoUserControl.xaml.h"
#if __has_include("DemoControl.DemoUserControl.g.cpp")
#include "DemoControl.DemoUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Demo::DemoControl::implementation
{
	DemoUserControl::DemoUserControl( )
	{
		InitializeComponent( );
	}
}
