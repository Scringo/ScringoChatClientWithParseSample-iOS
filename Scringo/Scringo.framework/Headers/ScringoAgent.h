//
//  ScringoAgent.h
//  ScringoExample2
//
//  Created by Ofer Kalisky on 1/10/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#import "Scringo.h"

// http://www.cocoanetics.com/2011/11/amazing-apple-like-documentation/

/** The ScringoAgent class is the integration point for almost all calls to Scringo. All calls to ScringoAgent methods are static.
 
 Some typical calls to ScringoAgent:
 
    // Initializing Scringo in your app
    [ScringoAgent startSession:@"ScringoAppId" locationManager:nil];
 
    // Don't open Scringo's sidebar with the swipe gesture
    [ScringoAgent pauseSwipe];
 
 */

//__attribute__((deprecated("You should start using Scringo from Scringo.h")))
@interface ScringoAgent : NSObject {

}


/**---------------------------------------------------------------------------------------
 * @name Initializating Scringo
 *  ---------------------------------------------------------------------------------------
 */

/** This is the simplest way to initialize Scringo
 
 @param appId Your Scringo Application Id
 @param locationManager Your app's location manager (or nil if your app doesn't use location manager).
 */
+(void)startSession:(NSString *)appId locationManager:(CLLocationManager *)locationManager;
+(void)startSession:(NSString *)appId locationManager:(CLLocationManager *)locationManager completion:(ScringoStartSessionCompletionBlk)completion;
+(void)startSession:(NSString *)appId locationManager:(CLLocationManager *)locationManager withDelay:(float)delay;
+(void)startSession:(NSString *)appId locationManager:(CLLocationManager *)locationManager withDelay:(float)delay completion:(ScringoStartSessionCompletionBlk)completion;
+(void)setTestMode:(BOOL)testMode;

/**---------------------------------------------------------------------------------------
 * @name Handling the swipe gestures
 *  ---------------------------------------------------------------------------------------
 */

/** Don't open Scringo's sidebar on swipe gesture.
 */
+(void)pauseSwipe;
/** Open Scringo's sidebar on swipe gesture.
 */
+(void)resumeSwipe;
/** Check if swipe gesture is enabled.
 @return YES is swipe gesture is enabled.

 */
+(BOOL)isSwipeEnalbed;

+(void)openSidebar;
+(void)closeSidebar;

// Some utility function that Scringo provides
+(void) postToFacebookWall:(NSMutableDictionary *)params;

+(void)setScringoActivationButtonType:(ScringoActivationButtonType)buttonType;
+(UIBarButtonItem *)scringoActivationBarItem;
+(UIButton *)scringoActivationButtonOpensToLeft:(BOOL)opensToLeft;

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

+(BOOL)isPopInAdsEnabled;
+(void)showPopInAdNow;
+(void)disablePopInAds:(BOOL)disablePopInAds;
+(void)disableSideBarAds:(BOOL)disableSideBarAds;

+(void)setCustomImageFetcher:(id<ScringoImageFetcher>)customImageFetcher;

+(void)connectFacebook;
+(void)disconnectFacebook;

+(void)setUserScore:(long)score;

+(BOOL)isUserLoggedIn;
+(NSString *)getUserId;

+(void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+(void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
+(void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

+(BOOL) handleOpenURL:(NSURL *)url;

@end
