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

/** Defines available Feature Ids */
typedef NS_ENUM(NSUInteger, ScringoFeatureId) {
    /** Activity Feed Feature Id */
    SCRINGO_FEATURE_ACTIVITY            = 0,
    /** Inbox Feature Id */
    SCRINGO_FEATURE_MESSAGES            = 1,
    /** Chat Rooms Feature Id */
    SCRINGO_FEATURE_CHAT_ROOMS          = 2,
    /** Find and Invite Friends Feature Id */
    SCRINGO_FEATURE_FIND_INVITE_FRIENDS = 3,
    /** Radar Feature Id */
    SCRINGO_FEATURE_RADAR               = 4,
    /** Unknown Feature Id */
    SCRINGO_FEATURE_UNKNOWN             = 5
};

/** Defines different activation button types */
typedef NS_ENUM(NSUInteger, ScringoActivationButtonType) {
    SCRINGO_BUTTON1,
    SCRINGO_BUTTON2,
    SCRINGO_BUTTON3,
    SCRINGO_BUTTON4,
};

@protocol ScringoImageFetcher;

/** Delegate for the Scringo Image Fetcher.
 */
@protocol ScringoImageFetcherDelegate <NSObject>
/** Handle image fetching success.
 
 Called by the Image Fetcher when an image was fetched successfully.
 
 @param imageFetcher The image fetcher that fetched the image.
 @param image The fetched image.
 */
-(void)imageFetcherDidFinish:(id<ScringoImageFetcher>)imageFetcher withImage:(UIImage *)image;
/** Handle image fetching failure.
 
 Called by the Image Fetcher when an image fetch has failed.
 
 @param imageFetcher the image fetcher that fetched the image.
 @param error The error description.
 */
-(void)imageFetcherGotError:(id<ScringoImageFetcher>)imageFetcher withError:(NSError *)error;
/** Delegate Id
 
 Returns an Id with which is the delegate is to be identified.
 
 @return Id with which the delegate is to be identified.
 */
-(NSString *)imageFetcherDelegateId;
@end

/** Scringo Image Fetcher Protocol definition.
 
 Allows the application to override Scringo's image fetching. For example, when wanting to supply images that are stored locally.
 */
@protocol ScringoImageFetcher <NSObject>
/** Ask the Image fetcher to fetch an image from a certain location.
 
 The Image Fetcher is expected to call [ScringoImageFetcherDelegate imageFetcherDidFinish:withImage:] with the image retrieved. If an error occurs, [ScringoImageFetcherDelegate imageFetcherGotError:withError:] should be called.

 @param imageLocation Location of the image to retrieve.
 @param delegate Delegate to call to when image is fetched or failed to be fetched.
 @return True if the image fetcher is handling the fetching. False if Scringo is expected to do that.
 @see [ScringoImageFetcherDelegate imageFetcherDidFinish:withImage:]
 @see [ScringoImageFetcherDelegate imageFetcherGotError:withError:]
 */
-(BOOL)fetchImage:(NSString *)imageLocation withDelegate:(id<ScringoImageFetcherDelegate>)delegate;
/** Cancel image retrieval
 
 Called when the image retrieval is no longer required.
 
 @param delegate Delegate to call to when image is fetched or failed to be fetched.
 */
-(void)cancelDelegate:(id<ScringoImageFetcherDelegate>)delegate;
/** Asks whether an image should be shared on the Activity Feed or not.
 
 Called by the Activity Feed view when a shareable image is about to be shown, asking whether to share it or not.
 
 @param imageLocation Location of the image to share
 @return True if image should be shareable, False otherwise.
 */
-(BOOL)shouldEnableImageShare:(NSString *)imageLocation;
/** Asks whether an image should be shared on the Activity Feed or not.
 
 Called to determine the URL to share when requested to share an image. Returning nil means the image original URL is good enough. Otherwise, the returned string will be used.
 
 @param imageLocation Location of the image to share
 @return Share URL or nil if original image location is good enough.
 */
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
 
 Add Scringo's community as a sidebar. This method adds a sidebar to your window. You can use
 
    [UIApplication sharedApplication].keyWindow
 
 to get your current key window.
 
 @param toWindow The window where to add the sidebar.
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
 
 @param error The error information.
 */
+(void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/** Tell Scringo that a remote notification was received.
 
 Should be called in the application delegate compatible method.
 
 @param userInfo Information about the remote notification.
 */
+(void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/** Tell Scringo that a URL is about to open.
 
 Should be called in the application delegate compatible method.
 
 @param url The URL to handle.
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
/**---------------------------------------------------------------------------------------
 * @name Activation Buttons
 *  ---------------------------------------------------------------------------------------
 */

/** Set the type of Scringo's activation button.
 
 This activation button type will be used throught Scringo's features.
 
 @param buttonType Type of Scringo activation button to use.
 */
+(void)setScringoActivationButtonType:(ScringoActivationButtonType)buttonType;

/** Get a bar item with which Scringo Menu can be swiped in.
 
 Returns an activation bar item, styled according to whatever was set with setScringoActivationButtonType: which shold be placed on the view navigation bar.
 Pressing this activation bar item swipes Scringo's menu in.
 @return An activation bar item.
 @see setScringoActivationButtonType:
 */
+(UIBarButtonItem *)scringoActivationBarItem;
/** Get an activation button with which Scringo's Menu can be swiped in.
 
 Returns an activation button, styled according to whatever was set with setScringoActivationButtonType: which should be placed aligned to the side in which Scringo's menu is situated.
 Pressing this activation button swipes Scringo's menu in.
 @param opensToLeft True if sidebar opens to left. False otherwise.
 @return An activation bar item.
 @see setScringoActivationButtonType:
 */
+(UIButton *)scringoActivationButtonOpensToLeft:(BOOL)opensToLeft;

#pragma mark Preload features
/**---------------------------------------------------------------------------------------
 * @name Preload Features
 *  ---------------------------------------------------------------------------------------
 */

/** Preload Scringo's Inbox.
 
 Directs Scringo to preload its Inbox feature, so data is available already when accessing it.
 @param completion Completion block to be called when done preloading. Can be nil.
 */
+(void)preloadInboxWithCompletion:(ScringoStartSessionCompletionBlk)completion;
/** Preload Scringo's Activity Feed.
 
 Directs Scringo to preload its Activity Feed feature, so data is available already when accessing it.
 @param completion Completion block to be called when done preloading. Can be nil.
 */
+(void)preloadActivityWithCompletion:(ScringoStartSessionCompletionBlk)completion;
/** Preload Scringo's Chat Rooms.
 
 Directs Scringo to preload its Chat Rooms feature, so data is available already when accessing it.
 @param completion Completion block to be called when done preloading. Can be nil.
 */
+(void)preloadChatRoomsWithCompletion:(ScringoStartSessionCompletionBlk)completion;
/** Preload Scringo's Quizzes.
 
 Directs Scringo to preload its Quizzes feature, so data is available already when accessing it.
 @param completion Completion block to be called when done preloading. Can be nil.
 */
+(void)preloadQuizzesWithCompletion:(ScringoStartSessionCompletionBlk)completion;

#pragma mark Open Screens
/**---------------------------------------------------------------------------------------
 * @name Open Features
 *  ---------------------------------------------------------------------------------------
 */

/** Open Scringo's Menu within a Popover (iPad only).
 
 Open Scringo's Menu with a popover out of a given rectangle within a view.
 @param rect Where to open the popover from.
 @param view Origin view from which the popover should open.
 @warning Available only for iPad
 */
+(void)openMenuInPopoverWithRect:(CGRect)rect inView:(UIView *)view;
/** Open Scringo's Menu.
 
 Open Scringo's Menu. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Menu will be pushed. If nil, Scringo's Menu will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 @warning This method cannot be used together with addSidebar:toLeft: .
 @see addSidebar:toLeft:
 */
+(void)openMenuWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

/** Open Scringo's Quizzes Screen.
 
 Open Scringo's Quizzes. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Quizzes will be pushed. If nil, Scringo's Quizzes will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openQuizWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Inbox Screen.
 
 Open Scringo's Inbox. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Inbox will be pushed. If nil, Scringo's Inbox will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openInboxWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Chat Rooms Screen.
 
 Open Scringo's Chat Rooms. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Chat Rooms will be pushed. If nil, Scringo's Chat Rooms will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openChatRoomsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Feedback Screen.
 
 Open Scringo's Feedback. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Feedback will be pushed. If nil, Scringo's Feedback will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openFeedbackWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Invite and Find Friends Screen.
 
 Open Scringo's Invite and Find Friends. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Invite and Find Friends will be pushed. If nil, Scringo's Invite and Find Friends will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openFindInviteFriendsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Radar Screen.
 
 Open Scringo's Radar. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Radar will be pushed. If nil, Scringo's Radar will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openRadarWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Leaderboard Screen.
 
 Open Scringo's Leaderboard. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Leaderboard will be pushed. If nil, Scringo's Leaderboard will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openLeaderboardWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Activity Feed Screen.
 
 Open Scringo's Activity Feed. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Activity Feed will be pushed. If nil, Scringo's Activity Feed will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openActivityWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Login Screen.
 
 Open Scringo's Login Screen. How it should appear and what type of navigation will it have depends on the given arguments.
 If the current user is already logged in, the user Profile screen will be opened.
 @param navController The navigation controller to which Scringo's Login Screen will be pushed. If nil, Scringo's Login Screen will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openLoginWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Signup Screen
 
 Open Scringo's Signup Screen. How it should appear and what type of navigation will it have depends on the given arguments.
 If the current user is already logged in, the user Profile screen will be opened.
 @param navController The navigation controller to which Scringo's Signup Screen will be pushed. If nil, Scringo's Signup Screen will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openSignupWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's User Profile Screen
 
 Open Scringo's Current User Profile Screen. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's User Profile will be pushed. If nil, Scringo's User Profile will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openMyProfileWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's Talk To Us Screen
 
 Open Scringo's Talk To Us. How it should appear and what type of navigation will it have depends on the given arguments.
 @param navController The navigation controller to which Scringo's Talk To Us will be pushed. If nil, Scringo's Talk To Us will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openTalkToUsWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark Open exact chatroom/quiz
/** Open a certain Scringo Quiz.
 
 Open a certain Scringo Quiz given its Id. How it should appear and what type of navigation will it have depends on the given arguments.
 The Quiz Id can be obtained using getQuizzes.
 @param quizId The Id of the quiz to open.
 @param navController The navigation controller to which Scringo's Quiz will be pushed. If nil, Scringo's Quiz will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 @see getQuizzes
 */
+(void)openQuizWithId:(int)quizId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open a certain Scringo Chat Room.
 
 Open a certain Scringo Chat Room given its Id. How it should appear and what type of navigation will it have depends on the given arguments.
 The chat Room Id can be obtained using getChatRoomTopics.
 @param chatRoomTopicId The Id of the Chat Room to open.
 @param navController The navigation controller to which Scringo's Chat Room will be pushed. If nil, Scringo's Chat Room will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 @see getChatRoomTopics
 */
+(void)openChatRoomWithTopicId:(int)chatRoomTopicId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark Screens with other users
/** Open Scringo's Chat Screen with a certain user
 
 Open Scringo's Chat Screen with a user with the given Id. How it should appear and what type of navigation will it have depends on the given arguments.
 @param otherUserId Id of the user with which the Chat will take place.
 @param navController The navigation controller to which Scringo's Chat Screen will be pushed. If nil, Scringo's Chat Screen will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openChatWithUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
/** Open Scringo's User Profile Screen
 
 Open Scringo's User Profile Screen for a user with the given Id. How it should appear and what type of navigation will it have depends on the given arguments.
 @param otherUserId Id of the user which Profile we'd like to open.
 @param navController The navigation controller to which Scringo's User Profile will be pushed. If nil, Scringo's User Profile will present as MODAL.
 @param scringoNavControllerEnabled Whether to enable Scrigno's navigation bar or not.
 */
+(void)openProfileForUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

#pragma mark model related
/**---------------------------------------------------------------------------------------
 * @name Model
 *  ---------------------------------------------------------------------------------------
 */

/** Get the current badge number of a certain feature.
 
 Returns the current badge number given a certain feature Id.
 @param featureId The feature Id, which badge number we're interested in.
 @return Badge number for the given featureId.
 */
+(int)getFeatureBadgeNumber:(ScringoFeatureId)featureId;

/** Get currently loaded array of Chat Room Topic Ids.
 
 Returns an array of Chat Room topic Ids (integers) that are currently available.
 @return Array of NSNumber object, each holding a topic Id.
 */
+(NSArray *)getChatRoomTopics;

/** Get currently loaded array of Quiz Ids.
 
 Returns an array of Quiz Ids (integers) that are currently available.
 @return Array of NSNumber object, each holding a quiz Id.
 */
+(NSArray *)getQuizzes;

/**---------------------------------------------------------------------------------------
 * @name Posting custom actions to the activity feed
 *  ---------------------------------------------------------------------------------------
 */
/** Post a simple message to the activity feed.
 
 @param feedMessage The text message to post.
 */
+(void)postToFeed:(NSString *)feedMessage;
/** Post a message with a link to the activity feed.
 
 @param feedMessage The text message to post.
 @param link The link to post the message with.
 */
+(void)postToFeed:(NSString *)feedMessage withLink:(NSString *)link;
/** Post a message with image to the activity feed.
 
 @param feedMessage The text message to post.
 @param imageUrl The Image URL that is part of the post.
 @param description The Image description.
 @param subDesc Optional Image sub-description.
 @param actionVerb The title that will be given to the action button. Can be nil.
 @param actionId The action id that will be supplied with the notification when the action button is clicked.
 */
+(void)postToFeed:(NSString *)feedMessage withImage:(NSString *)imageUrl withDescription:(NSString *)description withSubDesc:(NSString *)subDesc withActionVerb:(NSString *)actionVerb withActionId:(NSString *)actionId;

/** Set the current user score.
 
 Call this whenever the user performs an action to which you want to give score for. The total score tables appear in the Leaderboard.
 
 @param score Score to set.
 @param level The level. Set to nil or @"" for general level.
 */
+(void)setUserScore:(long)score withLevel:(NSString *)level;

@end
