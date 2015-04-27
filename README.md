A category to simplify a few tasks for the PHAsset class. 

Sample usage for saving an PHAsset to an album (will create the album if it doesn't exist):

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

Sample usage for getting metadata from a PHAsset

```
PHAsset *asset = // however you are getting your PHAsset
[asset requestMetadataWithCompletionBlock:^(NSDictionary *metadata) {
    NSLog(@"Metadata: %@", metadata);
}];
```

Sample: Save a UIImage to camera roll (returns PHAsset in completion block)

```
UIImage *image = [UIImage imageNamed:@"terribleImage"];
[PHAsset saveImageToApplicationAlbum:image 
                            location:nil 
                     completionBlock:^(PHAsset *asset, BOOL success) {
                        NSLog(@"asset saved to camera roll");
                     }];
```

Save video (from NSURL) to camera roll (returns PHAsset in completion block)

```
NSURL *url = [NSURL urlWithString:@"terribleURL"];
[PHAsset saveVideoAtURL:videoFileURL 
               location:nil 
        completionBlock:^(PHAsset *asset, BOOL success) {
            NSLog(@"asset saved to camera roll");
        }];
```



