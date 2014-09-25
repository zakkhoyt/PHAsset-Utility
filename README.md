A category to quickly/easily save a PHAsset to an Album. 

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

