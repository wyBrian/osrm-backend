%module osrm

%{
#include <vector>
#include "swig_osrm.hpp"
%}

%import <stl.i>
%import "swig_osrm.hpp"

%include <std_vector.i>

%include <enums.swg>

%ignore std::vector<Coordinate>::vector(size_type);
%template(CoordinateVector) std::vector<Coordinate>;

%ignore std::vector<Bearing>::vector(size_type);
%template(BearingVector) std::vector<Bearing>;

%ignore std::vector<Radius>::vector(size_type);
%template(RadiusVector) std::vector<Radius>;

#ifdef SWIGJAVA
%rename(CoordinateVector) Vector<Coordinate>;
%rename(BearingVector) Vector<Bearing>;
%rename(RadiusVector) Vector<Radius>;
#endif

%include "swig_osrm.hpp"
