//
//  PHAsset+Utilities.h
//
//  Created by Zakk Hoyt on 9/22/14.
//  Copyright (c) 2014 Zakk Hoyt. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __IPHONE_8_0
@import Photos;
#endif

typedef void (^PHAssetBoolBlock)(BOOL success);
typedef void (^PHAssetMetadataBlock)(NSDictionary *metadata);

@interface PHAsset (Utilities)
-(void)saveToAlbum:(NSString*)album completionBlock:(PHAssetBoolBlock)completionBlock;
-(void)requestMetadataWithCompletionBlock:(PHAssetMetadataBlock)completionBlock;
@end
