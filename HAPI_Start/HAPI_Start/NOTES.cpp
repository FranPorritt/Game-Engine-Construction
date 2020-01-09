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

// 29-12-2019
//
// Added game timer and ui class

// 30-12-2019
//
// - Sound?
//
// CLOCKS_PER_SEC for respawn rates? 
//
// Fixed seedbox timer -- clipping isn't perfect tho still needs work

// 03-01-2020
//
// Started on projectiles
// Initialising of vector is broken
// Added throw function -- only calls movement once need to call it until off screen or hits

//05-01-2020
//
// Adding egg count - score
// Don't love transition state in chickens -- hang around in the centre of screen rather than wandering due to it :(
// Fixed transition -- just needed to call Handle immediately after transition completed
//
// Chicken - egg state -- get coop pos
//
// COOP COLLISION DOESN'T WORK sadface

// 06-01-2020
//
// Projectile works (gets thrown on press moves in direction)
// Issues/to-do:
// - Needs to stop either at edge of screen (ie. activeFlag=false if off screen) or for a limited time (ie. for x distance or until off screen)
// - What happens if player is stood still, should go in last direction player was moving but need to account for if player has been stood still a while
//   should be a simple fix to current system, just add a check for if player stopped don't change last direction?
//				SOLUTION:	Rock only lasts x seconds, meaning it can only go so far and if player hasn't moved since starting game rock just drops
//							and then disappears after set time.
// - Collisions with enemy (currently no enemies :( )
// - Currently only works for first rock then won't throw again -- I think it's setting every rock to active after one press, thus not working until inactive again
//  Need to only set the first inactive rock to active
// 
// Changed it so player can only throw one rock at a time, has to wait x seconds before throwing another
//
// Fixed coop collision and weird glitch where feeder and seed box collisions only worked at one spot -- had it set to use an interactionBox rect
// in interactables but never set the rect to anything, changed it to use normal rectangle (y)
//
// Make vis a singleton so it can be accessed in UI and used for timer graphic and egg graphic? - DONE - Should it be done with UI too?
//
// Movement works with controller but need to do everything else too
//
//
// TO DO:
// Fix timer - Only works under 60 seconds :(
// * Controls (controller -- only works for movement)
// *** Enemy AI  ---  Also second AI (bear) if time
// * Pause
// ** End Game - Restart
// Better menu -- do similar to snake (if time)
// ** Fix quit memory leaks
// * Animation
// ** Interpolation (B to A mark)
//
//
// Difficulty features:
// Easier:
// - More chickens
// - More time
// - Faster refill time on seeds
// - More eats per seed
// - Slower enemy spawns

// 07-01-2020
//
// Future additions - report:
// - Set speed in entity not just chick -- pick ups for player?
//
// Hindsight - should have made cat and chicken children of an ai class
//			 - should have done chicken entity vector as list so i could remove them when dead
//
// Implemented cat ai and fsm
// cat catches chicken and kills it - need to make chicken fleeState
// FleeingState being set every loop meaning chicken is just running in tight circle
// Need to figure out how to immediately call handle when chicken starts fleeing but then only call it once
// every x seconds????
//
// LeavingState - if on right of screen dir = right until xPos > screenwidth
//				- else dir = left until xPos < 0 - spriteWidth
// Speed is meant to set to 3 when leaving, was working now that multiple cats work its broke
// Set it with direction instead and works now
//
// Added controller handling for throw and use -- NEEDS TESTING DO IN MORNING
//
// ROCK COLLISIONS HAVE TO BE DONE TOMORROW!!!! Cats and rocks are seperate from entity vectors so should be simple
// enough -- just same as entity collisions but pass in rock and cat?

// 08-01-2020
//
// Rock collisions done! :D
//
// To Do List:
// - Game cycling
//		- Pause
//		- Restart
// - Difficulty level
//		- Two options
// - Sound/Animation
// - Interpolation
//
//
// Started making sound class but not sure I need it
//
// Started working on a restart/return to menu after times up but it's not working, no idea what's wrong :(
//
// Pause works but button press is sensitive
// Doesn't stop timer - simple fix should just to be to track how much time passes during paused time and it to game timer?