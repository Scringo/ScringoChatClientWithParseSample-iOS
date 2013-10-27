//
//  ScringoLikeButton.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 1/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    SCRINGO_APP_LIKE_NONE = 0,
    SCRINGO_APP_LIKE_IMAGE = 1,
    SCRINGO_APP_LIKE_VIDEO = 2,
    SCRINGO_APP_LIKE_POST = 3,
    SCRINGO_APP_LIKE_OTHER = 6
}  ScringoAppLikeObjectType;

@class ScringoLikeObject;
@class ScringoFeedMessage;
@class ScringoChatRoomsComment;
@class ScringoChatRoomsTopic;

@protocol ScringoLikeButtonDelegate
-(void)likeObject:(ScringoLikeObject *)likeObject withData:(NSString *)data newMode:(BOOL)mode;
@end

@interface ScringoLikeButton : UIButton {
    BOOL likeObjectIsReady;
}

@property (nonatomic, assign) id<ScringoLikeButtonDelegate> delegate;
@property (nonatomic, retain) IBOutlet UIView *topLevelView;
@property (nonatomic, retain) IBOutlet UIButton *likeOnButton;
@property (nonatomic, retain) IBOutlet UIButton *likeOffButton;
@property (nonatomic, retain) ScringoLikeObject *likeObject;

-(IBAction)likeOnTapped:(id)sender;
-(IBAction)likeOffTapped:(id)sender;
-(void)updateLikeObject:(ScringoLikeObject *)aLikeObject;
-(void)updateLikeObjectFromFeed:(ScringoFeedMessage *)aFeedMessage;
-(void)updateLikeObjectFromChatRoomsWithComment:(ScringoChatRoomsComment *)aChatRoomsComment;
-(void)updateLikeObjectFromChatRoomsWithTopic:(ScringoChatRoomsTopic *)aChatRoomsTopic;
-(void)updateLikeObject:(NSString *)data type:(ScringoAppLikeObjectType)type description:(NSString *)description;

@end
