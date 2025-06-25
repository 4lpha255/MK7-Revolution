#include <base/entries.hpp>

#include <base/settings.hpp>
#include <base/utils.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    using type = settings::options::item::item_model::type;

    std::string model_name(type);

    void entries::item::item_model_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &item_model = g_settings.m_options.item.item_model;

        while (true)
        {
            auto options = std::vector<std::string>();
            std::for_each(item_model.items.begin(), item_model.items.end(), [&](auto const &e) { options.push_back(std::format("{} ({})", utils::item_name(e.first), model_name(e.second))); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &item = std::next(item_model.items.begin(), choice);
            item->second = magic_enum::enum_next_value_circular(item->second);
        }
    }

    std::string model_name(type t)
    {
        if (t == type::Default)
            return std::string(magic_enum::enum_name(t));

        if (t == type::KouraBUnused)
            return CTRPluginFramework::Color::Blue << "Unused " + utils::item_name(Item::eItemType::KouraB) + CTRPluginFramework::ResetColor();

        auto const name = std::string(magic_enum::enum_name(t));
        if (auto const item = magic_enum::enum_cast<Item::eItemType>(name); item.has_value())
            return CTRPluginFramework::Color::Lime << utils::item_name(item.value()) + CTRPluginFramework::ResetColor();
        
        return name;
    }
}