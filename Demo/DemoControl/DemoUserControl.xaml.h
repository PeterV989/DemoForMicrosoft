#pragma once

#include "DemoControl.DemoUserControl.g.h"

namespace winrt::Demo::DemoControl::implementation
{
    struct DemoUserControl : DemoUserControlT<DemoUserControl>
    {
        DemoUserControl( );
    };
}

namespace winrt::Demo::DemoControl::factory_implementation
{
    struct DemoUserControl : DemoUserControlT<DemoUserControl, implementation::DemoUserControl>
    {
    };
}
