//
//  AppDelegate.m
//  SampleWithParse
//
//  Created by Ofer Kalisky on 10/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "AppDelegate.h"
#import "MainTableViewController.h"

#import <Scringo/Scringo.h>
#import <Scringo/ScringoUser.h>

#import <Parse/Parse.h>
@implementation AppDelegate

- (void)dealloc
{
    [_window release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [Parse setApplicationId:@"YOUR PARSE APP ID" clientKey:@"YOUR PARSE CLIENT ID"];

    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[[MainTableViewController alloc] init]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    [Scringo initWithAppId:@"YOUR SCRINGO APP ID" completion:^{
        PFUser *currentUser = [PFUser currentUser];
        if (currentUser.isAuthenticated) {
            if (! [ScringoUser currentUser].isAuthenticated) {
                [ScringoUser signUpWithEmail:currentUser.email userName:currentUser.username password:@"Notimportant" completion:^(ScringoUser *aUser, BOOL isSuccess) {
                    if (isSuccess) {
                        [currentUser setObject:aUser.userId forKey:@"ScringoUserId"];
                        [currentUser saveInBackground];
                    }
                }];
            }
        }
    }];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
