A category to simplify common PHAsset functions (Saving to camera roll, updating location, retreiving metatdata)

Sample: Save UIImage to camera roll with optional location (return PHAsset in completion block)
```
UIImage *image = [UIImage imageNamed:@"bestImageEver"];
[PHAsset saveImageToCameraRoll:image 
                      location:nil 
               completionBlock:^(PHAsset *asset, BOOL success) {
                   NSLog(@"asset saved to camera roll");
               }];
```

Sample: Save video (from NSURL) to camera roll (returns PHAsset in completion block)
```
NSURL *url = [NSURL urlWithString:@"bestURLEver"];
[PHAsset saveVideoAtURL:videoFileURL 
               location:nil 
        completionBlock:^(PHAsset *asset, BOOL success) {
            NSLog(@"asset saved to camera roll");
        }];
```


Sample: Assign a PHAsset to an Album (will create the album if it doesn't exist):
```
PHAsset *asset = // however you are getting your PHAsset
[asset saveToAlbum:@"My App Album" completionBlock:^(BOOL success) {
    if(success){
        // Your asset now resides in My App Album
    } else {
        // Something bad happened. Handle it here.
    }
}];
```

Sample: Retrieve the REAL metadata for a PHAsset (Exif, GPS, PNG, Maker, etc...)
```
PHAsset *asset = // however you are getting your PHAsset
[asset requestMetadataWithCompletionBlock:^(NSDictionary *metadata) {
    NSLog(@"Metadata: %@", metadata);
}];
```

Sample: Alter the location and creation date of a PHAsset

```
CLLocation *location = [[CLLocation alloc]initWithLatitude:37.5 longitude:-122];
NSDate *date = [NSDate date];
[asset updateLocation:location creationDate:date completionBlock:^(BOOL success) {
    if(success){
        // Asset has new location and date
    } else {
        // Something bad happened. Handle it here.
    }
}];
```

Note: This class assumes that you've already prompted for permissions like so:
```
[PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
    // This has happened
}];
```

Looking for an easy way to get users to allow permissions? Check out [VWWPermissionKit](https://github.com/zakkhoyt/VWWPermissionKit)
