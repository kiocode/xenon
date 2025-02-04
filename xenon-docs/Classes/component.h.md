### Purpose
CComponent  `CComponent` is the base class for all components in the Xenon framework, including features and services. It provides a common interface and access to core framework elements such as configuration, variables, and the main Xenon instance.  

### Key Members
#### `std::shared_ptr<Xenon> g_pXenon;`

A shared pointer to the main `Xenon` instance, giving access to the core framework functionalities.

#### `std::shared_ptr<XenonVariables> g_pXenonVariables;`

A shared pointer to `XenonVariables`, which stores and manages runtime variables used across components.

#### `std::shared_ptr<XenonConfig> g_pXenonConfigs;`

A shared pointer to `XenonConfig`, which provides configuration management for components.

### Virtual Methods

#### `virtual void Init();`

This method is meant to be overridden in derived components to initialize necessary resources.

#### `virtual void Update();`

Called periodically to update the component state.

#### `virtual void UpdateCurrentTarget(TargetProfile* target);`

Allows components to modify behavior based on a specific target profile.

#### `virtual ~CComponent();`

A virtual destructor to ensure proper cleanup when a derived component is destroyed.

## Usage Example

To create a new component, simply inherit from `CComponent` and override the necessary methods:

```cpp
class CAimbot : public CComponent { 
public:     
	void Init() override {         
		spdlog::info("Aimbot initialized!");     
	}      
	
	void Update() override {         
		// Aimbot logic here     
	}     
	
	void UpdateCurrentTarget(TargetProfile* target) override {         
		// Process the target     
	} 
};
```

By inheriting from `CComponent`, all new components automatically integrate into the Xenon framework, gaining access to its core features and utilities.