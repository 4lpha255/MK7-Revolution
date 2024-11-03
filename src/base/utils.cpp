#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <UI/MessageIDConverter.hpp>

#include <map>

//#define FONT_SF     "\uE020"
//#define FONT_C      "\uE021"
#define FONT_N_1    "\uE022"
#define FONT_64_1   "\uE023"
#define FONT_GB     "\uE024"
#define FONT_A      "\uE025"
#define FONT_GC_1   "\uE026"
#define FONT_N_2    "\uE027"
//#define FONT_ICON   "\uE030"
#define FONT_SN     "\uE031"
#define FONT_ES     "\uE032"
#define FONT_DS     "\uE033"
//#define FONT_GC_2   "\uE034"
//#define FONT_64_2   "\uE035"
#define FONT_Wii    "\uE067"
//#define FONT_HOME   "\uE073"

namespace base
{
    std::string utils::item_name(Item::eItemSlot item)
    {
        auto const message_id = [item]()
        {
            switch (item)
            {
            case decltype(item)::Banana:
                return LMS_MessageID::Item_Banana;
            case decltype(item)::KouraG:
                return LMS_MessageID::Item_GreenShell;
            case decltype(item)::KouraR:
                return LMS_MessageID::Item_RedShell;
            case decltype(item)::Kinoko:
                return LMS_MessageID::Item_Mushroom;
            case decltype(item)::Bomhei:
                return LMS_MessageID::Item_Bobomb;
            case decltype(item)::Gesso:
                return LMS_MessageID::Item_Blooper;
            case decltype(item)::KouraB:
                return LMS_MessageID::Item_SpinyShell;
            case decltype(item)::Kinoko3:
                return LMS_MessageID::Item_TripleMushrooms;
            case decltype(item)::Star:
                return LMS_MessageID::Item_SuperStar;
            case decltype(item)::Killer:
                return LMS_MessageID::Item_BulletBill;
            case decltype(item)::Thunder:
                return LMS_MessageID::Item_Lightning;
            case decltype(item)::KinokoP:
                return LMS_MessageID::Item_GoldenMushroom;
            case decltype(item)::Flower:
                return LMS_MessageID::Item_FireFlower;
            case decltype(item)::Tail:
                return LMS_MessageID::Item_SuperLeaf;
            case decltype(item)::Seven:
                return LMS_MessageID::Item_LuckySeven;
            case decltype(item)::Test3:
            case decltype(item)::Test4:
                break;
            case decltype(item)::Banana3:
                return LMS_MessageID::Item_TripleBananas;
            case decltype(item)::KouraG3:
                return LMS_MessageID::Item_TripleGreenShells;
            case decltype(item)::KouraR3:
                return LMS_MessageID::Item_TripleRedShells;
            default:
                break;
            }

            return LMS_MessageID::INVALID;
        }();

        if (message_id == LMS_MessageID::INVALID)
            return std::string(magic_enum::enum_name(item));

        return g_message_service->get(message_id);
    }

    std::string utils::item_name(Item::eItemType item)
    {
        auto const message_id = [item]()
        {
            switch (item)
            {
            case decltype(item)::KouraG:
                return LMS_MessageID::Item_GreenShell;
            case decltype(item)::KouraR:
                return LMS_MessageID::Item_RedShell;
            case decltype(item)::Banana:
                return LMS_MessageID::Item_Banana;
            case decltype(item)::Kinoko:
                return LMS_MessageID::Item_Mushroom;
            case decltype(item)::Star:
                return LMS_MessageID::Item_SuperStar;
            case decltype(item)::KouraB:
                return LMS_MessageID::Item_SpinyShell;
            case decltype(item)::Thunder:
                return LMS_MessageID::Item_Lightning;
            case decltype(item)::FakeBox:
                break;
            case decltype(item)::KinokoP:
                return LMS_MessageID::Item_GoldenMushroom;
            case decltype(item)::Bomhei:
                return LMS_MessageID::Item_Bobomb;
            case decltype(item)::Gesso:
                return LMS_MessageID::Item_Blooper;
            case decltype(item)::BigKinoko:
                break;
            case decltype(item)::Killer:
                return LMS_MessageID::Item_BulletBill;
            case decltype(item)::Flower:
                return LMS_MessageID::Item_FireFlower;
            case decltype(item)::Tail:
                return LMS_MessageID::Item_SuperLeaf;
            case decltype(item)::Seven:
                return LMS_MessageID::Item_LuckySeven;
            default:
                break;
            }

            return LMS_MessageID::INVALID;
        }();

        if (message_id == LMS_MessageID::INVALID)
            return std::string(magic_enum::enum_name(item));

        return g_message_service->get(message_id);
    }

    std::string utils::course_name(RaceSys::ECourseID course)
    {
        if (course == RaceSys::ECourseID::MAX)
            return g_message_service->get(LMS_MessageID::Course_Random);

        auto const map = std::map<std::string, std::string>
        {
            { FONT_N_1 FONT_64_1, "N64" },
            { FONT_GB FONT_A, "GBA" },
            { FONT_GC_1 FONT_N_2, "GCN" },
            { FONT_SN FONT_ES, "SNES" },
            { FONT_DS, "DS" },
            { FONT_Wii, "Wii" },
        };
        
        auto const message_id = Sequence::GetMessageIDConverter()->m_course_message_ids[std::to_underlying(course)];
        auto const message = g_message_service->get(message_id);

        for (auto const &[original, replacement] : map)
            if (message.starts_with(original))
                return replacement + message.substr(original.size());

        return message;
    }
}