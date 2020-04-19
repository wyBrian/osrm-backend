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

#include "engine/engine.hpp"

#include "osrm/engine_config.hpp"
#include "osrm/exception.hpp"
#include "osrm/osrm.hpp"
#include "osrm/storage_config.hpp"

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
    explicit Bearing(float bearing) : bearing(bearing) {
        if (bearing >= 360.0 || bearing < 0.0) {
            throw std::out_of_range("bearing " + std::to_string(bearing) + " out of range");
        }
    }
    float getBearing() {
        return this->bearing;
    }

private:
    float bearing;
};

class Radius {
public:
    explicit Radius(float radius) : radius(radius) {
        if (radius < 0.0) {
            throw std::out_of_range("radius " + std::to_string(radius) + " out of range");
        }
    }
    float getRadius() {
        return this->radius;
    }

private:
    float radius;
};

struct BaseParameters {
    Profile profile;
    std::vector<Coordinate> coordinates;
    std::vector<Bearing> bearings;
    std::vector<Radius> radiuses;
};

struct RouteParameters : BaseParameters {

};

struct TableParameters : BaseParameters {

};

struct NearestParameters : BaseParameters {

};

struct TripParameters : BaseParameters {

};

struct MatchParameters : BaseParameters {

};

struct TileParameters : BaseParameters {

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
};

#endif //OSRM_SWIG_OSRM_HPP
