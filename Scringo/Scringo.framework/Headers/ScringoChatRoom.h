//
//  ScringoChatRoom.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScringoUser.h"

// EGEG - This is copied from ScringoChatRoomsTopicsRepository... Need them both used a single header
// EGEG - Notification should include the relevant object (chatroom / chatroom topic)
#define kNotificationNewTopics           @"ScringoChatRoomsNewTopicsNotification"
#define kNotificationNewTopicComments    @"ScringoChatRoomsNewTopicCommentsNotification"
#define kNotificationTopicCommentsViewed @"ScringoChatRoomsTopicCommentsViewedNotification"

@class ScringoChatRoom;

typedef void (^ScringoChatRoomGetChatRoomCompletionBlk)(ScringoChatRoom *chatRoom, BOOL isSuccess);
typedef void (^ScringoChatRoomGetCommentsCompletionBlk)(ScringoChatRoom *chatRoom, NSArray *comments, BOOL isSuccess);

@interface ScringoChatRoom : NSObject
+(void)getChatRoomByTopicId:(int)topicId completion:(ScringoChatRoomGetChatRoomCompletionBlk)completion;

@property (nonatomic, readonly) int topicId;
@property (nonatomic, readonly) int commentsNumber;
@property (nonatomic, readonly) int likesNumber;
@property (nonatomic, readonly) BOOL isRemoved;
@property (nonatomic, readonly) BOOL isAdhoc; /* i.e. not created in the devzone */
@property (nonatomic, assign, readonly) NSDate *dateTime;
@property (nonatomic, assign) NSString *title;
@property (nonatomic, assign) NSString *text;
@property (nonatomic, assign) NSString *photoUrl;
@property (nonatomic, assign, readonly) ScringoUser *user;

-(BOOL)hasPhoto;

-(NSArray *)getComments;
-(void)getPreviousComments:(int)commentId completion:(ScringoChatRoomGetCommentsCompletionBlk)completion;

// EGEG missing (Wed. evening)
/*
 - Same for chat (+ notification)
 - Same for message (+ notification)
 - Notification on Like (+ API)
 */

@end
