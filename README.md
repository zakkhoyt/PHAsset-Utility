### PHAsset+Utility
A category to simplify common PHAsset functions.

---

### Photos Permission
##### Note: This class assumes that you've already obtained permission from the user like so:
```
[PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
    // copacetic...
}];
```
Looking for a solution for user permission prompting? Check out this framework: 

#####[VWWPermissionKit](https://github.com/zakkhoyt/VWWPermissionKit)

---

### About this category
```
/*!
 @method        saveToAlbum:completionBlock
 @description   Save a copy of a PHAsset to a photo album. Will create the album if it doesn't exist.
 @param         title                  The title of the album.
 @param         completionBlock        This block is passed a BOOL for success.  This parameter may be nil.
 */
-(void)saveToAlbum:(NSString*)title completionBlock:(PHAssetBoolBlock)completionBlock;

/*!
 @method        updateLocation:creationDate:completionBlock
 @description   Update the location and date of an existing asset
 @param         location               A CLLocation object to be written to the PHAsset. See CoreLocation framework for obtaining locations.
 @param         creationDate           An NSDate to be written to the PHAsset.
 @param         completionBlock        This block is passed the PHAsset updated with location/date (if applied) and BOOL for success. This parameter may be nil.
 */
-(void)updateLocation:(CLLocation*)location creationDate:(NSDate*)creationDate completionBlock:(PHAssetBoolBlock)completionBlock;

/*!
 @method        saveImageToCameraRoll:location:completionBlock
 @description   Save an image to camera roll with optional completion (returns PHAsset in completion block)
 @param         location               A CLLocation object to be written to the PHAsset. See CoreLocation framework for obtaining locations. This parameter may be nil.
 @param         creationDate           An NSDate to be written to the PHAsset.
 @param         completionBlock        Returns the PHAsset which was written and BOOL for success. This parameter may be nil.
 */
+(void)saveImageToCameraRoll:(UIImage*)image location:(CLLocation*)location completionBlock:(PHAssetAssetBoolBlock)completionBlock;

/*!
 @method        saveVideoAtURL:location:completionBlock
 @description   Save a video to camera roll with optional completion (returns PHAsset in completion block)
 @param         location               A CLLocation object to be written to the PHAsset. See CoreLocation framework for obtaining locations. This parameter may be nil.
 @param         creationDate           An NSDate to be written to the PHAsset.
 @param         completionBlock        Returns the PHAsset which was written and BOOL for success. This parameter may be nil.
 */
+(void)saveVideoAtURL:(NSURL*)url location:(CLLocation*)location completionBlock:(PHAssetAssetBoolBlock)completionBlock;

/*!
 @method        requestMetadataWithCompletionBlock
 @description   Get metadata dictionary of an asset (the kind with {Exif}, {GPS}, etc...
 @param         completionBlock        This block is passed a dictionary of metadata properties. See ImageIO framework for parsing/reading these. This parameter may be nil.
 */
-(void)requestMetadataWithCompletionBlock:(PHAssetMetadataBlock)completionBlock;
```

---

### Metadata

The metatdata dictionary returned from requestMetadataWithCompletionBlock will have subdictionaries broken into logical categories. Use Apple's ImageIO framework for parsing.

```
{
    ColorModel = RGB;
    DPIHeight = 72;
    DPIWidth = 72;
    Depth = 8;
    Orientation = 1;
    PixelHeight = 2448;
    PixelWidth = 3264;
    ProfileName = "sRGB IEC61966-2.1";
    "{Exif}" =     {
        ApertureValue = "2.52606882168926";
        BrightnessValue = "1.660732196589769";
        ColorSpace = 1;
        ComponentsConfiguration =         (
                                           1,
                                           2,
                                           3,
                                           0
                                           );
        CustomRendered = 2;
        DateTimeDigitized = "2012:10:26 19:34:05";
        DateTimeOriginal = "2012:10:26 19:34:05";
        ExifVersion =         (
                               2,
                               2,
                               1
                               );
        ExposureMode = 0;
        ExposureProgram = 2;
        ExposureTime = "0.05";
        FNumber = "2.4";
        Flash = 0;
        FlashPixVersion =         (
                                   1,
                                   0
                                   );
        FocalLenIn35mmFilm = 33;
        FocalLength = "4.13";
        ISOSpeedRatings =         (
                                   160
                                   );
        MeteringMode = 5;
        PixelXDimension = 3264;
        PixelYDimension = 2448;
        SceneCaptureType = 0;
        SensingMethod = 2;
        ShutterSpeedValue = "4.321956769055745";
        WhiteBalance = 0;
    };
    "{GPS}" =     {
        Altitude = "28.28625472887768";
        AltitudeRef = 0;
        DateStamp = "2012:10:26";
        ImgDirection = "142.1425389755011";
        ImgDirectionRef = T;
        Latitude = "37.79883333333333";
        LatitudeRef = N;
        Longitude = "122.4598333333333";
        LongitudeRef = W;
        TimeStamp = "02:34:05";
    };
    "{TIFF}" =     {
        DateTime = "2012:10:26 19:34:05";
        Make = Apple;
        Model = "iPhone 5";
        Orientation = 1;
        ResolutionUnit = 2;
        Software = "6.0";
        XResolution = 72;
        YResolution = 72;
    };
}
```
