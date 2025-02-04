### Purpose
`CAimbot` provides functionality for automatic aiming at targets. It includes methods for setting targets, checking if the target is reached, and even incorporating prediction for moving targets.

### Key Members
#### `Vec2 m_vTarget;`
Stores the position of the current target.

#### `float nearestDistance = 0;`
Specifies the nearest distance threshold for the aimbot to target.

### Methods

#### `void Init();`
Initializes the aimbot, setting configuration values like `nearestDistance`.

#### `bool IsTargetEmpty() const;`
Checks if a target has been assigned to the aimbot.

#### `void SetTarget(Vec2& pos);`
Sets the target position for the aimbot.

#### `bool IsTargetReached() const;`
Returns `true` if the aimbot has reached the target.

#### `void ResetTarget();`
Resets the current target.

#### `void AimTarget();`
Aims at the current target without prediction.

#### `void AimTargetWithPrediction(Vec2& vel);`
Aims at the current target with prediction, based on the target's velocity.

#### `void UpdateCurrentTarget(TargetProfile* target) override;`
Updates the current target based on the provided target profile.


---

### Game Class

### Purpose
The `Game` class handles the game loop and interaction between Xenon components. It allows for event handling, component management, and game-specific logic.

### Key Members
#### `std::unordered_map<std::string, std::vector<std::function<void()>>> updateCallbacks;`
Stores callbacks for general events.

#### `std::unordered_map<std::string, std::vector<std::function<void(TargetProfile* target)>>> updateCurrentTargetCallbacks;`
Stores callbacks for events that need to be triggered with a `TargetProfile`.

#### `std::shared_ptr<Xenon> m_pXenon;`
A shared pointer to the main `Xenon` instance.

#### `std::shared_ptr<XenonConfig> m_pXenonConfigs;`
A shared pointer to the configuration object.

#### `std::shared_ptr<XenonVariables> m_pXenonVariables;`
A shared pointer to the variables used across components.

#### `std::vector<std::shared_ptr<CComponent>> m_pComponents;`
A vector storing all the components (features and services) used in the game.

### Methods

#### `void EnableUpdate();`
Enables the update function to run periodically.

#### `void OnEvent(const std::string& eventName, const std::function<void()>& callback);`
Registers a callback for a specific event.

#### `void TriggerEvent(const std::string& eventName);`
Triggers the registered callback(s) for an event.

#### `void OnEvent(const std::string& eventName, const std::function<void(TargetProfile* target)>& callback);`
Registers a callback for events related to `TargetProfile` objects.

#### `void TriggerEvent(const std::string& eventName, TargetProfile* target);`
Triggers the callback(s) for events with a specific `TargetProfile`.

#### `void ClearEvent(const std::string& eventName);`
Clears any registered events and their callbacks.

---

### Radar Class

### Purpose
`Radar` provides the ability to render and display a radar in the game, showing the position of targets.

### Methods

#### `void Render();`
R
