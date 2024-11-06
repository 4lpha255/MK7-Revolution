#include <base/notifier.hpp>

#include <ctrpf.hpp>

namespace base
{
    void notifier::notify(std::string str)
    {
        CTRPluginFramework::OSD::Notify(str);
    }
}