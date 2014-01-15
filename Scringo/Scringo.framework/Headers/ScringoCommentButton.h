//
//  ScringoCommentButton.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 11/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ScringoChatRoom.h"

/** Defines possible Comment Object types. */
typedef NS_ENUM(NSUInteger, ScringoAppCommentObjectType) {
    /** Image Comment Object type */
    SCRINGO_APP_COMMENT_IMAGE = 0,
    /** Video Comment Object type */
    SCRINGO_APP_COMMENT_VIDEO = 1,
    /** Text Comment Object type */
    SCRINGO_APP_COMMENT_TEXT = 2,
    /** HTML Comment Object type */
    SCRINGO_APP_COMMENT_HTML = 3
};

/** Delegate for Scringo's Comment Button.
 */
@protocol ScringoCommentButtonDelegate <NSObject>
/** Notifies the delegate the comment button was clicked.
 
 @param topicId The Id of the Chat Room that was created for the Comment Object Id.
 @param objectId The Id of the Comment Button Object.
 */
-(void)commentButtonClicked:(int)topicId withObjectId:(NSString *)objectId;
@end

@class ScringoLikeObject;

/** Represent Scringo's Comment Button.
 
 The Scringo Comment Button allows you to create chat rooms for almost any content in your app. The Comment button should appear on top of your content and clicking it will automatically open a chat room dedicated to defined content, be it an image or video.
 The Scringo Comment button can be added by editing a XIB file in the interface builder (choose UIButton and change its class to ScringoCommentButton) or programmatically
 
 */
@interface ScringoCommentButton : UIButton

/** Comment Button delegate */
@property (nonatomic, assign) id<ScringoCommentButtonDelegate> delegate;
/** Should Scringo's Navigation bar be used by the Chat Room opened when clicking the button. */
@property (nonatomic, assign) BOOL scringoNavControllerEnabled;
/** The Navigation controller to be used to push the Chat Room opened when clicking the button. If nil, the Chat Room will be opened MODALLY. */
@property (nonatomic, retain) UINavigationController *navController;

/** Comment object Chat Room Id */
@property (nonatomic, assign, readonly) int topicId;
/** Comment object Id */
@property (nonatomic, retain, readonly) NSString *objectId;
/** Comment object type */
@property (nonatomic, assign, readonly) ScringoAppCommentObjectType objectType;
/** Comment object title */
@property (nonatomic, retain, readonly) NSString *title;
/** Comment object data */
@property (nonatomic, retain, readonly) NSString *data;

/**---------------------------------------------------------------------------------------
 * @name Initializing & Setting Content to chat about
 *  ---------------------------------------------------------------------------------------
 */

/** Initialize a UI-less Comment button.
 
 The main purpose of this method is to allow developers to create and use their own UI objects for the Comment button.
 @return Scringo Comment button instance with no UI elements.
 */
-(id)initWithoutUI;

/** Update the Comment button with an Image object.
 
 @param data Image URL.
 @param title Text to describe the Image.
 @param completionBlk The completion block to execute when the operation ends, with the resulting Chat Room object.
 */
-(void)updateImageCommentObject:(NSString *)data withTitle:(NSString *)title withCompletionBlk:(ScringoGetChatRoomCompletionBlk)completionBlk;
/** Update the Comment button with a Video object.
 
 @param data Video URL.
 @param title Text to describe the Video.
 @param completionBlk The completion block to execute when the operation ends, with the resulting Chat Room object.
 */
-(void)updateVideoCommentObject:(NSString *)data withTitle:(NSString *)title withCompletionBlk:(ScringoGetChatRoomCompletionBlk)completionBlk;
/** Update the Comment button with a Text object.
 
 @param objectId The object Id.
 @param title Text to describe the object text.
 @param text Object Text.
 @param completionBlk The completion block to execute when the operation ends, with the resulting Chat Room object.
 */
-(void)updateTextCommentObject:(NSString *)objectId withTitle:(NSString *)title withText:(NSString *)text withCompletionBlk:(ScringoGetChatRoomCompletionBlk)completionBlk;
/** Update the Comment button with an HTML object.
 
 @param objectId The object Id.
 @param title Text to describe the HTML.
 @param html The HTML string.
 @param completionBlk The completion block to execute when the operation ends, with the resulting Chat Room object.
 */
-(void)updateHtmlCommentObject:(NSString *)objectId withTitle:(NSString *)title withHtml:(NSString *)html withCompletionBlk:(ScringoGetChatRoomCompletionBlk)completionBlk;

/** Imitate a click on the Comment Button.
 
 Causes the adequate Chat Room to open. The way it will open is according to preset attributes: navController and scringoNavControllerEnabled.
 */
-(void)click;

/** Force a refresh on the Comment Object.
 
 Causes the button to refresh its data from the server.
 */
-(void)refresh;

@end
