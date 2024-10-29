#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    bool display_courses(CTRPluginFramework::Keyboard &, std::set<RaceSys::ECourseID> &);

    void entries::network::course_vote_controller_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;

        auto &course_vote_controller = g_settings.m_options.network.course_vote_controller;

        while (true)
        {
        _main:
            keyboard.GetMessage() = entry->Name();

            auto options = std::vector<std::string>{ std::format("Mode ({})", magic_enum::enum_name(course_vote_controller.mode)) };
            switch (course_vote_controller.mode)
            {
            case decltype(course_vote_controller.mode)::Direct:
                options.push_back(std::format("{}", magic_enum::enum_name(course_vote_controller.direct_mode)));
                break;
            case decltype(course_vote_controller.mode)::Filter:
                options.push_back(std::format("{}", magic_enum::enum_name(course_vote_controller.filter_mode)));
                switch (course_vote_controller.filter_mode)
                {
                case decltype(course_vote_controller.filter_mode)::Whitelist:
                    options.push_back(std::format("List ({})", course_vote_controller.whitelist_set.size()));
                    break;
                case decltype(course_vote_controller.filter_mode)::Blacklist:
                    options.push_back(std::format("List ({})", course_vote_controller.blacklist_set.size()));
                    break;
                }
                break;
            }
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: utils::enum_next(course_vote_controller.mode); break;
                case 1:
                {
                    switch (course_vote_controller.mode)
                    {
                    case decltype(course_vote_controller.mode)::Direct:
                        utils::enum_next(course_vote_controller.direct_mode);
                        break;
                    case decltype(course_vote_controller.mode)::Filter:
                        utils::enum_next(course_vote_controller.filter_mode);
                        break;
                    }
                    break;
                }
                case 2:
                {
                    keyboard.GetMessage() = entry->Name() + "\n" + std::string(magic_enum::enum_name(course_vote_controller.filter_mode));

                    while (true)
                    {
                        switch (course_vote_controller.filter_mode)
                        {
                        case decltype(course_vote_controller.filter_mode)::Whitelist:
                            if (!display_courses(keyboard, course_vote_controller.whitelist_set))
                                goto _main;
                            break;
                        case decltype(course_vote_controller.filter_mode)::Blacklist:
                            if (!display_courses(keyboard, course_vote_controller.blacklist_set))
                                goto _main;
                            break;
                        }
                    }

                    break;
                }
            }
        }
    }

    bool display_courses(CTRPluginFramework::Keyboard &keyboard, std::set<RaceSys::ECourseID> &set)
    {
        auto const courses = std::to_array({ RaceSys::ECourseID::Gctr_MarioCircuit, RaceSys::ECourseID::Gctr_RallyCourse, RaceSys::ECourseID::Gctr_MarineRoad, RaceSys::ECourseID::Gctr_GlideLake, RaceSys::ECourseID::Gctr_ToadCircuit, RaceSys::ECourseID::Gctr_SandTown, RaceSys::ECourseID::Gctr_AdvancedCircuit, RaceSys::ECourseID::Gctr_DKJungle, RaceSys::ECourseID::Gctr_WuhuIsland1, RaceSys::ECourseID::Gctr_WuhuIsland2, RaceSys::ECourseID::Gctr_IceSlider, RaceSys::ECourseID::Gctr_BowserCastle, RaceSys::ECourseID::Gctr_UnderGround, RaceSys::ECourseID::Gctr_RainbowRoad, RaceSys::ECourseID::Gctr_WarioShip, RaceSys::ECourseID::Gctr_MusicPark, RaceSys::ECourseID::Gwii_CoconutMall, RaceSys::ECourseID::Gwii_KoopaCape, RaceSys::ECourseID::Gwii_MapleTreeway, RaceSys::ECourseID::Gwii_MushroomGorge, RaceSys::ECourseID::Gds_LuigisMansion, RaceSys::ECourseID::Gds_AirshipFortress, RaceSys::ECourseID::Gds_DKPass, RaceSys::ECourseID::Gds_WaluigiPinball, RaceSys::ECourseID::Ggc_DinoDinoJungle, RaceSys::ECourseID::Ggc_DaisyCruiser, RaceSys::ECourseID::Gn64_LuigiCircuit, RaceSys::ECourseID::Gn64_KalimariDesert, RaceSys::ECourseID::Gn64_KoopaTroopaBeach, RaceSys::ECourseID::Gagb_BowserCastle1, RaceSys::ECourseID::Gsfc_MarioCircuit2, RaceSys::ECourseID::Gsfc_RainbowRoad, RaceSys::ECourseID::Bctr_WuhuIsland3, RaceSys::ECourseID::Bctr_HoneyStage, RaceSys::ECourseID::Bctr_IceRink, RaceSys::ECourseID::Bds_PalmShore, RaceSys::ECourseID::Bn64_BigDonut, RaceSys::ECourseID::Bagb_BattleCourse1 });

        auto options = std::vector<std::string>();
        std::for_each(courses.begin(), courses.end(), [&](auto const &c) { options.push_back(std::format("{} ({})", utils::course_name(c), menu::toggle_name(set.contains(c)))); });
        keyboard.Populate(options);

        auto const choice = keyboard.Open();
        if (choice < 0)
            return false;

        if (auto const course = courses.at(choice); set.contains(course))
            set.erase(course);
        else
            set.emplace(course);

        return true;
    }
}