#include "swig_osrm.hpp"

#include <algorithm>
#include <functional>
#include <util/json_renderer.hpp>

//FIXME remove this when ready
#pragma GCC diagnostic ignored "-Wunused-parameter"

std::string ServiceHandler::Route(const RouteParameters &raw_params) {
    osrm::util::json::Object json;
    this->routing_machine.Route(ServiceHandler::translate(raw_params), json);
    return ServiceHandler::serialize(json);
}

std::string ServiceHandler::Table(const TableParameters &raw_params) {
    osrm::util::json::Object json;
    this->routing_machine.Table(ServiceHandler::translate(raw_params), json);
    return ServiceHandler::serialize(json);
}

std::string ServiceHandler::Nearest(const NearestParameters &raw_params) {
    osrm::util::json::Object json;
    this->routing_machine.Nearest(ServiceHandler::translate(raw_params), json);
    return ServiceHandler::serialize(json);
}

std::string ServiceHandler::Trip(const TripParameters &raw_params) {
    osrm::util::json::Object json;
    this->routing_machine.Trip(ServiceHandler::translate(raw_params), json);
    return ServiceHandler::serialize(json);}

std::string ServiceHandler::Match(const MatchParameters &raw_params) {
    osrm::util::json::Object json;
    this->routing_machine.Match(ServiceHandler::translate(raw_params), json);
    return ServiceHandler::serialize(json);
}

std::string ServiceHandler::Tile(const TileParameters &raw_params) {
    std::string result;
    this->routing_machine.Tile(ServiceHandler::translate(raw_params), result);
    return result;
}

osrm::engine::api::RouteParameters ServiceHandler::translate(const RouteParameters &raw) {
    osrm::RouteParameters params = osrm::engine::api::RouteParameters();

    params.alternatives = raw.alternatives;
    params.annotations = raw.annotations;
    params.annotations_type = osrm::engine::api::RouteParameters::AnnotationsType::All;
    params.geometries = raw.returnGeoJson ? osrm::engine::api::RouteParameters::GeometriesType::GeoJSON : osrm::engine::api::RouteParameters::GeometriesType::Polyline;
    params.steps = raw.steps;
    params.overview = raw.returnOverview ? osrm::engine::api::RouteParameters::OverviewType::Full : osrm::engine::api::RouteParameters::OverviewType::False;

    auto transformed_radiuses = std::vector<boost::optional<double>>(raw.radiuses.size());
    std::transform(raw.radiuses.begin(), raw.radiuses.end(), transformed_radiuses.begin(), ([] (Radius r) -> boost::optional<double>{
        return boost::optional<double>(r.radius);
    }));
    params.radiuses = std::move(transformed_radiuses);

    auto transformed_bearings = std::vector<boost::optional<osrm::engine::Bearing>>(raw.bearings.size());
    std::transform(raw.bearings.begin(), raw.bearings.end(), transformed_bearings.begin(), ([] (Bearing r) -> boost::optional<osrm::engine::Bearing>{
        return boost::optional<osrm::engine::Bearing>(osrm::engine::Bearing{(short)r.getValue(), (short)r.getRange()});
    }));
    params.bearings = std::move(transformed_bearings);

    auto transformed_coordinates = std::vector<osrm::util::Coordinate>(raw.coordinates.size());
    std::transform(raw.coordinates.begin(), raw.coordinates.end(), transformed_coordinates.begin(), ([] (Coordinate c) -> osrm::util::Coordinate{
        return osrm::util::Coordinate(osrm::FloatLongitude{c.getLon()}, osrm::FloatLatitude{c.getLat()});
    }));
    params.coordinates = std::move(transformed_coordinates);

    return params;
}

osrm::engine::api::TableParameters ServiceHandler::translate(const TableParameters &raw) {
    osrm::TableParameters params = osrm::engine::api::TableParameters();

    params.annotations = osrm::engine::api::TableParameters::AnnotationsType::All;

    auto transformed_radiuses = std::vector<boost::optional<double>>(raw.radiuses.size());
    std::transform(raw.radiuses.begin(), raw.radiuses.end(), transformed_radiuses.begin(), ([] (Radius r) -> boost::optional<double>{
        return boost::optional<double>(r.radius);
    }));
    params.radiuses = std::move(transformed_radiuses);

    auto transformed_bearings = std::vector<boost::optional<osrm::engine::Bearing>>(raw.bearings.size());
    std::transform(raw.bearings.begin(), raw.bearings.end(), transformed_bearings.begin(), ([] (Bearing r) -> boost::optional<osrm::engine::Bearing>{
        return boost::optional<osrm::engine::Bearing>(osrm::engine::Bearing{(short)r.getValue(), (short)r.getRange()});
    }));
    params.bearings = std::move(transformed_bearings);

    auto transformed_coordinates = std::vector<osrm::util::Coordinate>(raw.coordinates.size());
    std::transform(raw.coordinates.begin(), raw.coordinates.end(), transformed_coordinates.begin(), ([] (Coordinate c) -> osrm::util::Coordinate{
        return osrm::util::Coordinate(osrm::FloatLongitude{c.getLon()}, osrm::FloatLatitude{c.getLat()});
    }));
    params.coordinates = std::move(transformed_coordinates);

    params.scale_factor = raw.scaleFactor;

    params.sources = std::vector<std::size_t>(raw.sources);
    params.destinations = std::vector<std::size_t>(raw.destinations);

    return params;
}

osrm::engine::api::NearestParameters ServiceHandler::translate(const NearestParameters &raw) {
    osrm::NearestParameters params = osrm::engine::api::NearestParameters();

    auto transformed_radiuses = std::vector<boost::optional<double>>(raw.radiuses.size());
    std::transform(raw.radiuses.begin(), raw.radiuses.end(), transformed_radiuses.begin(), ([] (Radius r) -> boost::optional<double>{
        return boost::optional<double>(r.radius);
    }));
    params.radiuses = std::move(transformed_radiuses);

    auto transformed_bearings = std::vector<boost::optional<osrm::engine::Bearing>>(raw.bearings.size());
    std::transform(raw.bearings.begin(), raw.bearings.end(), transformed_bearings.begin(), ([] (Bearing r) -> boost::optional<osrm::engine::Bearing>{
        return boost::optional<osrm::engine::Bearing>(osrm::engine::Bearing{(short)r.getValue(), (short)r.getRange()});
    }));
    params.bearings = std::move(transformed_bearings);

    auto transformed_coordinates = std::vector<osrm::util::Coordinate>(raw.coordinates.size());
    std::transform(raw.coordinates.begin(), raw.coordinates.end(), transformed_coordinates.begin(), ([] (Coordinate c) -> osrm::util::Coordinate{
        return osrm::util::Coordinate(osrm::FloatLongitude{c.getLon()}, osrm::FloatLatitude{c.getLat()});
    }));
    params.coordinates = std::move(transformed_coordinates);

    params.number_of_results = raw.num_of_results;

    return params;
}

osrm::engine::api::TripParameters ServiceHandler::translate(const TripParameters &raw) {
    osrm::TripParameters params = osrm::engine::api::TripParameters();

    params.annotations = raw.annotations;
    params.geometries = raw.returnGeoJson ? osrm::engine::api::RouteParameters::GeometriesType::GeoJSON : osrm::engine::api::RouteParameters::GeometriesType::Polyline;
    params.steps = raw.steps;
    params.overview = raw.returnOverview ? osrm::engine::api::RouteParameters::OverviewType::Full : osrm::engine::api::RouteParameters::OverviewType::False;

    auto transformed_radiuses = std::vector<boost::optional<double>>(raw.radiuses.size());
    std::transform(raw.radiuses.begin(), raw.radiuses.end(), transformed_radiuses.begin(), ([] (Radius r) -> boost::optional<double>{
        return boost::optional<double>(r.radius);
    }));
    params.radiuses = std::move(transformed_radiuses);

    auto transformed_bearings = std::vector<boost::optional<osrm::engine::Bearing>>(raw.bearings.size());
    std::transform(raw.bearings.begin(), raw.bearings.end(), transformed_bearings.begin(), ([] (Bearing r) -> boost::optional<osrm::engine::Bearing>{
        return boost::optional<osrm::engine::Bearing>(osrm::engine::Bearing{(short)r.getValue(), (short)r.getRange()});
    }));
    params.bearings = std::move(transformed_bearings);

    auto transformed_coordinates = std::vector<osrm::util::Coordinate>(raw.coordinates.size());
    std::transform(raw.coordinates.begin(), raw.coordinates.end(), transformed_coordinates.begin(), ([] (Coordinate c) -> osrm::util::Coordinate{
        return osrm::util::Coordinate(osrm::FloatLongitude{c.getLon()}, osrm::FloatLatitude{c.getLat()});
    }));
    params.coordinates = std::move(transformed_coordinates);

    return params;
}

osrm::engine::api::MatchParameters ServiceHandler::translate(const MatchParameters &raw) {
    osrm::MatchParameters params = osrm::engine::api::MatchParameters();

    params.annotations = raw.annotations;
    params.geometries = raw.returnGeoJson ? osrm::engine::api::RouteParameters::GeometriesType::GeoJSON : osrm::engine::api::RouteParameters::GeometriesType::Polyline;
    params.steps = raw.steps;
    params.overview = raw.returnOverview ? osrm::engine::api::RouteParameters::OverviewType::Full : osrm::engine::api::RouteParameters::OverviewType::False;
    params.gaps = raw.gaps ? osrm::engine::api::MatchParameters::GapsType::Split : osrm::engine::api::MatchParameters::GapsType::Ignore;
    params.tidy = raw.tidy;


    auto transformed_radiuses = std::vector<boost::optional<double>>(raw.radiuses.size());
    std::transform(raw.radiuses.begin(), raw.radiuses.end(), transformed_radiuses.begin(), ([] (Radius r) -> boost::optional<double>{
        return boost::optional<double>(r.radius);
    }));
    params.radiuses = std::move(transformed_radiuses);

    auto transformed_bearings = std::vector<boost::optional<osrm::engine::Bearing>>(raw.bearings.size());
    std::transform(raw.bearings.begin(), raw.bearings.end(), transformed_bearings.begin(), ([] (Bearing r) -> boost::optional<osrm::engine::Bearing>{
        return boost::optional<osrm::engine::Bearing>(osrm::engine::Bearing{(short)r.getValue(), (short)r.getRange()});
    }));
    params.bearings = std::move(transformed_bearings);

    auto transformed_coordinates = std::vector<osrm::util::Coordinate>(raw.coordinates.size());
    std::transform(raw.coordinates.begin(), raw.coordinates.end(), transformed_coordinates.begin(), ([] (Coordinate c) -> osrm::util::Coordinate{
        return osrm::util::Coordinate(osrm::FloatLongitude{c.getLon()}, osrm::FloatLatitude{c.getLat()});
    }));
    params.coordinates = std::move(transformed_coordinates);

    auto transformed_timestamps = std::vector<unsigned>(raw.timestamps.size());
    std::transform(raw.timestamps.begin(), raw.timestamps.end(), transformed_timestamps.begin(), ([] (long ts) -> unsigned{
        return ts;
    }));
    params.timestamps = std::move(transformed_timestamps);

    return params;
}

osrm::engine::api::TileParameters ServiceHandler::translate(const TileParameters &raw) {
    //TODO implement it
    return osrm::engine::api::TileParameters();
}

std::string ServiceHandler::serialize(const osrm::util::json::Object &json) {
    std::ostringstream os;
    osrm::util::json::render(os, json);
    return os.str();
}

osrm::engine::EngineConfig ServiceHandler::translate(const EngineConfig &raw) {
    auto cfg = osrm::engine::EngineConfig {};
    cfg.storage_config = osrm::storage::StorageConfig(boost::filesystem::path(raw.base_path));
    cfg.max_locations_trip = raw.max_locations_trip;
    cfg.max_locations_viaroute = raw.max_locations_viaroute;
    cfg.max_locations_distance_table = raw.max_locations_distance_table;
    cfg.max_locations_map_matching = raw.max_locations_map_matching;
    cfg.max_radius_map_matching = raw.max_radius_map_matching;
    cfg.max_results_nearest = raw.max_results_nearest;
    cfg.max_alternatives = raw.max_alternatives;
    cfg.use_shared_memory = false;
    cfg.use_mmap = raw.use_mmap;
    cfg.algorithm = raw.use_mld ? osrm::engine::EngineConfig::Algorithm::MLD : osrm::engine::EngineConfig::Algorithm::CH;
    cfg.verbosity = raw.verbosity;
    cfg.dataset_name = raw.dataset_name;
    return cfg;
}
