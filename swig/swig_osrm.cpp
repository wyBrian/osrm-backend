#include "swig_osrm.hpp"

//FIXME remove this when ready
#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace swig {
    osrm::engine::Status ServiceHandler::Route(const swig::RouteParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Route(this->translate(raw_params), json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Table(const swig::TableParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Table(this->translate(raw_params), json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Nearest(const swig::NearestParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Nearest(this->translate(raw_params), json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Trip(const swig::TripParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Trip(this->translate(raw_params), json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Match(const swig::MatchParameters &raw_params, std::string &result) {
        osrm::util::json::Object json;
        auto res = this->routing_machine.Match(this->translate(raw_params), json);
        this->serialize(json, result);
        return res;
    }

    osrm::engine::Status ServiceHandler::Tile(const swig::TileParameters &raw_params, std::string &result) {
        return this->routing_machine.Tile(this->translate(raw_params), result);
    }

    osrm::engine::api::RouteParameters ServiceHandler::translate(const swig::RouteParameters &raw) {
        return osrm::engine::api::RouteParameters();
    }

    osrm::engine::api::TableParameters ServiceHandler::translate(const swig::TableParameters &raw) {
        return osrm::engine::api::TableParameters();
    }

    osrm::engine::api::NearestParameters ServiceHandler::translate(const swig::NearestParameters &raw) {
        return osrm::engine::api::NearestParameters();
    }

    osrm::engine::api::TripParameters ServiceHandler::translate(const swig::TripParameters &raw) {
        return osrm::engine::api::TripParameters();
    }

    osrm::engine::api::MatchParameters ServiceHandler::translate(const swig::MatchParameters &raw) {
        return osrm::engine::api::MatchParameters();
    }

    osrm::engine::api::TileParameters ServiceHandler::translate(const swig::TileParameters &raw) {
        return osrm::engine::api::TileParameters();
    }

    void ServiceHandler::serialize(const osrm::util::json::Object &json, std::string &txt) {
        //TODO implement it
        txt = "";
    }
}
