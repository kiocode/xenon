---

kanban-plugin: board

---

## Brainstorming

- [x] Mi immagino che metteremo tipo core.IsUnityGame() che darà errore se prima non hai detto core.IsInternalCheat() e dobbiamo fare un enum per unity game con due cose, enum UnityGames { IL2CPP, MONO }; e lo passiamo alla funzione con core.IsUnityGame(UnityGames.IL2CPP)Poi sempre se è un internal game puoi fare tipo UseConsole() e compare la console, ma stavo pensando, forse dovrei fare quello che dicevo, tipo che lascio builder e poi alla fine faccio BuildInternal() oppure BuildExternal() e mi ritorna due oggetti diversi, che hanno variabili diverse, tipo IsUnityGame() e cazzi e mazzi lo posso fare solo sull'oggetto InternalCheat ritornato da BuildInternal, mhhhh


## Todo

- [ ] Add Lua support
- [ ] Add Waypoints support
- [ ] Organize src content like includes
- [ ] Add on github an activity check for building and formatting


## InProgress



## Done

- [x] Organizzare i metodi dentro aimbot.cpp tra #region per raggruppare prima i metodi pubblici #region Public Methods e poi sotto #region Private Methods




%% kanban:settings
```
{"kanban-plugin":"board","list-collapse":[false,false,false,false],"show-checkboxes":true,"table-sizing":{"card":217}}
```
%%