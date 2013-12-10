//
//  OtherUserProfileViewController.h
//  Scringo
//
//  Created by Ofer Kalisky on 1/18/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Other User Profile view controller.
 
 This view controller loads and controls the screen holding a user profile.
 */
@interface ScringoOtherUserProfileViewController : ScringoGeneralFeatureViewController

/** Initialize the Other User Profile view.
 
 Initialize the Other User Profile view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 @param userId Scringo User Id of the user to open the profile for.
 */
-(id)initWithUserId:(NSString *)userId;

@end
