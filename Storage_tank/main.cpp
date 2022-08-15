#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"
#include <boost/program_options.hpp>


using namespace boost::program_options;


int main(int argc, const char* argv[])
{

    options_description desc{ "Options" };
    desc.add_options()
        ("help,h", "Help screen")
        ("tank_type,type", value<std::string>()/*->required()*/->default_value("h"), "Tank type")
        ("diameter,diam", value<double>()->required()->default_value(500), "Tank diameter")
        ("height,hght", value<double>()->required()->default_value(1000), "Tank height")
        ("level,lvl", value<double>()->required()->default_value(600), "Content level")
        ("density, dens", value<double>()->required()->default_value(1040), "Content density");
    try
    {
        variables_map vm; // � ���� ������ ����� ������� ��� ���-��������, ������� �������� �� ��������� ����������
        parse_command_line(argc, argv, desc); //����� ���� ��������� � ������, ������� ����� ��������� boost::options
        store(parse_command_line(argc, argv, desc), vm);
        if (vm.count("help"))
            std::cout << desc << '\n';
        else
        {
            std::string foo = "h";
            if (vm["type"].as<std::string>() == foo)
            {
                HorizontalStorageTank h(
                    vm["diameter"].as<double>(),
                    vm["height"].as<double>(),
                    vm["level"].as<double>(),
                    vm["density"].as<double>());

                h.ContentVolume();

                //Volume volume = ContentVolume(vm["level"].as<double>(), vm["height"].as<double>(), vm["diameter"].as<double>());
                //vm;
                //Mass mass = ContentMass(volume, vm.at("density").as<double>());
                ///*ContentMass(
                //            ContentValue(vm["level"].as<int>(), vm["height"].as<int>(), vm["diameter"].as<int>())
                //            , vm.at("density").as<double>());*/
                //printVolume(volume);
                //printMass(mass);
            }
        }
    }
    catch (const error& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}