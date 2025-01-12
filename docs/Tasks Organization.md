---

kanban-plugin: board

---

## Brainstorming



## Todo

- [ ] Add on github an activity check for building and formatting
- [ ] dll loader
- [ ] packet sniffer + parser
- [ ] implement il2cppresolver
- [ ] write down some Lua binding c++
- [ ] check configs naming convetions
- [ ] in update if attached a game check if its opened
- [ ] understand if toggle menu visiblity key is for game config or ui config
- [ ] merge track mouse with the system get mouse fn
- [ ] move all "use" var in a cheatconfig that will be share by any service
- [ ] add ui right top show enabled features like minecraft clients
- [ ] change all, don't have a single update but have a list with all features and services called now components that have a super clas with onupdate synchronized with the original update
- [ ] add esp and aimbot support for visible/not players behind walls
- [ ] check if the use of pointer makes sense like with vec2
- [ ] add NONE to enums


## InProgress

- [ ] customize GUI
- [ ] add health bar


## Done

- [x] Organize the methods inside `aimbot.cpp` using `#region` to group them, starting with public methods under `#region Public Methods`, followed by private methods under `#region Private Methods`.
- [x] External cheat gui
- [x] add more universal data, maybe a player profile with health and name and distance from the localplayer
- [x] get nearest maybe generalize the 3d thing
- [x] Add Waypoints support
- [x] spinbot 2d/3d
- [x] implement IsUnityGame(type)/IsUnrealGame(version)
- [x] make tests for Lua
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