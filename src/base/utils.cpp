#include <base/utils.hpp>

#include <base/services/message_service.hpp>

namespace base
{
    std::optional<std::string> utils::item_name(Item::eItemSlot item)
    {
        auto const get_message = [](auto const &i) { return g_message_service->get("Common", i); };

        switch (item)
        {
        case decltype(item)::Banana:
            return get_message(LMS_MessageID::Item_Banana);
        case decltype(item)::KouraG:
            return get_message(LMS_MessageID::Item_GreenShell);
        case decltype(item)::KouraR:
            return get_message(LMS_MessageID::Item_RedShell);
        case decltype(item)::Kinoko:
            return get_message(LMS_MessageID::Item_Mushroom);
        case decltype(item)::Bomhei:
            return get_message(LMS_MessageID::Item_Bobomb);
        case decltype(item)::Gesso:
            return get_message(LMS_MessageID::Item_Blooper);
        case decltype(item)::KouraB:
            return get_message(LMS_MessageID::Item_SpinyShell);
        case decltype(item)::Kinoko3:
            return get_message(LMS_MessageID::Item_TripleMushrooms);
        case decltype(item)::Star:
            return get_message(LMS_MessageID::Item_SuperStar);
        case decltype(item)::Killer:
            return get_message(LMS_MessageID::Item_BulletBill);
        case decltype(item)::Thunder:
            return get_message(LMS_MessageID::Item_Lightning);
        case decltype(item)::KinokoP:
            return get_message(LMS_MessageID::Item_GoldenMushroom);
        case decltype(item)::Flower:
            return get_message(LMS_MessageID::Item_FireFlower);
        case decltype(item)::Tail:
            return get_message(LMS_MessageID::Item_SuperLeaf);
        case decltype(item)::Seven:
            return get_message(LMS_MessageID::Item_LuckySeven);
        case decltype(item)::Test3:
        case decltype(item)::Test4:
            break;
        case decltype(item)::Banana3:
            return get_message(LMS_MessageID::Item_TripleBananas);
        case decltype(item)::KouraG3:
            return get_message(LMS_MessageID::Item_TripleGreenShells);
        case decltype(item)::KouraR3:
            return get_message(LMS_MessageID::Item_TripleRedShells);
        }

        return {};
    }

    std::optional<std::string> utils::item_name(Item::eItemType item)
    {
        auto const get_message = [](auto const &i) { return g_message_service->get("Common", i); };

        switch (item)
        {
        case decltype(item)::KouraG:
            return get_message(LMS_MessageID::Item_GreenShell);
        case decltype(item)::KouraR:
            return get_message(LMS_MessageID::Item_RedShell);
        case decltype(item)::Banana:
            return get_message(LMS_MessageID::Item_Banana);
        case decltype(item)::Kinoko:
            return get_message(LMS_MessageID::Item_Mushroom);
        case decltype(item)::Star:
            return get_message(LMS_MessageID::Item_SuperStar);
        case decltype(item)::KouraB:
            return get_message(LMS_MessageID::Item_SpinyShell);
        case decltype(item)::Thunder:
            return get_message(LMS_MessageID::Item_Lightning);
        case decltype(item)::FakeBox:
            break;
        case decltype(item)::KinokoP:
            return get_message(LMS_MessageID::Item_GoldenMushroom);
        case decltype(item)::Bomhei:
            return get_message(LMS_MessageID::Item_Bobomb);
        case decltype(item)::Gesso:
            return get_message(LMS_MessageID::Item_Blooper);
        case decltype(item)::BigKinoko:
            break;
        case decltype(item)::Killer:
            return get_message(LMS_MessageID::Item_BulletBill);
        case decltype(item)::Flower:
            return get_message(LMS_MessageID::Item_FireFlower);
        case decltype(item)::Tail:
            return get_message(LMS_MessageID::Item_SuperLeaf);
        case decltype(item)::Seven:
            return get_message(LMS_MessageID::Item_LuckySeven);
        }

        return {};
    }
}