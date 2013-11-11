//
//  ScringoChatRoomsViewController.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 4/4/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Chat Rooms list view controller.
 
 This view controller loads and controls the screen holding a list of available chat rooms, allowing entering and using any of them.
 */
@interface ScringoChatRoomsViewController : ScringoGeneralFeatureViewController

/** Initialize the Chat Rooms list view.
 
 Initialize the Chat Rooms list view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 @param shouldShowProfileButton Should the user profile button be visible or not.
 */
-(id)initFromNib:(BOOL)shouldShowProfileButton;

@end
    