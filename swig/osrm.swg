%module osrm

%{
#include <vector>
#include "swig_osrm.hpp"
%}

%include "swig_osrm.hpp"

#ifdef SWIGJAVA   //swig到java的swig预定义宏
%include <enums.swg>
%template(CoordinateVector) std::vector<Coordinate>;
%template(BearingVector) std::vector<Bearing>;
%template(RadiusVector) std::vector<Radius>;
%rename(CoordinateVector) Vector<Coordinate>;
%rename(BearingVector) Vector<Bearing>;
%rename(RadiusVector) Vector<Radius>;
#endif
