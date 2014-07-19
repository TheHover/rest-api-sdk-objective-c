//
//  UserFile.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 07/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Response.h"
#import "ClientDELETE.h"
#import <UIKit/UIKit.h>
#import "SharedData.h"

@interface UserFile : NSObject


/*!Upload anything file to server it can be file or image. Yo need put specific type (file or image).
 *
 * \param NSData file: representation of file
 * \param NSString name: name of file
 * \param NSString type: type of file (file, image)
 *
 * \return a response instance with the http status code and the body decoded as NSDictionary
 *   is returned on given completion handler.
 */
+ (void) uploadFile:(void (^)(Response *))block WithData:(NSData *) data andName:(NSString *)name ofType:(NSString *)type;


/*!Add a photo to user profile
 *
 * \param NSString file_id: photo id of user
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) deleteFile:(void (^)(Response *))block WithFileID:(NSString *) idFile;

@end