### PHAsset+Utility
A category to simplify common PHAsset functions.

##### Note: This class assumes that you've already prompted for permissions like so:
```
[PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
    // This has happened
}];
```
Looking for a solution for permission prompting? Check out  [VWWPermissionKit](https://github.com/zakkhoyt/VWWPermissionKit)

##### Example usage

###### Sample: Save UIImage to camera roll with optional location (return PHAsset in completion block)
```
UIImage *image = [UIImage imageNamed:@"bestImageEver"];
[PHAsset saveImageToCameraRoll:image 
                      location:nil 
               completionBlock:^(PHAsset *asset, BOOL success) {
                   NSLog(@"asset saved to camera roll");
               }];
```

###### Sample: Save video (from NSURL) to camera roll (returns PHAsset in completion block)
```
NSURL *url = [NSURL urlWithString:@"bestURLEver"];
[PHAsset saveVideoAtURL:videoFileURL 
               location:nil 
        completionBlock:^(PHAsset *asset, BOOL success) {
            NSLog(@"asset saved to camera roll");
        }];
```


###### Sample: Assign a PHAsset to an Album (will create the album if it doesn't exist):
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
###### Sample: Alter the location and creation date of a PHAsset

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

###### Sample: Retrieve the REAL metadata for a PHAsset (Exif, GPS, PNG, Maker, etc...)
```
PHAsset *asset = // however you are getting your PHAsset
[asset requestMetadataWithCompletionBlock:^(NSDictionary *metadata) {
    NSLog(@"Metadata: %@", metadata);
}];
```

A metatdata dictionary can have subdictionaries broken into logical sections. See ImageIO framework for constant strings. 
```
//    {
//        ColorModel = RGB;
//        DPIHeight = 72;
//        DPIWidth = 72;
//        Depth = 8;
//        Orientation = 1;
//        PixelHeight = 2448;
//        PixelWidth = 3264;
//        ProfileName = "sRGB IEC61966-2.1";
//        "{Exif}" =     {
//            ApertureValue = "2.52606882168926";
//            BrightnessValue = "1.660732196589769";
//            ColorSpace = 1;
//            ComponentsConfiguration =         (
//                                               1,
//                                               2,
//                                               3,
//                                               0
//                                               );
//            CustomRendered = 2;
//            DateTimeDigitized = "2012:10:26 19:34:05";
//            DateTimeOriginal = "2012:10:26 19:34:05";
//            ExifVersion =         (
//                                   2,
//                                   2,
//                                   1
//                                   );
//            ExposureMode = 0;
//            ExposureProgram = 2;
//            ExposureTime = "0.05";
//            FNumber = "2.4";
//            Flash = 0;
//            FlashPixVersion =         (
//                                       1,
//                                       0
//                                       );
//            FocalLenIn35mmFilm = 33;
//            FocalLength = "4.13";
//            ISOSpeedRatings =         (
//                                       160
//                                       );
//            MeteringMode = 5;
//            PixelXDimension = 3264;
//            PixelYDimension = 2448;
//            SceneCaptureType = 0;
//            SensingMethod = 2;
//            ShutterSpeedValue = "4.321956769055745";
//            WhiteBalance = 0;
//        };
//        "{GPS}" =     {
//            Altitude = "28.28625472887768";
//            AltitudeRef = 0;
//            DateStamp = "2012:10:26";
//            ImgDirection = "142.1425389755011";
//            ImgDirectionRef = T;
//            Latitude = "37.79883333333333";
//            LatitudeRef = N;
//            Longitude = "122.4598333333333";
//            LongitudeRef = W;
//            TimeStamp = "02:34:05";
//        };
//        "{TIFF}" =     {
//            DateTime = "2012:10:26 19:34:05";
//            Make = Apple;
//            Model = "iPhone 5";
//            Orientation = 1;
//            ResolutionUnit = 2;
//            Software = "6.0";
//            XResolution = 72;
//            YResolution = 72;
//        };
//    }
```
