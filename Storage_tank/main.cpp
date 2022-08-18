#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;
using namespace boost::units;
using namespace boost::units::si;


int main(int argc, const char* argv[])
{

    options_description desc{ "Options" };
    desc.add_options()
        ("help,h", "Help screen")
        ("tank_type,type",  value<std::string>()->required()->default_value("h"), "Tank type")
        ("diameter,diam",   value<double>()->required()->default_value(500), "Tank diameter")
        ("height,hght",     value<double>()->required()->default_value(1000), "Tank height")
        ("level,lvl",       value<int>()->required()->default_value(600), "Content level")
        ("density, dens",   value<double>()->required()->default_value(1040), "Content density");
    try
    {
        variables_map vm;
        parse_command_line(argc, argv, desc);
        store(parse_command_line(argc, argv, desc), vm);
        if (vm.count("help"))
        {
            std::cout << desc << '\n';
            return 0;
        }
        StorageTank* bptr;
        if (vm["tank_type"].as<std::string>() == "h")
        {
            HorizontalStorageTank h(
                vm["diameter"].as<double>(),
                vm["height"].as<double>(),
                vm["level"].as<int>(),
                vm["density"].as<double>());

            bptr = &h;

            bptr->ContentVolume();
            bptr->ContentMass();
            h.printVolume();
            h.printMass();
        }
        else if (vm["tank_type"].as<std::string>() == "v")
        {
            VerticalStorageTank v(
                vm["diameter"].as<double>(),
                vm["height"].as<double>(),
                vm["level"].as<int>(),
                vm["density"].as<double>());

            bptr = &v;

            bptr->ContentVolume();
            bptr->ContentMass();
            v.printVolume();
            v.printMass();
        }
        else
        {
            std::cout << "invalid argument for tank type" << std::endl;
            return -1;
        }
        
    }
    catch (const error& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}