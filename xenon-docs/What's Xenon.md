*Xenon is a framework, created to make cheat development easier and faster.*

With Xenon you can already have all the features of a good cheat, without having to write almost anything. 
It is a framework, designed to have a library of common features that can be useful for any game.

An example? 
 1. Aimbot; 
 2. Automatic Radar; 
 3. Player health bar;
 4. Wallhack. 

 *All enclosed in Xenon*.

The project also contains examples of games we used to develop, logic and features of Xenon. 
They are all free to play games, with little memory space and light, suitable for everyone.

Take the solution 'example-oar-internal', which stands for the game 'One Armed Robber', inside we can find all its dumpers and the ddlmain project, which is responsible for starting the cheats in the xenon library:
``` cpp
DWORD WINAPI MainThread(LPVOID lpReserved)
{
	/* Codes */
	Cheat cheat = builder.Build();
	cheat.UseUICustom(RenderingHookType::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIRadar();
	cheat.UseUIRenderMouse();
	cheat.UseESPSnapline();
	cheat.UseESPBox2D();
	cheat.UseESPHealthBar();
	cheat.UseUIRenderOverlays();
	cheat.UseUIQuickActions();
	cheat.UseAimbot();

	cheat.Run();
	
	return TRUE;
}
```
*You can also create your own graphics to use, to create your own cheats.*
