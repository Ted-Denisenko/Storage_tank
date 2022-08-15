#include "StorageTank.h"
#include <boost/program_options.hpp>


using namespace boost::program_options;

void print_current_C_locale()
{
    std::cout <<
        setlocale(LC_ALL, nullptr)
        << std::endl;
}

//региональные настройки не должны влиять на ввод и вывод программы
/*
*    для ввода:
узнать локаль пользователя
перевести текст вывода из текущей локали в подходящую для boost.options
    для вывода:
узнать локаль пользователя
вывести результат в локали пользователя
*/

int main(int argc, const char* argv[])
{
    //setlocale(LC_ALL, "");
    //std::cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << std::endl;
    //std::cout << "LC_CTYPE: " << setlocale(LC_CTYPE, NULL) << std::endl;

    ////setlocale(LC_ALL, "");

    //options_description desc{ "Options" };
    //desc.add_options()
    //    ("help,h", "Help screen")
    //    ("tank_type,type", value<std::string>()->required()->default_value("v"), "Tank type")
    //    ("diameter,diam", value<double>()->required()->default_value(500), "Tank diameter")
    //    ("height,hght", value<double>()->required()->default_value(1000), "Tank height")
    //    ("level,lvl", value<double>()->required()->default_value(600), "Content level")
    //    ("density, dens", value<double>()->required()->default_value(1040), "Content density");
    //try
    //{
    //    variables_map vm; // в мапе всегда будет столько пар имя-значение, сколько значений по умолчанию выставлено
    //    parse_command_line(argc, argv, desc); //здесь надо перевести в локаль, которую может прочитать boost::options
    //    store(parse_command_line(argc, argv, desc), vm);

    //    if (vm.count("help"))
    //        std::cout << desc << '\n';
    //    else
    //    {
    //        if (vm["type"].as<std::string>() == "h")
    //        {
    //            Volume volume = ContentVolume(vm["level"].as<double>(), vm["height"].as<double>(), vm["diameter"].as<double>());
    //            vm;
    //            Mass mass = ContentMass(volume, vm.at("density").as<double>());
    //            /*ContentMass(
    //                        ContentValue(vm["level"].as<int>(), vm["height"].as<int>(), vm["diameter"].as<int>())
    //                        , vm.at("density").as<double>());*/
    //            printVolume(volume);
    //            printMass(mass);
    //        }
    //    }
    //}
    //catch (const error& ex)
    //{
    //    std::cerr << ex.what() << '\n';
    //}
}