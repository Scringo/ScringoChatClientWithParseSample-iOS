//
//  RadarMapViewController.h
//  ScringoExample2
//
//  Created by Ofer Kalisky on 1/20/12.
//  Copyright (c) 2012 Ziggy Software. All rights reserved.
//

#import "ScringoGeneralFeatureViewController.h"

/** Radar map and list view controller.
 
 This view controller loads and controls the screen holding a map available users on it, allowing you to follow them, send the messages and more.
 */
@interface ScringoRadarMapViewController : ScringoGeneralFeatureViewController

/** Initialize the Radar map and list view.
 
 Initialize the Radar map and list view from its interface builder definition file.
 This object can later be pushed into an existing navigation controller, a container view controller or even modally.
 */
-(id)initFromNib;

@end
