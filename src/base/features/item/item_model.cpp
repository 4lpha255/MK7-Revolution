#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#define ITEM_BANANA "Item/itemBanana/itemBanana.bcmdl"
#define ITEM_BOMHEI "Item/itemBombhei/itemBombhei.bcmdl"
#define ITEM_FLOWER "Item/itemFireball/itemFireball.bcmdl"
#define ITEM_GESSO "Item/itemGesso/itemGesso.bcmdl"
#define ITEM_KINOKO "Item/itemKinoko/itemKinoko.bcmdl"
#define ITEM_KOURAB "Item/itemTogezo/itemTogezo.bcmdl"
#define ITEM_KOURAG "Item/itemKouraGreen/itemKouraGreen.bcmdl"
#define ITEM_KOURAR "Item/itemKouraRed/itemKouraRed.bcmdl"
#define ITEM_STAR "Item/itemStar/itemStar.bcmdl"
#define ITEM_TAIL "Item/itemTail/itemTail.bcmdl"
#define ITEM_KOURABUNUSED "Item/itemKouraBlue/itemKouraBlue.bcmdl"

namespace base
{
    using type_t = settings::options::item::item_model::type;

    inline auto s_path_to_item = std::map<std::string, Item::eItemType>
    {
        { ITEM_BANANA, Item::eItemType::Banana },
        { ITEM_BOMHEI, Item::eItemType::Bomhei },
        { ITEM_FLOWER, Item::eItemType::Flower },
        { ITEM_GESSO, Item::eItemType::Gesso },
        { ITEM_KINOKO, Item::eItemType::Kinoko },
        { ITEM_KOURAB, Item::eItemType::KouraB },
        { ITEM_KOURAG, Item::eItemType::KouraG },
        { ITEM_KOURAR, Item::eItemType::KouraR },
        { ITEM_STAR, Item::eItemType::Star },
        { ITEM_TAIL, Item::eItemType::Tail },
    };

    inline auto s_type_to_path = std::map<type_t, char const *>
    {
        { type_t::Banana, ITEM_BANANA },
        { type_t::Bomhei, ITEM_BOMHEI },
        { type_t::Flower, ITEM_FLOWER },
        { type_t::Gesso, ITEM_GESSO },
        { type_t::Kinoko, ITEM_KINOKO },
        { type_t::KouraB, ITEM_KOURAB },
        { type_t::KouraG, ITEM_KOURAG },
        { type_t::KouraR, ITEM_KOURAR },
        { type_t::Star, ITEM_STAR },
        { type_t::Tail, ITEM_TAIL },
    };

    inline auto s_unused = ITEM_KOURABUNUSED;

    void features::item::item_model(char const *&fmt)
    {
        if (g_menu->m_item_model_entry->IsActivated())
        {
            auto const str = std::string(fmt);

            if (auto const it = s_path_to_item.find(str); it != s_path_to_item.end()) [[unlikely]]
            {
                auto const type = g_settings.m_options.item.item_model.items.at(it->second);

                if (type == type_t::KouraBUnused)
                    fmt = s_unused;
                else if (type != type_t::Default)
                    fmt = s_type_to_path.at(type);
            }
        }
    }
}