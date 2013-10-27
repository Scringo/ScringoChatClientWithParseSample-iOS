//
//  ScringoAds.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ScringoAds : NSObject

+(BOOL)isPopInAdsEnabled;
+(void)showPopInAdNow;
+(void)disablePopInAds:(BOOL)disablePopInAds;
+(void)disableSideBarAds:(BOOL)disableSideBarAds;


@end
