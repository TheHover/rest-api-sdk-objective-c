//  ClientGET.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "SharedData.h"

/**
 * Creates a correct GET HTTP request using query string as API needs.
 */
@interface ClientGET : NSObject


/*!Execute the GET HTTP request building previously with the attributes
 *  passed into this class constructor.
 *
 * \param query string to make request
 * \param uri to specific service
 *
 * \return status code, body response and if error exist this parameters will not nil. All of them is returned on given completion handler.
 */
+ (void) getRequestWithURLParameters:(void (^)(NSData *responseBody, NSError *error, NSInteger statusCode))block parametersURL:(NSDictionary *)urlQueryStringParameters andURI:(NSString *) uri;


@end
