#include "swig_osrm.hpp"

//FIXME remove this when ready
#pragma GCC diagnostic ignored "-Wunused-parameter"

osrm::engine::Status ServiceHandler::Route(const RouteParameters &raw_params, std::string &result) {
    osrm::util::json::Object json;
    auto res = this->routing_machine.Route(this->translate(raw_params), json);
    this->serialize(json, result);
    return res;
}

osrm::engine::Status ServiceHandler::Table(const TableParameters &raw_params, std::string &result) {
    osrm::util::json::Object json;
    auto res = this->routing_machine.Table(this->translate(raw_params), json);
    this->serialize(json, result);
    return res;
}

osrm::engine::Status ServiceHandler::Nearest(const NearestParameters &raw_params, std::string &result) {
    osrm::util::json::Object json;
    auto res = this->routing_machine.Nearest(this->translate(raw_params), json);
    this->serialize(json, result);
    return res;
}

osrm::engine::Status ServiceHandler::Trip(const TripParameters &raw_params, std::string &result) {
    osrm::util::json::Object json;
    auto res = this->routing_machine.Trip(this->translate(raw_params), json);
    this->serialize(json, result);
    return res;
}

osrm::engine::Status ServiceHandler::Match(const MatchParameters &raw_params, std::string &result) {
    osrm::util::json::Object json;
    auto res = this->routing_machine.Match(this->translate(raw_params), json);
    this->serialize(json, result);
    return res;
}

osrm::engine::Status ServiceHandler::Tile(const TileParameters &raw_params, std::string &result) {
    return this->routing_machine.Tile(this->translate(raw_params), result);
}

static osrm::engine::api::RouteParameters ServiceHandler::translate(const RouteParameters &raw) {
    //TODO implement it
    return osrm::engine::api::RouteParameters();
}

static osrm::engine::api::TableParameters ServiceHandler::translate(const TableParameters &raw) {
    //TODO implement it
    return osrm::engine::api::TableParameters();
}

static osrm::engine::api::NearestParameters ServiceHandler::translate(const NearestParameters &raw) {
    //TODO implement it
    return osrm::engine::api::NearestParameters();
}

static osrm::engine::api::TripParameters ServiceHandler::translate(const TripParameters &raw) {
    //TODO implement it
    return osrm::engine::api::TripParameters();
}

static osrm::engine::api::MatchParameters ServiceHandler::translate(const MatchParameters &raw) {
    //TODO implement it
    return osrm::engine::api::MatchParameters();
}

static osrm::engine::api::TileParameters ServiceHandler::translate(const TileParameters &raw) {
    //TODO implement it
    return osrm::engine::api::TileParameters();
}

static void ServiceHandler::serialize(const osrm::util::json::Object &json, std::string &txt) {
    //TODO implement it
    txt = "";
}
