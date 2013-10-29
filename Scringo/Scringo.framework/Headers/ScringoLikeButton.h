//
//  ScringoLikeButton.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 1/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Defines possible Like Object types. */
typedef NS_ENUM(NSUInteger, ScringoAppLikeObjectType) {
    /** No type - shouldn't be used!! */
    SCRINGO_APP_LIKE_NONE = 0,
    /** Image Like Object type */
    SCRINGO_APP_LIKE_IMAGE = 1,
    /** Video Like Object type */
    SCRINGO_APP_LIKE_VIDEO = 2,
    /** Activity Feed Like Object type */
    SCRINGO_APP_LIKE_POST = 3,
    /** Other, not yet defined Like Object type */
    SCRINGO_APP_LIKE_OTHER = 6
};

@class ScringoLikeObject;

/** Delegate for Scringo's Like Button.
 */
@protocol ScringoLikeButtonDelegate
/** Notifies a change of state.
 
 Notifies the delegate that the like object that the button represents has changed its mode.

 @param likeObject The like button object.
 @param data The like button data.
 @param mode True if button is in 'Like' mode. False otherwise.
 */
-(void)likeObject:(ScringoLikeObject *)likeObject withData:(NSString *)data newMode:(BOOL)mode;
@end

/** Represents Scringo's Like Button.
 
 The Scringo Like Button allows your users to like and comment almost any content in your app. The Like button should appear on top of your content (image, video, article) and clicking it will automatically increase the number of likes counter. Liked objects will also automatically appear in your app's Activity screen, allowing your users to share them via Facebook, Twitter & Email. The Scringo Like button can be added by editing a XIB file in the interface builder (choose a UIButton and change its class to ScringoLikeButton) or programmatically.
 
 */
@interface ScringoLikeButton : UIButton

/** Like Button delegate. */
@property (nonatomic, assign) id<ScringoLikeButtonDelegate> delegate;

/** Update Button with details.
 
 Set the internal like object with details.
 
 @param data The like object data, usually an image URL.
 @param type The like object data type.
 @param description Textual description of the like object data.
 */
-(void)updateLikeObject:(NSString *)data type:(ScringoAppLikeObjectType)type description:(NSString *)description;

@end
