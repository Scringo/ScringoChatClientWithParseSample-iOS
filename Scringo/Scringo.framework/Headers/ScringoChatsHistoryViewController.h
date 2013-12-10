//
//  ScringoChatsHistoryViewController.h
//  Scringo
//
//  Created by Ofer Kalisky on 1/16/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ScringoGeneralFeatureViewController.h"

/** Inbox list view controller.
 
 This view controller loads and controls the screen holding a list of available chats, allowing entering an existing chat and creating a new one.
 */
@interface ScringoChatsHistoryViewController : ScringoGeneralFeatureViewController

/** Initialize the Inbox list view.
 
 Initialize the Inbox list view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 */
-(id)initFromNib;

@end
