//
//  ScringoAds.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/2/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Centralize all API that is Ads related.
 */
@interface ScringoAds : NSObject

/** Return whether pop-in ads are enabled or not.
 
 @return True if pop-in ads are enabled, False otherwise.
 */
+(BOOL)isPopInAdsEnabled;
/** Asks to show a pop-in ad now.
 */
+(void)showPopInAdNow;
/** Disable or Enable pop-in ads.
 
 @param disablePopInAds True if pop-in ads should be disabled, False otherwise.
 */
+(void)disablePopInAds:(BOOL)disablePopInAds;
/** Disable or Enable sidebar ads.
 
 @param disableSideBarAds True if sidebar ads should be disabled, False otherwise.
 */
+(void)disableSideBarAds:(BOOL)disableSideBarAds;


@end
