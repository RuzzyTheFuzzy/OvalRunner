# OvalRunner
Endless runner but fps

WASD and mouse to move around. Left click to shoot.

The obstacles are spawned via an actor class called obsticlespawner. It uses a TArray of TObjectPtrs so that instead of constantly spawning new obstacles i can simply reuse them and optimize the performance.
The spawner checks the distance eatch obstacle is away from it and adds them to the reuse TArray incase they are a proper distance away. Checking this in the obstacle spawner class lowers the amount of tick actors and avoids circular dependence.

The obstacles themselves are an actor class that contain a movement component and staticmesh component. This was so that i could create blueprints inhereting this class and easily add variety to the obstacles spawned from the obstacle spawner.

The movement component is a really simple component that just moves its parent actor a certain distance acording to its FVector eatch tick. It was made so that linear movement could easily be added to actors.

The Run Character class inherets the base unreal character class for easy collision detection, camera and movement controls.

The Gamemode handles score and the players lives, as it is easily accessable from anywhere in the code. The player lives use an unsigned 8 bit intiger for space efficency.

# Changes

Fixed Access violation caused by obstacles being destroyed while still being pointed to by the spawners reuse array. Made enemy obstacle not destroy itself, instead just teleporting so that it gets reused and hidden uppon hit. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/86fbd53d7f865841ca9cc35cf3d5f652b52b6e1f)

Fixed Access violation caused by SaveScore TObjectPtr being garbage collected while still being referenced in gamemode. Added UPROPERTY to TObjectPtr so that GC wont collect it early. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/86fbd53d7f865841ca9cc35cf3d5f652b52b6e1f#diff-30dc5f09f36b33acb391fbcb166218318c4f695194eda140f946ddf9af22ac5c)

Changed obstacle reuse system so that the spawner handles it all to avoid circular dependensies and lots of pointers back and forth. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/86fbd53d7f865841ca9cc35cf3d5f652b52b6e1f)

- Removed bar obstacles as they caused lots of issues from being able to land on them. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/574804faa8e107215d1a034638babf537924cfaf)

+ Added lives ui. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/e416018111b76e2fd64cc895a93f1d49826b2001)
+ Made score ui yellow to make it easier to see. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/e416018111b76e2fd64cc895a93f1d49826b2001)
+ Moved camera upwards and increased the FOV for increased vision. [Commit](https://github.com/RuzzyTheFuzzy/OvalRunner/commit/c1ac4f9ef2e10c97171748324d28a0371ff70b16)
