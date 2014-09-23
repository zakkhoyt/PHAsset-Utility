//
//  PHAsset+SaveToAlbum.h
//  RCToolsVideo
//
//  Created by Zakk Hoyt on 9/22/14.
//  Copyright (c) 2014 Zakk Hoyt. All rights reserved.
//

@import Photos;

typedef void (^PHAssetBoolBlock)(BOOL success);

@interface PHAsset (SaveToAlbum)
// Create album if it doesn't exist then add PHAsset (self) to it.
-(void)saveToAlbum:(NSString*)album completionBlock:(PHAssetBoolBlock)completionBlock;
@end
