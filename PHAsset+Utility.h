//
//  PHAsset+Utilities.h
//
//  Created by Zakk Hoyt on 9/22/14.
//  Copyright (c) 2014 Zakk Hoyt. All rights reserved.
//




#import <Foundation/Foundation.h>

@import Photos;

typedef void (^PHAssetBoolBlock)(BOOL success);
typedef void (^PHAssetMetadataBlock)(NSDictionary *metadata);
typedef void (^PHAssetAssetBoolBlock)(PHAsset *asset, BOOL success);

@interface PHAsset (Utilities)

// Save a copy of a PHAsset to a specific album
-(void)saveToAlbum:(NSString*)title completionBlock:(PHAssetBoolBlock)completionBlock;

// Get metadata dictionary of an asset (the kind with {Exif}, {GPS}, etc...
-(void)requestMetadataWithCompletionBlock:(PHAssetMetadataBlock)completionBlock;

//    // Save an image to camera roll (returns PHAsset in completion block)
//    UIImage *image = [UIImage imageNamed:@"terribleImage"];
//    [PHAsset saveImageToApplicationAlbum:image location:nil completionBlock:^(PHAsset *asset, BOOL success) {
//        NSLog(@"asset saved to camera roll");
//    }];
+(void)saveImageToApplicationAlbum:(UIImage*)image location:(CLLocation*)location completionBlock:(PHAssetAssetBoolBlock)completionBlock;

//    // Save video to camera roll (returns PHAsset in completion block)
//    NSURL *url = [NSURL urlWithString:@"terribleURL"];
//    [PHAsset saveVideoAtURL:videoFileURL location:nil completionBlock:^(PHAsset *asset, BOOL success) {
//        NSLog(@"asset saved to camera roll");
//    }];
+(void)saveVideoAtURL:(NSURL*)url location:(CLLocation*)location completionBlock:(PHAssetAssetBoolBlock)completionBlock;
@end


