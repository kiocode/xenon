#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>

#include <xenon/core/xenon_core.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/core/xenon_config.hpp>

/**
 * @class CComponent
 * @brief A base class for components in the Xenon system.
 *
 * This class provides a basic interface for all components that interact with the Xenon core,
 * Xenon variables, and Xenon configuration systems. Derived classes should implement the
 * `Init()`, `Update()`, and `UpdateCurrentTarget()` methods to define specific behavior.
 */
class CComponent {
public:
    /**
     * @brief Shared pointer to the Xenon core instance.
     */
    std::shared_ptr<Xenon> g_pXenon;

    /**
     * @brief Shared pointer to the Xenon variables instance.
     */
    std::shared_ptr<XenonVariables> g_pXenonVariables;

    /**
     * @brief Shared pointer to the Xenon configuration instance.
     */
    std::shared_ptr<XenonConfig> g_pXenonConfigs;

    /**
     * @brief Virtual method to initialize the component.
     *
     * This method should be overridden by derived classes to perform any initialization tasks
     * required by the component.
     */
    virtual void Init() {}

    /**
     * @brief Virtual method to update the component.
     *
     * This method should be overridden by derived classes to update the component's state.
     */
    virtual void Update() {}

    /**
     * @brief Virtual method to update the current target.
     *
     * @param target A pointer to the target profile that is being updated.
     *
     * This method should be overridden by derived classes to update the target profile based on
     * the current state of the component.
     */
    virtual void UpdateCurrentTarget(TargetProfile* target) {}

    /**
     * @brief Destructor for the CComponent class.
     *
     * This destructor is virtual, allowing for proper cleanup of derived class objects.
     */
    virtual ~CComponent() = default;
};
