// 14-12-2019
// 
// CURRENTLY WORKING ON INTERACTION
// PLAN IS TO CREATE A LISTENER FOR WHEN THE USER PRESSES THE INTERACTION BUTTON
// Issue is once the listener has called their interact function and determined whether or not the player is interacting with them is how to then set the bool values in player.
// IE. When the player interacts with the seed box how do we then call the SetSeedsTrue function in player?

// 19-12-2019
//
// - Need to set hasSeeds to false when player collects them from seedBox
// - Need to show player has seeds when true

// 21-12-2019
//
// Interaction is now working but only works when player is stood at certain points
// Removed interaction box but may need to add it back??

// 24-12-2019
//
// - When chickens collide with interactables, x needs to happen.
// 
// - UI Seed timer
// Create simple graphic, calculate percentage based on timer. Clip blit using that percentage.
// *It doesn't work* - You are here
//
// TRY GET PROJECTILES IMPLEMENTED AND SOME HUD!
// AT THIS POINT HAVING A ~FINISHED~ GAME DOESN'T MATTER JUST HAVE ALL THE ASPECTS:
// - PROJECTILE
// - HUD/UI
// - GAME CYCLE
// - TIMER
// LOOK AT CHECKLIST

// 27-12-2019
//
// Implemented game cycle -- Currently 'main menu' is just a black screen
// Need to make a simple graphic and implement the different options ie. play, quit, ect.
//
// Added a game timer - need to figure out hud stuff, seed box timer didn't work
