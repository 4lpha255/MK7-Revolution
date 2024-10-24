#include <base/utils.hpp>

#include <base/services/message_service.hpp>

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
            }

            return LMS_MessageID::INVALID;
        }();

        if (message_id == LMS_MessageID::INVALID)
            return std::string(magic_enum::enum_name(item));

        return g_message_service->get(message_id);
    }
}