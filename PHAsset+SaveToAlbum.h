//
//  PHAsset+SaveToAlbum.h
//  RCToolsVideo
//
//  Created by Zakk Hoyt on 9/22/14.
//  Copyright (c) 2014 Zakk Hoyt. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __IPHONE_8_0
@import Photos;
#endif

typedef void (^PHAssetBoolBlock)(BOOL success);

@interface PHAsset (SaveToAlbum)
// Create album if it doesn't exist then add PHAsset (self) to it.
-(void)saveToAlbum:(NSString*)album completionBlock:(PHAssetBoolBlock)completionBlock NS_AVAILABLE_IOS(8_0);
@end
