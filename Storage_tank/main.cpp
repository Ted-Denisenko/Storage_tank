#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"
#include <boost/program_options.hpp>
#include <boost/leaf.hpp>
#include <boost/leaf/exception.hpp>

using namespace boost::program_options;
using namespace boost::units;
using namespace boost::units::si;

enum class errors { invalidTankType = -1, invalidTankParameters = -2 };

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

boost::leaf::result<int> check_tankType(std::string tankType)
{
    if (tankType != "v" && tankType != "h")
        /*return boost::leaf::new_error(errors::invalidTankType);*/
        BOOST_LEAF_THROW_EXCEPTION(errors::invalidTankType);
    return 0;
}

boost::leaf::result<int> check_tankParameters(double diam, double height, int level, double dens)
{
    if (diam < 0.0 || height < 0.0 || level < 0.0 || dens < 0.0)
        /*return boost::leaf::new_error(errors::invalidTankParameters);*/
        BOOST_LEAF_THROW_EXCEPTION(errors::invalidTankParameters);
    return 0;
}

template <typename T>
boost::leaf::result<T> CheckInput(std::string tankType, double diam, double height, int level, double dens)
{
    boost::leaf::result<T> checkTypeResult = check_tankType(tankType);
    if (!checkTypeResult)
        return checkTypeResult.error();
    boost::leaf::result<T> checkParamsResult = check_tankParameters(diam, height, level, dens);
    if (!checkParamsResult)
        return checkParamsResult.error();

    return 0;
}

//template <class C>
//C createTank(std::string tankType,
//    quantity<length,double> param_tankDiameter,
//    quantity<length, double> param_tankHeight,
//    quantity<length, double> param_contentLevel,
//    quantity<mass_density, double> param_contentDensity)
//{
//    if (tankType == "h")
//    {
//        HorizontalStorageTank h(
//            param_tankDiameter,
//            param_tankHeight,
//            param_contentLevel,
//            param_contentDensity);
//        return h;
//    }
//    else if (tankType == "v")
//    {
//        VerticalStorageTank v(
//            param_tankDiameter,
//            param_tankHeight,
//            param_contentLevel,
//            param_contentDensity);
//        return v;
//    }
//    else
//    {
//        // TODO: здесь нужно выкидывать исключение (см. тикет №69)
//
//        std::cout << "invalid argument for tank type" << std::endl;
//        return -1;
//    }
//}

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

        // TODO: #69 - не допускать создания вырожденных резервуаров (невозможный параметр)
        // проверка ввода: при невозможном параметре определит ошибку и вернет -1
        if(!CheckInput<int>(tankType, diam, height, level, dens))
            return -1;        

        if (vm.count("help"))
        {
            std::cout << desc << '\n';
            return 0;
        }
        StorageTank* bptr;

        quantity<length> tankDiameter(diam * milli * meters);
        quantity<length> tankHeight(height * milli * meters);
        quantity<length> contentLevel(level * milli * meters);
        quantity<mass_density> contentDensity(dens * kilogrammes_per_cubic_metre);

        //bptr = &(createTank(tankType,tankDiameter,tankHeight, contentLevel, contentDensity));

        if (tankType == "h")
        {
            HorizontalStorageTank h(
                tankDiameter,
                tankHeight,
                contentLevel,
                contentDensity);

            bptr = &h;
            bptr->ContentVolume();
            bptr->ContentMass();
            std::cout << bptr->getVolume() << std::endl; 
            std::cout << bptr->getMass() << std::endl;
        }
        else if (tankType == "v")
        {
            VerticalStorageTank v(
                tankDiameter,
                tankHeight,
                contentLevel,
                contentDensity);

            bptr = &v;
            bptr->ContentVolume();
            bptr->ContentMass();
            std::cout << bptr->getVolume() << std::endl;
            std::cout << bptr->getMass() << std::endl;
        }
        else
        {
            // TODO: #69 - не допускать создания вырожденных резервуаров (несуществующий тип резервуара)
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