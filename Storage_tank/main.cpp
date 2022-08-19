#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;
using namespace boost::units;
using namespace boost::units::si;


void doMaths(StorageTank* bptr)
{
    bptr->ContentVolume();
    bptr->ContentMass();
}

template < typename T >
void doPrint(T& Tank)
{
    Tank.printVolume();
    Tank.printMass();
}

int main(int argc, const char* argv[])
{

    options_description desc{ "Options" };
    desc.add_options()
        ("help,h", "Help screen")
        ("tank_type,type", value<std::string>()->required()->default_value("h"), "Tank type")
        ("diameter,diam",  value<double>()->required()->default_value(500), "Tank diameter")
        ("height,hght",    value<double>()->required()->default_value(1000), "Tank height")
        ("level,lvl",      value<int>()->required()->default_value(600), "Content level")
        ("density, dens",  value<double>()->required()->default_value(1040), "Content density");
    try
    {
        variables_map vm;
        parse_command_line(argc, argv, desc);
        store(parse_command_line(argc, argv, desc), vm);

        auto tankType = vm["tank_type"].as<std::string>();
        auto diam = vm["diameter"].as<double>();
        auto height = vm["height"].as<double>();
        auto level = vm["level"].as<int>();
        auto dens = vm["density"].as<double>();

        if (vm.count("help") || diam < 0.0 || height < 0.0 || level < 0.0 || dens < 0.0)
        {
            std::cout << desc << '\n';
            std::cout << "**Every value must be positive**" << '\n';
            return 0;
        }

        StorageTank* bptr;
        if (tankType == "h")
        {
            HorizontalStorageTank h(
                diam,
                height,
                level,
                dens);

            bptr = &h;

            doMaths(bptr);
            doPrint(h);
        }
        else if (tankType == "v")
        {
            VerticalStorageTank v(
                diam,
                height,
                level,
                dens);

            bptr = &v;

            doMaths(bptr);
            doPrint(v);
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