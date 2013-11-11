//
//  GeneralFeatureViewController.h
//  ScringoExample2
//
//  Created by Ofer Kalisky on 1/16/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ScringoGeneralFeatureViewControllerDelegate <NSObject>
-(void)didClickBack;
-(void)didClose;
-(void)backToPanel;
-(BOOL)isUsingPopover;
-(BOOL)isTopPanelHidden;
-(BOOL)isOpenedAsFeature;
@end

@interface ScringoGeneralFeatureViewController : UIViewController

@property (retain, nonatomic) id<ScringoGeneralFeatureViewControllerDelegate> featureTabDelegate;
@property (retain, nonatomic) NSString *titleText;

@end

