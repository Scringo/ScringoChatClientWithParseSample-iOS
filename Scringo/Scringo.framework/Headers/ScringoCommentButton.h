//
//  ScringoCommentButton.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 11/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    SCRINGO_APP_COMMENT_IMAGE = 0,
    SCRINGO_APP_COMMENT_VIDEO = 1,
    SCRINGO_APP_COMMENT_LINK = 2,
    SCRINGO_APP_COMMENT_HTML = 3
}  ScringoAppCommentObjectType;

@protocol ScringoCommentButtonDelegate <NSObject>
-(void)commentButtonClicked:(int)topicId withObjectId:(NSString *)objectId;
@end

@class ScringoLikeObject;

@interface ScringoCommentButton : UIButton
@property (nonatomic, assign) id<ScringoCommentButtonDelegate> delegate;

@property (assign, nonatomic) BOOL scringoNavControllerEnabled;
@property (retain, nonatomic) UINavigationController *navController;

@property (nonatomic, assign, readonly) int topicId;
@property (nonatomic, retain, readonly) NSString *objectId;
@property (nonatomic, assign, readonly) ScringoAppCommentObjectType objectType;
@property (nonatomic, retain, readonly) NSString *title;
@property (nonatomic, retain, readonly) NSString *data;

@property (retain, nonatomic) IBOutlet UIView *topLevelView;
@property (retain, nonatomic) IBOutlet UIButton *commentButton;

-(void)updateCommentObject:(NSString *)objectId withType:(ScringoAppCommentObjectType)type withTitle:(NSString *)title withData:(NSString *)data;
-(void)updateImageCommentObject:(NSString *)data withTitle:(NSString *)title;
-(void)updateVideoCommentObject:(NSString *)data withTitle:(NSString *)title;
//-(void)updateLinkCommentObject:(NSString *)data withTitle:(NSString *)title;
//-(void)updateHtmlCommentObject:(NSString *)objectId withTitle:(NSString *)title withHtml:(NSString *)data;
-(void)updateCommentObjectWithLikeObject:(ScringoLikeObject *)likeObject;

-(void)refresh;

- (IBAction)commentClicked:(id)sender;
@end
