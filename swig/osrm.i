%module osrm

%{
#include "util/exception_utils.hpp"
#include "util/log.hpp"
#include "util/meminfo.hpp"
#include "util/version.hpp"

#include "osrm/engine_config.hpp"
#include "osrm/exception.hpp"
#include "osrm/osrm.hpp"
#include "storage/shared_memory.hpp"
#include "osrm/storage_config.hpp"
#include "storage/storage.hpp"
%}
