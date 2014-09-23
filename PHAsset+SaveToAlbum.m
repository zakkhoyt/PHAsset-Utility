//
//  PHAsset+SaveToAlbum.m
//  RCToolsVideo
//
//  Created by Zakk Hoyt on 9/22/14.
//  Copyright (c) 2014 Zakk Hoyt. All rights reserved.
//

#import "PHAsset+SaveToAlbum.h"
@import Photos;

@implementation PHAsset (SaveToAlbum)

-(PHAssetCollection*)albumWithTitle:(NSString*)title{
    
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"localizedTitle = %@", title];
    PHFetchOptions *options = [[PHFetchOptions alloc]init];
    options.predicate = predicate;
    PHFetchResult *result = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeAlbum subtype:PHAssetCollectionSubtypeAny options:options];
    if(result.count){
        return result[0];
    }
    return nil;
    
}

-(void)saveToAlbum:(NSString*)title completionBlock:(PHAssetBoolBlock)completionBlock{
    
    void (^saveAssetCollection)(PHAssetCollection *assetCollection) = ^(PHAssetCollection *assetCollection){
        [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
            PHAssetCollectionChangeRequest *changeRequest = [PHAssetCollectionChangeRequest changeRequestForAssetCollection:assetCollection];
            [changeRequest addAssets:@[self]];
        } completionHandler:^(BOOL success, NSError *error) {
            if(success == NO) {
                NSLog(@"Failed to add PHAsset to album: %@ error: %@", title, error.localizedDescription);
            }
            return completionBlock(success);
        }];
    };
    
    // Check if album exists. If not, create it.
    PHAssetCollection *assetCollection = [self albumWithTitle:title];
    
    if(assetCollection){
        // Album exists
        saveAssetCollection(assetCollection);
    } else {
        // Need to create album before saving
        // Create new album (will create duplicates)
        [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
            [PHAssetCollectionChangeRequest creationRequestForAssetCollectionWithTitle:title];
        } completionHandler:^(BOOL success, NSError *error) {
            if (!success) {
                NSLog(@"Error creating album: %@", error);
            } else {
                // Now that we've created the album, get a reference to it
                PHAssetCollection *assetCollection = [self albumWithTitle:title];
                saveAssetCollection(assetCollection);
            }
            
            
        }];
    }
}

@end
