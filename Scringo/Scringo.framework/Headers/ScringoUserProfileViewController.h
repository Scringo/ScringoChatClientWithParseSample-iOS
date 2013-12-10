//
//  ScringoUserProfileViewController.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 5/13/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Current User Profile view controller.
 
 This view controller loads and controls the screen holding the current user profile.
 */
@interface ScringoUserProfileViewController : ScringoGeneralFeatureViewController

/** Initialize the Current User Profile view.
 
 Initialize the Current User Profile view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 */
-(id)initFromNib;

@end
