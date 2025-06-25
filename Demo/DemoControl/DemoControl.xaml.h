#pragma once

#include "DemoControl.g.h"

namespace winrt::Demo::implementation
{
    struct DemoControl : DemoControlT<DemoControl>
    {
        DemoControl( );
    };
}

namespace winrt::Demo::factory_implementation
{
    struct DemoControl : DemoControlT<DemoControl, implementation::DemoControl>
    {
    };
}
