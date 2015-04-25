A category to simplify a few tasks for the PHAsset class. 

Sample usage for saving an asset to an album (will create):

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

Sample usage for getting metadata from an asset

```
PHAsset *asset = // however you are getting your PHAsset
[asset requestMetadataWithCompletionBlock:^(NSDictionary *metadata) {
    NSLog(@"Metadata: %@", metadata);
}];
```

Sample: Save an image to camera roll (returns PHAsset in completion block)

```
UIImage *image = [UIImage imageNamed:@"terribleImage"];
[PHAsset saveImageToApplicationAlbum:image location:nil completionBlock:^(PHAsset *asset, BOOL success) {
    NSLog(@"asset saved to camera roll");
}];
```

Save video to camera roll (returns PHAsset in completion block)

```
NSURL *url = [NSURL urlWithString:@"terribleURL"];
[PHAsset saveVideoAtURL:videoFileURL location:nil completionBlock:^(PHAsset *asset, BOOL success) {
    NSLog(@"asset saved to camera roll");
}];
```



