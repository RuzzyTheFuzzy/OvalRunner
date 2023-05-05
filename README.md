# OvalRunner
Endless runner but fps

WASD and mouse to move around. I aint got any menus, so just alt+f4 to quit.

The obsticles class was designed with Blueprints in mind for variations in the obstacles.
The spawner accepts any blueprint that inherets from the obsticles class, so you can spawn different obstacles with varying speed, and rarity.

The obstacle spawners have an array of obstacle pointers that can be reused. This way instead of destroying the obstacles, they simply get hidden and have a pointer to the array so they can add themselves to the reuse pile.

The bullets and obstacles use the same Move Component so that the linear movement code can be reused.

The menu and score text use blueprints because C++ felt overkill for such a simple thing.
