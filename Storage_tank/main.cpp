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

template <class C>
C createClassElem(std::string tankType,
    quantity<length> param_tankDiameter,
    quantity<length> param_tankHeight,
    quantity<length> param_contentLevel,
    quantity<mass_density> param_contentDensity)
{
    if (tankType == "h")
    {
        HorizontalStorageTank h(
            param_tankDiameter,
            param_tankHeight,
            param_contentLevel,
            param_contentDensity);
        return h;
    }
    else if (tankType == "v")
    {
        VerticalStorageTank v(
            param_tankDiameter,
            param_tankHeight,
            param_contentLevel,
            param_contentDensity);
        return v;
    }
    else
    {
        std::cout << "invalid argument for tank type" << std::endl;
        return -1;
    }
}

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

        boost::units::quantity<boost::units::si::length> tankDiameter(diam * milli * meters);
        boost::units::quantity<boost::units::si::length> tankHeight(height * milli * meters);
        boost::units::quantity<boost::units::si::length> contentLevel(level * milli * meters);
        boost::units::quantity<boost::units::si::mass_density> contentDensity(dens * kilogrammes_per_cubic_metre);

        //if (tankType == "h")
        //{
        //    HorizontalStorageTank h(
        //        diam,
        //        height,
        //        level,
        //        dens);

        //    bptr = &h;
        //    bptr->ContentVolume();
        //    bptr->ContentMass();
        //    std::cout << bptr->getVolume() << std::endl; 
        //    std::cout << bptr->getMass() << std::endl;
        //}
        //else if (tankType == "v")
        //{
        //    VerticalStorageTank v(
        //        diam,
        //        height,
        //        level,
        //        dens);

        //    bptr = &v;
        //    bptr->ContentVolume();
        //    bptr->ContentMass();
        //    std::cout << bptr->getVolume() << std::endl;
        //    std::cout << bptr->getMass() << std::endl;
        //}
        //else
        //{
        //    std::cout << "invalid argument for tank type" << std::endl;
        //    return -1;
        //}
        
    }
    catch (const error& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}