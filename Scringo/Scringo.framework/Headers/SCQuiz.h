//
//  SCQuiz.h
//  ScringoExample3
//
//  Created by Guy Federovsky on 4/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SCQuiz : NSObject

+(BOOL)isLockedForUser:(int)quizId;
+(NSString *)getName:(int)quizId;
+(NSString *)getDescription:(int)quizId;

@end
