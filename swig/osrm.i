%module osrm

%{
#include <vector>
#include "swig_osrm.hpp"
%}

%import <stl.i>
%import "swig_osrm.hpp"

#ifdef SWIGJAVA
%include <enums.swg>
%template(CoordinateVector) std::vector<Coordinate>;
%template(BearingVector) std::vector<Bearing>;
%template(RadiusVector) std::vector<Radius>;
//%rename(CoordinateVector) Vector<Coordinate>;
//%rename(BearingVector) Vector<Bearing>;
//%rename(RadiusVector) Vector<Radius>;
#endif

%include "swig_osrm.hpp"
