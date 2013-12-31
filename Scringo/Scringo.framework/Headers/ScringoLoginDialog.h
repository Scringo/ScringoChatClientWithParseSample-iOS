//
//  ScringoLoginDialog.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 25/12/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScringoUser.h"

/** Protocol definition for login dialog delegate.
 */
@protocol ScringoLoginDialogDelegate
/** Call when the user logged in.
 
 @param user The logged in user.
 */
-(void)userLoggedIn:(ScringoUser *)user;
@end

/** Scringo's Login/signup Dialog.
 
 Controls Scringo's login/signup dialog.
 */
@interface ScringoLoginDialog : NSObject

/** The dialog delegate. Will get notified when the user is logged in. */
@property (nonatomic, assign) id<ScringoLoginDialogDelegate> delegate;

/** Initialize the dialog with a delegate.
 
 @param delegate The delegate to call when user logs in.
 */
-(id)initWithDelegate:(id<ScringoLoginDialogDelegate>)delegate;

/** Show the login/signup dialog.
 
 Show the login/signup dialog in the center if the given view with the given message as the description.
 @param view The view in which center the dialog is displayed.
 @param message The message to present in the dialog, just above the buttons.
 */
-(void)showInView:(UIView *)view withMessage:(NSString *)message;

@end
