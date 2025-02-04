### Purpose
`CEsp` class is responsible for rendering various ESP (Extra Sensory Perception) features like boxes, snaplines, skeletons, and health bars around targets.

### Methods

#### `void RenderSnapline() const;`
Renders a snapline connecting the player to the target.

#### `void Render2DBox() const;`
Renders a 2D bounding box around a target.

#### `void Render3DBox() const;`
Renders a 3D bounding box around a target.

#### `void RenderSkeleton() const;`
Renders the skeleton of a target.

#### `void RenderHealthBar() const;`
Renders a health bar above the target.

#### `void Update() override;`
Updates the ESP features for the current frame.