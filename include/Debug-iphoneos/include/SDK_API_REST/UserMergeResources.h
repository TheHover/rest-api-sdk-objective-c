//
//  UserMergeResources.h
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Response.h"
#import "MergeParameters.h"
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "ClientGET.h"

@interface UserMergeResources : NSObject

/*!Merge users for avoid duplicates, selecting by similiarities, one of the user must be the main user, the rest of users are merge. If a user is not merge with another then the state of merge is free. All data are required.
 *      branch_id, main_user_id, users_id
 *
 * \param MergeParameters class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code,
 *   is returned on given completion handler.
 */
+ (void) mergeUsers:(void (^)(Response *))block withParameters:(MergeParameters *) userParameters;

/*!You can use this resource to change the main user in a group of merged users, for delete or append a user in the same group.
 *  The optional data is:
 *  new_main_user_id: The new main user of the merge group
 *
 * \param MergeParameters class representing the data to post. The data could be encoded as json format by the SDK
 *
 * \return a response instance with the http status code, is returned on given completion handler.
 */
+ (void) changeMainUser:(void (^)(Response *))block OfMergedUsers:(MergeParameters *) userParameters;


/*!To obtain the merge users information is necessary user_id parameter.
 *
 * \param NSString user_id : current user_id
 *
 * \return a response instance with the http status code and the body decoded as json and in a class translation,
 *         is returned on given completion handler.
 */
+ (void) getMergeUsersInformation:(void (^)(Response *))block withUserID:(NSString *) user_id;

@end
