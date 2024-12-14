#include <functional>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>

class DiManager {
public:
    template <typename TService>
    void AddSingleton(std::function<std::shared_ptr<TService>()> factory) {
        auto type = std::type_index(typeid(TService));
        if (services.find(type) != services.end()) {
            throw std::runtime_error("Service already registered.");
        }
        services[type] = [factory]() { return factory(); };
    }

    template <typename TService, typename TImplementation>
    void AddSingleton() {
        AddSingleton<TService>([this]() {
            return CreateInstance<TImplementation>();
            });
    }

    template <typename TService>
    std::shared_ptr<TService> GetService() {
        auto type = std::type_index(typeid(TService));
        if (services.find(type) == services.end()) {
            throw std::runtime_error("Service not registered.");
        }
        return std::static_pointer_cast<TService>(services[type]());
    }

    template <typename TService>
    std::shared_ptr<TService> CreateInstance() {
        if constexpr (std::is_constructible_v<TService>) {
            return std::make_shared<TService>();
        }
        else {
            return ConstructWithDependencies<TService>();
        }
    }

private:
    std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> services;

    template <typename TService, typename... TDependencies>
    std::shared_ptr<TService> ConstructWithDependencies() {
        using ConstructorArgs = ConstructorParameters<TService>;
        return std::apply([this](auto&&... args) {
            return std::make_shared<TService>(GetService<std::decay_t<decltype(args)>>()...);
            }, ConstructorArgs{});
    }

    template <typename T>
    struct ConstructorParameters;

    template <typename T, typename... Args>
    struct ConstructorParameters<T(Args...)> {
        using type = std::tuple<Args...>;
    };

    template <typename T>
    using ConstructorParameters = typename ConstructorParameters<decltype(&T::T)>::type;
};