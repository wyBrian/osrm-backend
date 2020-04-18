%module osrm

%{
    #include "osrm/osrm.hpp"
    #include "storage/shared_memory.hpp"
    #include "storage/storage.hpp"
%}

%include "osrm/osrm.hpp"
%include "storage/shared_memory.hpp"
%include "storage/storage.hpp"
