//
//  RadarViewController.h
//  Scringo
//
//  Created by Ofer Kalisky on 1/16/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"
 
/** Activity Feed view controller.
 
 This view controller loads and controls the screen holding the app Activity Feed.
 */
@interface ScringoFeedViewController : ScringoGeneralFeatureViewController

/** Initialize the Activity Feed view.
 
 Initialize the Activity Feed view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 @param shouldShowProfileButton Whether or not the profile button should show at the screen top right corner.
 */
-(id)initFromNib:(BOOL)shouldShowProfileButton;

@end
