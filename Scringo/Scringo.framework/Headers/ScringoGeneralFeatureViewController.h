//
//  GeneralFeatureViewController.h
//  ScringoExample2
//
//  Created by Ofer Kalisky on 1/16/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Delegate for Scringo Features General view controller. */
@protocol ScringoGeneralFeatureViewControllerDelegate <NSObject>
/** Notify the delegate that the user clicked the back button. Usually means the user is expecting to get to the previous view. */
-(void)didClickBack;
/** Notify the delegate that the user clicked the close button. Usually means the user is exepcting the feature to close. */
-(void)didClose;
/** Notify the delegate that the user should get back to the first feature view. */
-(void)backToPanel;
/** Answer whether iPad popover is being used.
 @return True if iPad popover is being used. False otherwise.
 */
-(BOOL)isUsingPopover;
/** Answer whether the top panel should be hidden.
 @return True if top panel should be hidden. False otherwise.
 */
-(BOOL)isTopPanelHidden;
/** Answer whether the feature was opened as a standalone feature.
 @return True if feature was opened as a standalone feature. False otherwise.
 */
-(BOOL)isOpenedAsFeature;
@end

/** Scringo Features General view controller.
 
 This view controller serves as the basis for all of Scringo Feature view controllers.
 */
@interface ScringoGeneralFeatureViewController : UIViewController

/** Feature Delegate Object. */
@property (retain, nonatomic) id<ScringoGeneralFeatureViewControllerDelegate> featureTabDelegate;
/** Feature Title. */
@property (retain, nonatomic) NSString *titleText;

@end

