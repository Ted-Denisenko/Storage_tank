#include "Storage_tank.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;

int main(int argc, const char* argv[])
{
    try
    {
        options_description desc{ "Options" };
        desc.add_options()
            ("help,h", "Help screen")
            ("diameter,diam", value<int>()->default_value(500), "Tank diameter")
            ("height,hght", value<int>()->default_value(1000), "Tank height")
            ("level,lvl", value<int>()->default_value(600), "Content level")
            ("density, dens", value<int>()->default_value(1040), "Content density");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else if(!vm.count(""))
        {
            std::cout << "Magic is happening" << std::endl;
        }
        
        //ContentMass(ContentValue(LevelInput(vm["level"].as<int>())));

    }
    catch (const error& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}