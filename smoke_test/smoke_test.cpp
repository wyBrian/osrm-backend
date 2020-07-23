#include <iostream>
#include <vector>

#include "../swig/swig_osrm.hpp"


int main () { 
	EngineConfig *engineConfig = new EngineConfig;
	engineConfig->base_path = "/Users/yu.w/workspace/apollo/data/osrm/countries/country.osrm";
	engineConfig->use_mld = true;
	engineConfig->use_mmap = true;
	ServiceHandler *handler = new ServiceHandler(*engineConfig);

	TableParameters *tableParameters = new TableParameters;
	tableParameters->profile = CAR;
	std::vector<Coordinate> table_coords = {
		Coordinate(1.2830529f, 103.8383417f), Coordinate(1.2919341f, 103.8225059f)
	};
	tableParameters->coordinates = table_coords;
	std::cout << "Table Service Smoke Test" << std::endl;
	std::string table_res = handler->Table(*tableParameters);
	std::cout << table_res << std::endl;	


	MatchParameters *matchParameters = new MatchParameters;
	matchParameters->profile = CAR;
	std::vector<Coordinate> match_coords = {
		Coordinate(-6.3114f, 106.9723f), 
		Coordinate(-6.3144f, 106.9786f),
		Coordinate(-6.3136f, 106.9759f),
		Coordinate(-6.3139f, 106.9757f),
		Coordinate(-6.3139f, 106.9757f),
		Coordinate(-6.3139f, 106.9757f),
		Coordinate(-6.3137f, 106.9756f),
		Coordinate(-6.3137f, 106.9756f),
		Coordinate(-6.3137f, 106.9756f),
		Coordinate(-6.3149f, 106.9724f),
		Coordinate(-6.316f, 106.9733f),
		Coordinate(-6.3156f, 106.9739f)
	};
	matchParameters->coordinates = match_coords;
	std::vector<Radius> match_radius = {
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0},
		Radius{50.0}
	};
	matchParameters->radiuses = match_radius;
	std::vector<long> match_timestamps = {
		1583127588,
		1583127594,
		1583127663,
		1583127835,
		1583127851,
		1583127873,
		1583127910,
		1583127917,
		1583127925,
		1583128058,
		1583128133,
		1583128202
	};	
	matchParameters->timestamps = match_timestamps;
	matchParameters->gaps=true;
	matchParameters->tidy=false;
	matchParameters->steps=false;
	matchParameters->annotations=false;
	matchParameters->returnGeoJson=false;
	matchParameters->returnOverview=true;

	std::cout << "Match Service Smoke Test" << std::endl;
	std::string match_res = handler->Match(*matchParameters);
	std::cout << match_res << std::endl;	

	return 0;
}
