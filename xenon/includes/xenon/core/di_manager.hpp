#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>

class DIManager {
public:

    template <typename TService>
    std::shared_ptr<TService> AddSingleton(std::function<std::shared_ptr<TService>()> factory) {
        auto type = std::type_index(typeid(TService));
        if (singletons.find(type) != singletons.end()) {
            throw std::runtime_error("Service already registered as Singleton.");
        }
        auto instance = factory();
        singletons[type] = instance;

        return instance;
    }

    template <typename TService, typename TImplementation>
    std::shared_ptr<TService> AddSingleton() {
        return AddSingleton<TService>([]() {
            return std::make_shared<TImplementation>();
        });
    }

    template <typename TService>
    std::shared_ptr<TService> AddSingleton() {
        return AddSingleton<TService>([]() {
            return std::make_shared<TService>();
        });
    }
    
    template <typename TService>
    std::shared_ptr<TService> AddTransient(std::function<std::shared_ptr<TService>()> factory) {
        auto type = std::type_index(typeid(TService));
        if (transients.find(type) != transients.end()) {
            throw std::runtime_error("Service already registered as Transient.");
        }
        transients[type] = factory;

        return factory;
    }

    template <typename TService, typename TImplementation>
    std::shared_ptr<TService> AddTransient() {
        return AddTransient<TService>([]() {
            return std::make_shared<TImplementation>();
        });
    }

    template <typename TService>
    std::shared_ptr<TService> GetService() {
        auto type = std::type_index(typeid(TService));
        if (singletons.find(type) != singletons.end()) {
            return std::static_pointer_cast<TService>(singletons[type]);
        }
        if (transients.find(type) != transients.end()) {
            return std::static_pointer_cast<TService>(transients[type]());
        }
        throw std::runtime_error("Service not registered.");
    }

    template <typename TConfiguration>
    std::shared_ptr<TConfiguration> AddConfiguration() {
        auto type = std::type_index(typeid(TConfiguration));
        if (configurations.find(type) != configurations.end()) {
            throw std::runtime_error("Configuration already registered.");
        }
        auto instance = std::make_shared<TConfiguration>();
        configurations[type] = instance;
        return instance;
    }

    template <typename TConfiguration>
    std::shared_ptr<TConfiguration> GetConfiguration() {
        auto type = std::type_index(typeid(TConfiguration));
        if (configurations.find(type) != configurations.end()) {
            return std::static_pointer_cast<TConfiguration>(configurations[type]);
        }
        throw std::runtime_error("Configuration not registered.");
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> singletons;
    std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> transients;
    std::unordered_map<std::type_index, std::shared_ptr<void>> configurations;
};
