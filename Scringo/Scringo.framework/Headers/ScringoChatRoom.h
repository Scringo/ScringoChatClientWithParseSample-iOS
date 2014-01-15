//
//  ScringoChatRoom.h
//  Scringo
//
//  Created by Guy Federovsky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScringoUser.h"

#define kNotificationNewTopics           @"ScringoChatRoomsNewTopicsNotification"
#define kNotificationNewTopicComments    @"ScringoChatRoomsNewTopicCommentsNotification"
#define kNotificationTopicCommentsViewed @"ScringoChatRoomsTopicCommentsViewedNotification"

@class ScringoChatRoom;

typedef void (^ScringoGetChatRoomCompletionBlk)(ScringoChatRoom *chatRoom, BOOL isSuccess);
typedef void (^ScringoGetChatRoomCommentsCompletionBlk)(ScringoChatRoom *chatRoom, NSArray *comments, BOOL isSuccess);

/** Represents a single Chat Room.
 */
@interface ScringoChatRoom : NSObject

/** The Chat Room Id.
 */
@property (nonatomic, readonly) int topicId;
/** Number of comments in the Chat Room.
 */
@property (nonatomic, readonly) int commentsNumber;
/** Number of likes the Chat Room received.
 */
@property (nonatomic, readonly) int likesNumber;
/** Is the Chat Room marked for deletion.
 */
@property (nonatomic, readonly) BOOL isRemoved;
/** Is the Chat Room an ad-hoc one (not defined in Scringo's developers zone).
 */
@property (nonatomic, readonly) BOOL isAdhoc; /* i.e. not created in the devzone */
/** The date and time in which the Chat Room was last modified.
 */
@property (nonatomic, assign, readonly) NSDate *dateTime;
/** The user that created the Chat Room.
 
 @see ScringoUser
 */
@property (nonatomic, assign, readonly) ScringoUser *user;

/** The Chat Room title.
 */
@property (nonatomic, assign) NSString *title;
/** The Chat Room content.
 */
@property (nonatomic, assign) NSString *text;
/** The Chat Room attached Photo.
 */
@property (nonatomic, assign) NSString *photoUrl;

/**---------------------------------------------------------------------------------------
 * @name Obtaining a Chat Room
 *  ---------------------------------------------------------------------------------------
 */

/** Retrieve a Chat Room given its topic Id.
 
 @param topicId The Id of the Chat Room.
 @param completion The completion block to execute when the operation ends.
 */
+(void)getChatRoomByTopicId:(int)topicId completion:(ScringoGetChatRoomCompletionBlk)completion;

/**---------------------------------------------------------------------------------------
 * @name Accessors
 *  ---------------------------------------------------------------------------------------
 */

/** Checks whether Chat Room has an image.
 
 @return True if an image is defined for the Chat Room, False otherwise.
 */
-(BOOL)hasPhoto;

/** Retrieve latest comments from the Chat Room.
 
 @return An ordered Array of the latest ScringoChatRoomComment objects.
 */
-(NSArray *)getComments;
/** Retrieves the previous set of comments from the Chat Room.
 
 @param commentId The earliest comment Id available.
 @param completion The block to execute when comments are fetched.
 */
-(void)getPreviousComments:(int)commentId completion:(ScringoGetChatRoomCommentsCompletionBlk)completion;

/**---------------------------------------------------------------------------------------
 * @name Opening a Chat Room
 *  ---------------------------------------------------------------------------------------
 */

/** Open the Chat Room.
 
 @param navController The navigation controller to which the chat room will be pushed. If nil, the chat room will present as MODAL.
 @param scringoNavBarEnabled Whether to enable Scrigno's navigation bar or not.
 */
-(void)openWithNavigationController:(UINavigationController *)navController usingScringoNavBar:(BOOL)scringoNavBarEnabled;

@end
