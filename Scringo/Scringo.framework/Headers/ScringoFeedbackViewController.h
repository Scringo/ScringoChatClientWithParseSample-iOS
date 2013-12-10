//
//  ScringoFeedbackViewController.h
//  Scringo
//
//  Created by Ofer Kalisky on 10/21/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Feedback list view controller.
 
 This view controller loads and controls the screen holding the Feedback panel.
 */
@interface ScringoFeedbackViewController : ScringoGeneralFeatureViewController

/** Initialize the Feedback view.
 
 Initialize the Feedback list view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 @param shouldShowProfileButton Whether or not the profile button should show at the screen top right corner.
 */
-(id)initFromNib:(BOOL)shouldShowProfileButton;

@end
