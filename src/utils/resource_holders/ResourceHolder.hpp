//
// Created by zaha on 5/16/23.
//

#ifndef PACMAN_RESOURCEHOLDER_HPP
#define PACMAN_RESOURCEHOLDER_HPP


#include <map>
#include <memory>
#include "../exceptions/FileNotFound.hpp"


template<typename Resource, typename Identifier>
class ResourceHolder {
protected:
    std::map<Identifier, std::unique_ptr<Resource>> resources;

public:
    ResourceHolder() = default;

    ResourceHolder(const ResourceHolder &other) = delete;

    ResourceHolder &operator=(const ResourceHolder &other) = delete;

    virtual ~ResourceHolder() = default;

    virtual void load(Identifier id, const std::string &path) {
        std::unique_ptr<Resource> resource = std::make_unique<Resource>();
        if (!resource->loadFromFile(path)) {
            throw FileNotFound("Resource not found at: " + path);
        }
        resources.insert(std::make_pair(id, std::move(resource)));
    }

    Resource &get(Identifier id) {
        return *resources.at(id);
    }

    const Resource &get(Identifier id) const {
        return *resources.at(id);
    }
};


#endif //PACMAN_RESOURCEHOLDER_HPP
