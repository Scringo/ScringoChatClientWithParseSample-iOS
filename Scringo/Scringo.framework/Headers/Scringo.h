//
//  Scringo.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "ScringoStyleSheetProtocol.h"

#define kNotificationScringoIsReady                 @"ScringoIsReady"
#define kNotificationBadgesNumberChanged            @"ScringoBadgeNumberChangedNotification"
#define kScringoNotificationActivityActionTapped    @"kScringoNotificationActivityActionTapped"
#define kNotificationUserSignInChanged              @"ScringoUserSigninChanged"
#define kScringoCustomButtonClicked                 @"kScringoCustomButtonClicked"

// Scringo's Features
#define kScringoFeatureTabTagBase           700

typedef void (^ScringoStartSessionCompletionBlk)(void);

typedef enum {
    SCRINGO_FEATURE_ACTIVITY            = 0,
    SCRINGO_FEATURE_MESSAGES            = 1,
    SCRINGO_FEATURE_CHAT_ROOMS          = 2,
    SCRINGO_FEATURE_FIND_INVITE_FRIENDS = 3,
    SCRINGO_FEATURE_RADAR               = 4,
    SCRINGO_FEATURE_UNKNOWN             = 5
} ScringoFeatureId;

typedef enum {
    SCRINGO_BUTTON1,
    SCRINGO_BUTTON2,
    SCRINGO_BUTTON3,
    SCRINGO_BUTTON4,
} ScringoActivationButtonType;

@protocol ScringoImageFetcher;

@protocol ScringoImageFetcherDelegate <NSObject>
-(void)imageFetcherDidFinish:(id<ScringoImageFetcher>)imageFetcher withImage:(UIImage *)image;
-(void)imageFetcherGotError:(id<ScringoImageFetcher>)imageFetcher withError:(NSError *)error;
-(NSString *)imageFetcherDelegateId;
@end

@protocol ScringoImageFetcher <NSObject>
-(BOOL)fetchImage:(NSString *)imageLocation withDelegate:(id<ScringoImageFetcherDelegate>)delegate;
-(void)cancelDelegate:(id<ScringoImageFetcherDelegate>)delegate;
-(BOOL)shouldEnableImageShare:(NSString *)imageLocation;
-(NSString *)shareUrlForImage:(NSString *)imageLocation;
@end

/** This is the main entry point to all that Scringo API has to offer.
 */
@interface Scringo : NSObject

#pragma mark Init
/**---------------------------------------------------------------------------------------
 * @name Initializating Scringo
 *  ---------------------------------------------------------------------------------------
 */

/** Init Scringo with your application id.
 
 Initialize Scringo with your Scringo application id. This method must be called prior to any other call to Scringo. You can also pass a completion handler to be executed when initialization has completed.
 
 @param appId Your Scringo Application Id.
 @param completion The handler to call when the initialization has completed.
 */
+(void)initWithAppId:(NSString *)appId completion:(ScringoStartSessionCompletionBlk)completion;

/** Set a custom styling sheet handler.
 
 Set the handler to be used to custom style Scringo's UI.
 
 @param styleSheet The handler that defines the custom style to use.
 */
+(void)setCustomStyleSheet:(id<ScringoStyleSheetProtocol>)styleSheet;

/** Set Scringo to work in test mode.
 
 @param testMode True if Scringo should work in test mode. False, otherwise.
 */
+(void)setTestMode:(BOOL)testMode;

/** Set the location manager to use.
 
 Set the Location Manger Scringo should use for its location based features.
 
 @param locationManager The location manager to use.
 */
+(void)setLocationManager:(CLLocationManager *)locationManager;

/** Set the custom image fetcher to use.
 
 Set the Custom Image Fetcher Scringo should use when fetching images.
 
 @param customImageFetcher The image fetcher to use.
 */
+(void)setCustomImageFetcher:(id<ScringoImageFetcher>)customImageFetcher;

#pragma mark Sidebar

/**---------------------------------------------------------------------------------------
 * @name Working with sidebar
 *  ---------------------------------------------------------------------------------------
 */

/** Add a community sidebar to your app.
 
 Add Scringo's community as a sidebar. This method adds a sidebar to your window.
 
 @param toWindow The window where to add the sidebar. You can use [UIApplication sharedApplication].keyWindow to get your current key window.
 @param toLeft Whether to add the sidebar to the left (YES) or to the right (NO).
 */
+(void)addSidebar:(UIWindow *)toWindow toLeft:(BOOL)toLeft;

/** Enable swiping to open sidebar.
 */
+(void)enableSwipeToOpenSidebar;

/** Disable swiping to open sidebar.
 */
+(void)disableSwipeToOpenSidebar;

/** Returns whether swipe to open sidebar is enabled or not.
 
 @return Whether swipe is enabled or not.
 */
+(BOOL)isSwipeOpenSidebar;

/** Open the sidebar programmatically.
 */
+(void)openSidebar;

/** Close the sidebar programmatically.
 */
+(void)closeSidebar;

/** Returns whether the sidebar is open or not.
 
 @return Whethter the sidebar is open or not.
 */
+(BOOL)isSidebarOpen;

#pragma mark Push and Facebook

/**---------------------------------------------------------------------------------------
 * @name Setting push
 *  ---------------------------------------------------------------------------------------
 */

/** Tell Scringo that the user has registered the device token.
 
 Should be called in the application delegate compatible method.
 
 @param deviceToken A token that identifies the device to the Push Service.
 */
+(void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/** Tell Scringo that the device token registration for remote notifications has failed.
 
 Should be called in the application delegate compatible method.
 
 @param deviceToken A token that identifies the device to the Push Service.
 */
+(void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/** Tell Scringo that a remote notification was received.
 
 Should be called in the application delegate compatible method.
 
 @param deviceToken A token that identifies the device to the Push Service.
 */
+(void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/** Tell Scringo that a URL is about to open.
 
 Should be called in the application delegate compatible method.
 
 @param deviceToken A token that identifies the device to the Push Service.
 @return Whether handling was successful or not.
 */
+(BOOL)handleOpenURL:(NSURL *)url;

/** Silently connect Scringo to user's Facebook.
 
 Should be called after the user has successfully connected to Facebook through the application.
 */
+(void)connectFacebook;

/** Silently disconnect Scringo from user's Facebook.
 
 Should be called after the user has successfully disconnected from Facebook through the application.
 */
+(void)disconnectFacebook;

#pragma mark Activation Button
/** Set the type of Scringo's activation button.
 
 This activation button type will be used throught Scringo's features.
 
 @param buttonType Type of Scringo activation button to use.
 */
+(void)setScringoActivationButtonType:(ScringoActivationButtonType)buttonType;

+(UIBarButtonItem *)scringoActivationBarItem;
+(UIButton *)scringoActivationButtonOpensToLeft:(BOOL)opensToLeft;


#pragma mark Preload features

+(void)preloadInboxWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadActivityWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadChatRoomsWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadQuizzesWithCompletion:(ScringoStartSessionCompletionBlk)completion;

#pragma mark Open Screens
+(void)openMenuInPopoverWithRect:(CGRect)rect inView:(UIView *)view;
+(void)openMenuWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

+(void)openQuizWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openInboxWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openChatRoomsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openFeedbackWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openFindInviteFriendsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openRadarWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openLeaderboardWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openActivityWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openLoginWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openSignupWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openMyProfileWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openTalkToUsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark Open exact chatroom/quiz
+(void)openChatRoomWithTopicId:(int)chatRoomTopicId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openQuizWithId:(int)quizId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark Screens with other users
+(void)openChatWithUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openProfileForUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark model related
+(int)getFeatureBadgeNumber:(ScringoFeatureId)featureId;

+(NSArray *)getChatRoomTopics;

// Returns array of Quiz Ids
+(NSArray *)getQuizzes;

/**---------------------------------------------------------------------------------------
 * @name Posting custom actions to the activity feed
 *  ---------------------------------------------------------------------------------------
 */
/** Post a simple message to the activity feed
 
 @param feedMessage The text message to post
 */
+(void)postToFeed:(NSString *)feedMessage;
+(void)postToFeed:(NSString *)feedMessage withLink:(NSString *)link;
+(void)postToFeed:(NSString *)feedMessage withImage:(NSString *)imageUrl withDescription:(NSString *)description withSubDesc:(NSString *)subDesc withActionVerb:(NSString *)actionVerb withActionId:(NSString *)actionId;

+(void)setUserScore:(long)score;

@end
