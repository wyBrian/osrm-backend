%module osrm

%{
#include <vector>
#include "swig_osrm.hpp"
%}

#ifdef SWIGJAVA
#endif

%include <stl.i>

%import "swig_osrm.hpp"

%include <enums.swg>

%ignore std::vector<Coordinate>::vector(size_type);
%template(CoordinateVector) std::vector<Coordinate>;

%ignore std::vector<Bearing>::vector(size_type);
%template(BearingVector) std::vector<Bearing>;

%ignore std::vector<Radius>::vector(size_type);
%template(RadiusVector) std::vector<Radius>;

%include "swig_osrm.hpp"
