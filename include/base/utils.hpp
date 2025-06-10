#pragma once

#include <3ds/types.h>
#include <3ds/mii.h>

#include <string>

namespace base::utils
{
    std::string mii_name(MiiData const &mii);
}