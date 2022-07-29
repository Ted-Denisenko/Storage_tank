#include "Storage_tank.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;

int main(int argc, const char* argv[])
{
    
    options_description desc{ "Options" };
    desc.add_options()
        ("help,h", "Help screen")
        ("diameter,diam", value<int>()->required()->default_value(500), "Tank diameter")
        ("height,hght", value<int>()->required()->default_value(1000), "Tank height")
        ("level,lvl", value<int>()->required()->default_value(600), "Content level")
        ("density, dens", value<double>()->required()->default_value(1040), "Content density");
    try
    {
        variables_map vm; // � ���� ������ ����� ������� ��� ��������-��������, ������� �������� �� ��������� ����������
        store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else
        {
            ContentMass(
                        ContentValue(vm["level"].as<int>(), vm["height"].as<int>(), vm["diameter"].as<int>())
                        , vm.at("density").as<double>());
        }
        
    }
    catch (const error& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}