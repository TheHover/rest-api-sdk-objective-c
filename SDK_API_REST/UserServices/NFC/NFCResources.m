//
//  NFCResources.m
//  SDK_API_REST
//
//  Created by Eder Gomez Nocelo on 04/07/14.
//  Copyright (c) 2014 Hova Networks. All rights reserved.
//

#import "NFCResources.h"

@implementation NFCResources

+(void)assignNFCtoUser:(void (^)(Response *))block withParameters:(NFCParameters *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/nfc_card";
    
    [ClientPOST postRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];

}

+(void)updateNFCtoUser:(void (^)(Response *))block withParameters:(NFCParameters *)parameters{

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[parameters toDictionary] options:kNilOptions error:&error];
    NSString *uri=@"/v1/user/nfc_card";

    [ClientPUT putRequestWithBODYParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            block(resp);
        }else
            block(nil);
        
    } body:jsonData andURI:uri];
    
}

+(void)getNFCtoUser:(void (^)(Response *))block withUserID:(NSString *)userId{

    NSDictionary *param=[[NSDictionary alloc] initWithObjectsAndKeys:userId,@"user_id", nil];
    NSString *uri=@"/v1/user/nfc_card";
    
    [ClientGET getRequestWithURLParameters:^(NSData *responseBody, NSError *error, NSInteger statusCode){
    
        if(error==nil){
            NSError *error;
            NSDictionary *jsonDecode=[NSJSONSerialization JSONObjectWithData:responseBody options:kNilOptions error:&error];
            Response *resp=[[Response alloc] init];
            resp.statusCode=statusCode;
            resp.responseBody=responseBody;
            resp.responseBodyT=jsonDecode;
            block(resp);
        }else
            block(nil);
        
    } parametersURL:param andURI:uri];
    
}
@end
