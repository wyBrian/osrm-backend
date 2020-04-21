%module osrm

%{
#include <vector>
#include "swig_osrm.hpp"
%}

#ifdef SWIGJAVA
#endif

%include <stl.i>
%include <std_string.i>
%include <std_except.i>
%include <swiginterface.i>
%include <typemaps.i>
%include <enums.swg>

%pragma(java) jniclasscode=%{
    static {
        System.loadLibrary("libswig_jni_bindings.so");
    }
%}

%apply long { std::size_t }; 

%ignore std::vector<Coordinate>::vector(size_type);
%template(CoordinateVector) std::vector<Coordinate>;

%ignore std::vector<Bearing>::vector(size_type);
%template(BearingVector) std::vector<Bearing>;

%ignore std::vector<Radius>::vector(size_type);
%template(RadiusVector) std::vector<Radius>;

%template(SizeTVector) std::vector<std::size_t>;
%template(LongVector) std::vector<long>;
%template(DoubleVector) std::vector<double>;

%include "swig_osrm.hpp"
