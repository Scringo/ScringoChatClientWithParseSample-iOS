//
//  ScringoLeaderboardViewController.h
//  Scringo
//
//  Created by Guy Federovsky on 10/6/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Leaderboard / High Scores view controller.
 
 This view controller loads and controls the screen holding the app Leaderboard or a certain app High Scores information.
 */
@interface ScringoLeaderboardViewController : ScringoGeneralFeatureViewController

/** Initialize the Leaderboard / High Scores view.
 
 Initialize the Leaderboard / High Scores view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 @param level Category to which the High Scores relate. If empty, the app Leaderboard will open.
 @param shouldShowProfileButton Whether or not the profile button should show at the screen top right corner.
 */
-(id)initFromNibWithLevel:(NSString *)level shouldShowProfileButton:(BOOL)shouldShowProfileButton;

@end
