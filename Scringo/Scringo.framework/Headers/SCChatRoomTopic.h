//
//  SCChatRoomTopic.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 4/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SCChatRoomTopic : NSObject

+(int)getCommentsNumber:(int)topicId;
+(int)getLikesNumber:(int)topicId;

+(NSString *)getTitle:(int)topicId;
+(NSString *)getText:(int)topicId;

+(NSString *)getPhotoUrl:(int)topicId;

+(NSString *)getUser:(int)topicId;

@end
