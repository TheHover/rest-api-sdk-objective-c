//
//  UserGetParameters.m
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import "UserGetParameters.h"

@implementation UserGetParameters

+(BOOL)propertyIsOptional:(NSString *)propertyName{

    if ([propertyName isEqualToString: @"fmd"]) return YES;
    return NO;
    
}

@end
