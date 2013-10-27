//
//  SCUser.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 5/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface SCUser : NSObject

+(BOOL)amILoggedIn;
+(BOOL)isUserLoggedIn:(NSString *)userId;

+(NSString *)getMyFirstName;
+(NSString *)getUserFirstName:(NSString *)userId;

+(NSString *)getMyLastName;
+(NSString *)getUserLastName:(NSString *)userId;

+(NSString *)getMyPhotoUrl;
+(NSString *)getUserPhotoUrl:(NSString *)userId;

+(NSString *)getMyEmail;
+(NSString *)getUserEmail:(NSString *)userId;

+(long long)getMyFacebookId;
+(long long)getUserFacebookId:(NSString *)userId;

+(long long)getMyTwitterId;
+(long long)getUserTwitterId:(NSString *)userId;

+(CLLocation *)getMyLocation;
+(CLLocation *)getUserLocation:(NSString *)userId;

+(int)getMyFollowersNumber;
+(int)getUserFollowersNumber:(NSString *)userId;

+(int)getMyFollowingNumber;
+(int)getUserFollowingNumber:(NSString *)userId;

+(int)getMyPostsNumber;
+(int)getUserPostsNumber:(NSString *)userId;

+(BOOL)isUserBlockedByMe:(NSString *)userId;
+(BOOL)isUserReportedByMe:(NSString *)userId;
+(BOOL)isUserFollowedByMe:(NSString *)userId;

+(double)userDistanceFromMe:(NSString *)userId;

@end
