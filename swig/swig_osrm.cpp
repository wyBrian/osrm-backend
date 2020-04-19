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

osrm::engine::api::RouteParameters ServiceHandler::translate(const RouteParameters &raw) {
    return osrm::engine::api::RouteParameters();
}

osrm::engine::api::TableParameters ServiceHandler::translate(const TableParameters &raw) {
    return osrm::engine::api::TableParameters();
}

osrm::engine::api::NearestParameters ServiceHandler::translate(const NearestParameters &raw) {
    return osrm::engine::api::NearestParameters();
}

osrm::engine::api::TripParameters ServiceHandler::translate(const TripParameters &raw) {
    return osrm::engine::api::TripParameters();
}

osrm::engine::api::MatchParameters ServiceHandler::translate(const MatchParameters &raw) {
    return osrm::engine::api::MatchParameters();
}

osrm::engine::api::TileParameters ServiceHandler::translate(const TileParameters &raw) {
    return osrm::engine::api::TileParameters();
}

void ServiceHandler::serialize(const osrm::util::json::Object &json, std::string &txt) {
    //TODO implement it
    txt = "";
}
