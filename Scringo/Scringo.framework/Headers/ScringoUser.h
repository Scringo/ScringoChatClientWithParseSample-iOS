//
//  ScringoUserPublic.h
//  Scringo
//
//  Created by Guy Federovsky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class ScringoUser;

typedef void (^ScringoUserCommandsCompletionBlk)(ScringoUser *user, BOOL isSuccess);

/** Represents a user in Scringo.
 */
@interface ScringoUser : NSObject

/** Scringo User Id.
 */
@property(nonatomic, assign, readonly) NSString *userId;
/** Last known user location.
 */
@property(nonatomic, assign, readonly) CLLocation *location;
/** User Facebook Id, if user is connected to Facebook.
 */
@property(nonatomic, readonly) long long facebookId;
/** User Twitter Id, if user is connected to Twitter.
 */
@property(nonatomic, readonly) long long twitterId;
/** Number of users that are following the user has.
 */
@property(nonatomic, readonly) int numFollowers;
/** Number if users the user is following.
 */
@property(nonatomic, readonly) int numFollowing;
/** Number of Posts the user has posted to the activity feed.
 */
@property(nonatomic, readonly) int numPosts;
/** Is the user blocked by the current user.
 */
@property(nonatomic, readonly) BOOL isBlockedByMe;
/** Was the user reported by the current user.
 */
@property(nonatomic, readonly) BOOL isReportedByMe;
/** Is the user followed by the current user.
 */
@property(nonatomic, readonly) BOOL isFollowedByMe;
/** The distance, in meters, from the current user.
 */
@property(nonatomic, readonly) double distanceFromMe;

/** The user first name.
 */
@property(nonatomic, assign) NSString *firstName;
/** The user last name.
 */
@property(nonatomic, assign) NSString *lastName;
/** The user photo URL.
 */
@property(nonatomic, assign) NSString *photoUrl;
/** The user Email address.
 */
@property(nonatomic, assign) NSString *email;
/** The user bio.
 */
@property(nonatomic, assign) NSString *bio;

/**---------------------------------------------------------------------------------------
 * @name Obtaining a User
 *  ---------------------------------------------------------------------------------------
 */

/** Get current user.
 
 @return The current user.
 */
+(ScringoUser *)currentUser;
/** Get a user given its Id.
 
 @param userId The Id of the user one wants to retrieve.
 @param completion The completion block to call when operation ends.
 */
+(void)getUserByScringoId:(NSString *)userId  completion:(ScringoUserCommandsCompletionBlk)completion;

/**---------------------------------------------------------------------------------------
 * @name Current user methods
 *  ---------------------------------------------------------------------------------------
 */

/** Login current user with Email and Password.
 
 @param email The user Email.
 @param password The user Password.
 @param completion The completion block to call when operation is done.
 */
+(void)loginWithEmail:(NSString *)email password:(NSString *)password completion:(ScringoUserCommandsCompletionBlk)completion;
/** Login current user with Facebook.
 
 @param completion The completion block to call when operation is done.
 */
+(void)loginWithFacebook:(ScringoUserCommandsCompletionBlk)completion;
/** Login current user with Twitter.
 
 @param completion The completion block to call when operation is done.
 @param view The view this method is called from.
 */
+(void)loginWithTwitter:(ScringoUserCommandsCompletionBlk)completion inView:(UIView *)view;
/** Signup current user into Scringo.
 
 @param email The user Email.
 @param userName The User name.
 @param password The user Password.
 @param completion The completion block to call when operation is done.
 */
+(void)signUpWithEmail:(NSString *)email userName:(NSString *)userName password:(NSString *)password completion:(ScringoUserCommandsCompletionBlk)completion;
/** Logout the current user from Scringo.
 
 @param completion The completion block to call when operation is done.
 */
+(void)logout:(ScringoUserCommandsCompletionBlk)completion;
/** Upload an image for the current user.
 
 @param image Image to upload.
 @param completion The completion block to call when operation is done.
 */
+(void)uploadUserImage:(UIImage *)image completion:(ScringoUserCommandsCompletionBlk)completion;
/** Ask Scringo to be 'reminded' with the user password.

 Once the Email is found within Scringo servers, an email will be sent to it with the required information.
 
 @param email The Email of the user which password is forgotten.
 @param completion The completion block to call when operation is done.
 */
+(void)forgotPassword:(NSString *)email completion:(ScringoUserCommandsCompletionBlk)completion;
/** Ask Scringo to change the current user password.
 
 @param newPassword The new password, in cleartext.
 @param completion The completion block to call when operation is done.
 */
+(void)changePassword:(NSString *)newPassword completion:(ScringoUserCommandsCompletionBlk)completion;
/** Save latest changes to current user.
 
 @param completion The completion block to call when operation is done.
 */
+(void)save:(ScringoUserCommandsCompletionBlk)completion;

/**---------------------------------------------------------------------------------------
 * @name Other user interactions
 *  ---------------------------------------------------------------------------------------
 */

/** Block a user.
 
 Prevent a certain user from interacting with the current user.
 
 @param userId User Id of the user to block.
 */
+(void)blockUser:(NSString *)userId;
/** Unblock a user.
 
 Cancel previous certain user blocking from interacting with the current user.
 
 @param userId User Id of the user to unblock.
 */
+(void)unblockUser:(NSString *)userId;
/** Report a user.
 
 Report a certain user to the app developer. The app developer can later decide to ban or unban the user from using Scringo.
 
 @param userId User Id of the user to report.
 */
+(void)reportUser:(NSString *)userId;
/** Unreport a user.
 
 Cancel a certain user report to the app developer. The app developer can later decide to ban or unban the user from using Scringo.
 
 @param userId User Id of the user to unreport.
 */
+(void)unreportUser:(NSString *)userId;

/**---------------------------------------------------------------------------------------
 * @name Accessors
 *  ---------------------------------------------------------------------------------------
 */

/** Is the user the current one.
 
 @return True if the user is the current one. False otherwise.
 */
-(BOOL)isCurrent;
/** Is the user authenticated.
 
 @return True if the user is logged into Scringo. False otherwise.
 */
-(BOOL)isAuthenticated;

@end
