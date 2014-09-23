A category to quickly/easily save a PHAsset to an Album. 

Sample usage:



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
