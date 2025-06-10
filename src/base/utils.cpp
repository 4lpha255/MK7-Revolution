#include <base/utils.hpp>

#include <algorithm>
#include <codecvt>
#include <locale>

namespace base::utils
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // wstring_convert
    inline auto s_converter = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>();
#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress-of-packed-member" // mii_name
    std::string mii_name(MiiData const &mii)
    {
        // FIXME: mii_name doesn't match anymore
        auto mii_name = reinterpret_cast<MiiData const *>(reinterpret_cast<u8 const *>(&mii) + 0x16);

        auto name = std::u16string(reinterpret_cast<char16_t const *>(mii_name), std::size(mii.mii_name));
        name.erase(std::find(name.begin(), name.end(), '\0'), name.end());
        return s_converter.to_bytes(name);
    }
#pragma GCC diagnostic pop
}