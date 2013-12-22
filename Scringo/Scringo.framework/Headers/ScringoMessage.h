//
//  ScringoMessage.h
//  Scringo
//
//  Created by Guy Federovsky on 17/12/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "ScringoUser.h"

#define SCRINGO_MESSAGE_PLAIN       @"text/plain"
#define SCRINGO_MESSAGE_IMAGE       @"image"
#define SCRINGO_MESSAGE_STICKER     @"sticker"
#define SCRINGO_MESSAGE_HTML        @"text/html"
#define SCRINGO_MESSAGE_LINK        @"text/link"

/** Represents a single Chat Message.
 */
@interface ScringoMessage : NSObject

/** The User that sent the message.
 
 @see ScringoUser
 */
@property (nonatomic, assign, readonly) ScringoUser *sender;
/** The User the message was sent to.
 
 @see ScringoUser
 */
@property (nonatomic, assign, readonly) ScringoUser *otherUser;
/** The message.
 
 If content type is image, sticker or link the message will consist of a URL. Otherwise, the message is the actual message as written by the sender.
 */
@property (nonatomic, assign, readonly) NSString *message;
/** The message content type. */
@property (nonatomic, assign, readonly) NSString *contentType;
/** The date and time in which the message was sent. */
@property (nonatomic, assign, readonly) NSDate *time;

@end
