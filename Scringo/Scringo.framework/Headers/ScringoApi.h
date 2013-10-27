//
//  ScringoApi.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 14/7/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ScringoAgent.h"
#import "SCUser.h"
#import "SCChatRoomTopic.h"
#import "SCQuiz.h"

//#import "ScringoStyleSheetProtocol.h"

#define kNotificationBadgesNumberChanged    @"ScringoBadgeNumberChangedNotification"

// Scringo's Features
#define kScringoFeatureTabTagBase           700

@interface ScringoApi : NSObject

+(void)initWithAppId:(NSString *)appId completion:(ScringoStartSessionCompletionBlk)completion;
+(void)addSidebar:(UIWindow *)toWindow toLeft:(BOOL)toLeft;

+(void)preloadInboxWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadActivityWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadChatRoomsWithCompletion:(ScringoStartSessionCompletionBlk)completion;
+(void)preloadQuizzesWithCompletion:(ScringoStartSessionCompletionBlk)completion;
//+(void)preLoadRadar;
//+(void)preLoadRadarWithCompletion:(ScringoStartSessionCompletionBlk)completion;

//+(void)openMenuInWindow:(UIWindow *)window;
+(void)openMenuInPopoverWithRect:(CGRect)rect inView:(UIView *)view;
+(void)openMenuWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
//+(void)addMenuToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;

//+(void)openFeature:(NSString *)featureId inWindow:(UIWindow *)window;
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
+(void)openStickerStoreWithNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

//+(void)addQuizToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addInboxToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addChatRoomsToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addFeedbackToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addFindInviteFriendsToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addRadarToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addLeaderboardToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addActivityToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addLoginToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addSignupToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;
//+(void)addMyProfileToTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;

+(void)openChatWithUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
+(void)openProfileForUser:(NSString *)otherUserId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;
//+(void)addChatWithUser:(NSString *)otherUserId toTabBarController:(UITabBarController *)tabBarController atPosition:(int)position;

+(int)getFeatureBadgeNumber:(ScringoFeatureId)featureId;

// Returns array of Chat Room Topic Ids
+(NSArray *)getChatRoomTopics;
+(void)openChatRoomWithTopicId:(int)chatRoomTopicId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

// Returns array of Quiz Ids
+(NSArray *)getQuizzes;
+(void)openQuizWithId:(int)quizId withNavigationController:(UINavigationController *)navController withScringoNavControllerEnabled:(BOOL)scringoNavControllerEnabled;

@end
