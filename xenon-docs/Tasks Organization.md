---

kanban-plugin: board

---

## Brainstorming

- [ ] add esp and aimbot support for visible/not players behind walls
- [ ] Add on github an activity check for building and formatting


## Todo

- [ ] dll loader
- [ ] packet sniffer + parser
- [ ] implement il2cppresolver
- [ ] write down some Lua binding c++
- [ ] check configs naming convetions
- [ ] in update if attached a game check if its opened
- [ ] understand if toggle menu visiblity key is for game config or ui config
- [ ] merge track mouse with the system get mouse fn
- [ ] add ui right top show enabled features like minecraft clients
- [ ] check if the use of pointer makes sense like with vec2
- [ ] check is use enums with plural or singular name
- [ ] add fly
- [ ] system and gamesvariable needs rename


## InProgress

- [ ] customize GUI
- [ ] move all "use" var in a cheatconfig that will be share by any service
- [ ] change all, don't have a single update but have a list with all features and services called now components that have a super clas with onupdate synchronized with the original update


## Done

- [x] Organize the methods inside `aimbot.cpp` using `#region` to group them, starting with public methods under `#region Public Methods`, followed by private methods under `#region Private Methods`.
- [x] add health bar
- [x] External cheat gui
- [x] create a single centralized object accessible from any object that have access to any component
- [x] add more universal data, maybe a player profile with health and name and distance from the localplayer
- [x] get nearest maybe generalize the 3d thing
- [x] Add Waypoints support
- [x] spinbot 2d/3d
- [x] implement IsUnityGame(type)/IsUnrealGame(version)
- [x] make tests for Lua
- [x] add NONE to enums
- [x] convert all vec in float
- [x] delete GetModuleAddress (make overload but use it privately) ADD READPOINTER/READVALUE USE AUTOMATICALLY THE GETMODULE - SetModuleAddress
- [x] make tests for radar
- [x] centralize renderui in another file
- [x] esp snapline
- [x] esp skeleton
- [x] esp box2d/3d
- [x] implement radar function
- [x] create a public services pool
- [x] Add Lua support
- [x] generalize events in base
- [x] Organize src content like includes
- [x] move hkpresent in another clas




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false,false],"show-checkboxes":true,"table-sizing":{"card":217}}
```
%%