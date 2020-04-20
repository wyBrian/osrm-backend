#ifndef OSRM_SWIG_OSRM_HPP
#define OSRM_SWIG_OSRM_HPP

#include <vector>

#include "util/exception_utils.hpp"
#include "util/log.hpp"
#include "util/meminfo.hpp"
#include "util/typedefs.hpp"
#include "util/version.hpp"

#include "storage/serialization.hpp"
#include "storage/shared_memory.hpp"
#include "storage/shared_monitor.hpp"
#include "storage/storage.hpp"
#include "storage/storage_config.hpp"

#include "engine/engine.hpp"

#include "osrm/engine_config.hpp"
#include "osrm/exception.hpp"
#include "osrm/osrm.hpp"
#include "osrm/storage_config.hpp"


struct EngineConfig {
    std::string base_path;
    int max_locations_trip = -1;
    int max_locations_viaroute = -1;
    int max_locations_distance_table = -1;
    int max_locations_map_matching = -1;
    double max_radius_map_matching = -1.0;
    int max_results_nearest = -1;
    int max_alternatives = 3;
    bool use_mmap = false;
    bool useMld = false;
    std::string verbosity;
    std::string dataset_name;
};

enum Profile {
    CAR, BIKE, FOOT
};

class Coordinate {
public:
    explicit Coordinate(float lat, float lon) : lat(lat), lon(lon) {
        if (lat < -90.0 || lat > 90.0 || lon < -180.0 || lat > 180.0) {
            throw std::out_of_range("latitude" + std::to_string(lat) + " or longitude " + std::to_string(lon) + " out of range");
        }
    }
    float getLat() {
        return this->lat;
    }
    float getLon() {
        return this->lon;
    }

private:
    float lat;
    float lon;
};

class Bearing {
public:
    explicit Bearing(uint32_t value, uint32_t range) : value(value), range(range) {
        if (value >= 360 || range >= 180) {
            throw std::out_of_range("value " + std::to_string(value) + " or range " + std::to_string(range) + " out of range");
        }
    }
    int getValue() {
        return this->value;
    }
    int getRange() {
        return this->range;
    }

private:
    uint32_t value;
    uint32_t range;
};

struct Radius {
    uint32_t radius;
};

struct BaseParameters {
    Profile profile;
    std::vector<Coordinate> coordinates;
    std::vector<Bearing> bearings;
    std::vector<Radius> radiuses;
};

struct RouteParameters : public BaseParameters {
    bool alternatives = false;
    bool steps = false;
    bool annotations = false;
    bool returnGeoJson = true;
    bool returnOverview = false;
};

struct TableParameters : public BaseParameters {
    std::vector<size_t> sources;
    std::vector<size_t> destinations;
};

struct NearestParameters : public BaseParameters {
    uint32_t number = 1;
};

struct TripParameters : public BaseParameters {
    bool steps = false;
    bool annotations = false;
    bool returnGeoJson = true;
    bool returnOverview = false;
};

struct MatchParameters : public BaseParameters {
    bool steps = false;
    bool annotations = false;
    bool returnGeoJson = true;
    bool returnOverview = false;
    std::vector<long> timestamps;
    std::vector<double> radiuses;
};

struct TileParameters {
    Profile profile;
    int x;
    int y;
    int zoom;
};

class ServiceHandler {
public:
    explicit ServiceHandler(osrm::EngineConfig &config) : routing_machine(config) {
    }

    ~ServiceHandler() {}

    osrm::engine::Status Route(const RouteParameters &params, std::string &result);

    osrm::engine::Status Table(const TableParameters &params, std::string &result);

    osrm::engine::Status Nearest(const NearestParameters &params, std::string &result);

    osrm::engine::Status Trip(const TripParameters &params, std::string &result);

    osrm::engine::Status Match(const MatchParameters &params, std::string &result);

    osrm::engine::Status Tile(const TileParameters &params, std::string &result);

private:
    osrm::OSRM routing_machine;

    static osrm::engine::api::RouteParameters translate(const RouteParameters &raw);

    static osrm::engine::api::TableParameters translate(const TableParameters &raw);

    static osrm::engine::api::NearestParameters translate(const NearestParameters &raw);

    static osrm::engine::api::TripParameters translate(const TripParameters &raw);

    static osrm::engine::api::MatchParameters translate(const MatchParameters &raw);

    static osrm::engine::api::TileParameters translate(const TileParameters &raw);

    static void serialize(const osrm::util::json::Object &json, std::string &txt);

    static osrm::engine::EngineConfig translate(const EngineConfig &raw);
};

#endif //OSRM_SWIG_OSRM_HPP
