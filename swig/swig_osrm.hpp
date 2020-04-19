#ifndef OSRM_SWIG_OSRM_HPP
#define OSRM_SWIG_OSRM_HPP

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

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/any.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include <csignal>
#include <cstdlib>

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <memory>
#include <new>
#include <string>

class ServiceHandlerInterface
{
public:
    virtual ~ServiceHandlerInterface() = default;
    virtual osrm::engine::Status Route(const osrm::engine::api::RouteParameters &params, osrm::util::json::Object &result) = 0;
    virtual osrm::engine::Status Table(const osrm::engine::api::TableParameters &params, osrm::util::json::Object &result) = 0;
    virtual osrm::engine::Status Nearest(const osrm::engine::api::NearestParameters &params, osrm::util::json::Object &result) = 0;
    virtual osrm::engine::Status Trip(const osrm::engine::api::TripParameters &params, osrm::util::json::Object &result) = 0;
    virtual osrm::engine::Status Match(const osrm::engine::api::MatchParameters &params, osrm::util::json::Object &result) = 0;
    virtual osrm::engine::Status Tile(const osrm::engine::api::TileParameters &params, std::string &result) = 0;
};

class ServiceHandler final : public ServiceHandlerInterface
{
public:
    explicit ServiceHandler(osrm::EngineConfig &config) : routing_machine(config) {
    }

    ~ServiceHandler() override {
    }

    osrm::engine::Status Route(const osrm::engine::api::RouteParameters &params, osrm::util::json::Object &result) override {
        return this->routing_machine.Route(params, result);
    }

    osrm::engine::Status Table(const osrm::engine::api::TableParameters &params, osrm::util::json::Object &result) override {
        return this->routing_machine.Table(params, result);
    }

    osrm::engine::Status Nearest(const osrm::engine::api::NearestParameters &params, osrm::util::json::Object &result) override {
        return this->routing_machine.Nearest(params, result);
    }

    osrm::engine::Status Trip(const osrm::engine::api::TripParameters &params, osrm::util::json::Object &result) override {
        return this->routing_machine.Trip(params, result);
    }

    osrm::engine::Status Match(const osrm::engine::api::MatchParameters &params, osrm::util::json::Object &result) override {
        return this->routing_machine.Match(params, result);
    }

    osrm::engine::Status Tile(const osrm::engine::api::TileParameters &params, std::string &result) override {
        return this->routing_machine.Tile(params, result);
    }

private:
    osrm::OSRM routing_machine;
};


#endif //OSRM_SWIG_OSRM_HPP
