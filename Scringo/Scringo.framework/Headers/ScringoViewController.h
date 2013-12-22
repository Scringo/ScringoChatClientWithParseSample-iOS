//
//  ScringoViewController.h
//  Scringo
//
//  Created by Ofer Kalisky on 1/8/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Scringo Menu view controller.
 
 This view controller loads and controls the screen with Scringo's main menu.
 @warning This API should not be used if [Scringo addSidebar:toLeft:] or [Scringo openMenuWithNavigationController:withScringoNavControllerEnabled:] are in use.
 */
@interface ScringoViewController : UIViewController

/** Scringo Main Menu navigation controller. */
@property(retain, nonatomic, readonly) UINavigationController *scringoNavController;

/** Initialize Scringo's main menu view controller.
 
 Initialize Scringo's main menu view controller from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or presented modally.
 @param navController Navigation controller Scringo should be using. If nil, an internal navigation controller will be created.
 @param showScringoNavBar Whether Scringo's navigation bar shoule be shown or not. If navController is nil, this parameter is ignored and will default to YES.
 @warning If navController is nil, one should use scringoNavController for presenting this view controller modally:
 
    ScringoViewController *vc = [[ScringoViewController alloc] initFromNibWithNavController:nil showScringoNavBar:NO];
    [myViewController presentViewController:vc.scringoNavController animated:YES completion:nil];
 */
-(id)initFromNibWithNavController:(UINavigationController *)navController showScringoNavBar:(BOOL)showScringoNavBar;

@end
