#include "osrm/osrm.hpp"

#include "engine/algorithm.hpp"
#include "engine/api/match_parameters.hpp"
#include "engine/api/nearest_parameters.hpp"
#include "engine/api/route_parameters.hpp"
#include "engine/api/table_parameters.hpp"
#include "engine/api/trip_parameters.hpp"
#include "engine/engine.hpp"
#include "engine/engine_config.hpp"
#include "engine/status.hpp"

#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

#include <memory>

namespace osrm
{

// Pimpl idiom

OSRM::OSRM(engine::EngineConfig &config)
{
    using CH = engine::routing_algorithms::ch::Algorithm;
    using MLD = engine::routing_algorithms::mld::Algorithm;

    // First, check that necessary core data is available
    if (!config.use_shared_memory && !config.storage_config.IsValid())
    {
        throw util::exception("Required files are missing, cannot continue.  Have all the "
                              "pre-processing steps been run?");
    }

    // Now, check that the algorithm requested can be used with the data
    // that's available.

    if (config.algorithm == EngineConfig::Algorithm::CoreCH)
    {
        util::Log(logWARNING) << "Using CoreCH is deprecated. Falling back to CH";
        config.algorithm = EngineConfig::Algorithm::CH;
    }

    switch (config.algorithm)
    {
    case EngineConfig::Algorithm::CH:
        engine_ = std::make_unique<engine::Engine<CH>>(config);
        break;
    case EngineConfig::Algorithm::MLD:
        engine_ = std::make_unique<engine::Engine<MLD>>(config);
        break;
    default:
        util::exception("Algorithm not implemented!");
    }
}
OSRM::~OSRM() = default;
OSRM::OSRM(OSRM &&) noexcept = default;
OSRM &OSRM::operator=(OSRM &&) noexcept = default;

// Forward to implementation

engine::Status OSRM::Route(const engine::api::RouteParameters &params,
                           util::json::Object &result) const
{
    return engine_->Route(params, result);
}

engine::Status OSRM::Table(const engine::api::TableParameters &params, json::Object &result) const
{
    return engine_->Table(params, result);
}

engine::Status OSRM::Nearest(const engine::api::NearestParameters &params,
                             json::Object &result) const
{
    return engine_->Nearest(params, result);
}

engine::Status OSRM::Trip(const engine::api::TripParameters &params, json::Object &result) const
{
    return engine_->Trip(params, result);
}

template <typename Enumeration>
auto as_integer(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

engine::Status OSRM::Match(const engine::api::MatchParameters &params, json::Object &result) const
{
    std::cout << "DEBUGGING MATCH SERVICE" << std::endl;
    std::cout << "timestamps" << std::endl;
    for(unsigned t : params.timestamps) {
        std::cout << t << std::endl;
    }
    std::cout << "radiuses" << std::endl;
    for(boost::optional<double> r : params.radiuses) {
        std::cout << r << std::endl;
    }
    std::cout << "coordinates" << std::endl;
    for(util::Coordinate c : params.coordinates) {
        std::cout << "lat: " << c.lat << " lon: " << c.lon << std::endl;
    }
    std::cout << "waypoints" << std::endl;
    for(std::size_t wp : params.waypoints) {
        std::cout << wp << std::endl;
    }
    std::cout << "tidy: " << params.tidy << std::endl;    
    std::cout << "gaps: " << as_integer(params.gaps) << std::endl;    
    std::cout << "steps: " << params.steps << std::endl;    
    std::cout << "alternatives: " << params.alternatives << std::endl;    
    std::cout << "number_of_alternatives: " << params.number_of_alternatives << std::endl;    
    std::cout << "annotations: " << params.annotations << std::endl;    
    std::cout << "annotations_type: " << as_integer(params.annotations_type) << std::endl;    
    std::cout << "geometries: " << as_integer(params.geometries) << std::endl;    
    std::cout << "overview: " << as_integer(params.overview) << std::endl;    
    std::cout << "continue_straight: " << params.continue_straight << std::endl;    
    return engine_->Match(params, result);
}

engine::Status OSRM::Tile(const engine::api::TileParameters &params, std::string &result) const
{
    return engine_->Tile(params, result);
}

} // ns osrm
