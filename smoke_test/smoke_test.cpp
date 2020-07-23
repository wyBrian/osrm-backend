#include <iostream>
#include "../swig/swig_osrm.hpp"

int main () { 
	EngineConfig *engineConfig = new EngineConfig;
	engineConfig->base_path = "/Users/yu.w/workspace/apollo/data/osrm/countries/country.osrm";
	engineConfig->use_mld = true;
	engineConfig->use_mmap = true;
	ServiceHandler *handler = new ServiceHandler(*engineConfig);
	std::cout << handler << std::endl;		
	std::cout << engineConfig->base_path << std::endl;	
	std::cout << engineConfig->use_mld << std::endl;	
	std::cout << engineConfig->use_mmap << std::endl;	
	return 0;
}