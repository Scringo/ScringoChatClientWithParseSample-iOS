//
//  ScringoChatRoomComment.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScringoUser.h"

@interface ScringoChatRoomComment : NSObject

@property (nonatomic, readonly) int commentId;
@property (nonatomic, readonly) int topicId;
@property (nonatomic, readonly) int likesNumber;
@property (nonatomic, assign, readonly) ScringoUser *user;
@property (nonatomic, assign, readonly) NSString *text;
@property (nonatomic, assign, readonly) NSDate *dateTime;


@end
