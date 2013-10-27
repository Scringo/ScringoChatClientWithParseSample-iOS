//
//  ScringoUserPublic.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class ScringoUser;

typedef void (^ScringoUserCommandsCompletionBlk)(ScringoUser *user, BOOL isSuccess);

// ScringoUserPublic (temp name)
@interface ScringoUser : NSObject

+(ScringoUser *)currentUser;
+(void)getUserByScringoId:(NSString *)userId  completion:(ScringoUserCommandsCompletionBlk)completion;

+(void)loginWithEmail:(NSString *)email password:(NSString *)password completion:(ScringoUserCommandsCompletionBlk)completion;
+(void)loginWithFacebook:(ScringoUserCommandsCompletionBlk)completion;
+(void)loginWithTwitter:(ScringoUserCommandsCompletionBlk)completion inView:(UIView *)view;
+(void)signUpWithEmail:(NSString *)email userName:(NSString *)userName password:(NSString *)password completion:(ScringoUserCommandsCompletionBlk)completion;
+(void)logout:(ScringoUserCommandsCompletionBlk)completion;
+(void)uploadUserImage:(UIImage *)image completion:(ScringoUserCommandsCompletionBlk)completion;
+(void)forgotPassword:(NSString *)email completion:(ScringoUserCommandsCompletionBlk)completion;
+(void)changePassword:(NSString *)newPassword completion:(ScringoUserCommandsCompletionBlk)completion;
+(void)save:(ScringoUserCommandsCompletionBlk)completion;

-(BOOL)isCurrent;
-(BOOL)isAuthenticated;

@property(nonatomic, assign, readonly) NSString *userId;
@property(nonatomic, assign) NSString *firstName;
@property(nonatomic, assign) NSString *lastName;
@property(nonatomic, assign) NSString *photoUrl;
@property(nonatomic, assign) NSString *email;
@property(nonatomic, assign) NSString *bio;
@property(nonatomic, readonly) long long facebookId;
@property(nonatomic, readonly) long long twitterId;

@property(nonatomic, assign, readonly) CLLocation *location;
@property(nonatomic, readonly) int numFollowers;
@property(nonatomic, readonly) int numFollowing;
@property(nonatomic, readonly) int numPosts;
@property(nonatomic, readonly) BOOL isBlockedByMe;
@property(nonatomic, readonly) BOOL isReportedByMe;
@property(nonatomic, readonly) BOOL isFollowedByMe;
@property(nonatomic, readonly) double distanceFromMe;

@end
