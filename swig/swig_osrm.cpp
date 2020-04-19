#include "swig_osrm.hpp"

namespace swig {
    osrm::engine::Status ServiceHandler::Route(const swig::RouteParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Route(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Table(const swig::MatchParameters raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res =  this->routing_machine.Table(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Nearest(const swig::NearestParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res =  this->routing_machine.Table(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Trip(const swig::TripParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res =  this->routing_machine.Table(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Match(const swig::MatchParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res =  this->routing_machine.Table(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Tile(const swig::TileParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res =  this->routing_machine.Table(&this->translate(raw_params), &json);
        this->serialize(json, result);
        return res;
    }

    swig::RouteParameters ServiceHandler::translate(const swig::RouteParameters &raw) {
        return RouteParameters();
    }

    swig::TableParameters ServiceHandler::translate(const swig::TableParameters &raw) {
        return TableParameters();
    }

    swig::NearestParameters ServiceHandler::translate(const swig::NearestParameters &raw) {
        return NearestParameters();
    }

    swig::TripParameters ServiceHandler::translate(const swig::TripParameters &raw) {
        return TripParameters();
    }

    swig::MatchParameters ServiceHandler::translate(const swig::MatchParameters &raw) {
        return MatchParameters();
    }

    swig::TileParameters ServiceHandler::translate(const swig::TileParameters &raw) {
        return TileParameters();
    }

    void ServiceHandler::serialize(osrm::json::Object &json, std::string &txt) {
        //TODO implement it
    }
}