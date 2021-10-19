//
//  PhotoPanoView.h
//  PhotoPanoView
//

#import <GLKit/GLKit.h>
#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

/** FOV control for a viewer. */
typedef NS_ENUM(NSInteger, PhotoPanoViewFovControl) {
    // Numerical values must be kept in sync with C code (ViewerFovControl)

    /** FOV control also affects projection type. */
    PhotoPanoViewFovControlFull = 0,

    /** FOV control always follows rectilinear projection. */
    PhotoPanoViewFovControlRectilinear = 1,
};

/** Aspect ratio */
typedef NS_ENUM(NSInteger, PhotoPanoViewAspectRatio) {
    // Numerical values must be kept in sync with C code (ViewerAspectRatio)
    /**< 1:1 aspect ratio */
    PhotoPanoViewAspectRatio_1_1 = 0,

    /**< 4:3 aspect ratio */
    PhotoPanoViewAspectRatio_4_3,

    /**< 3:2 aspect ratio */
    PhotoPanoViewAspectRatio_3_2,

    /**< 16:9 aspect ratio */
    PhotoPanoViewAspectRatio_16_9,

    /**< 2:1 aspect ratio */
    PhotoPanoViewAspectRatio_2_1,
};

@class PhotoPanoDescription;

NS_ASSUME_NONNULL_BEGIN

@interface PhotoPanoView : GLKView
- (void)setup:(EAGLContext *) context fovControl:(PhotoPanoViewFovControl)fovControl gridDivisions:(int)gridDivisions;
- (void)setPanorama:(NSString *)path enableAnimation:(BOOL)enabled triggerAnimation:(BOOL)triggered;
- (void)triggerStartAnimation;
- (void)setQuaternion:(CMQuaternion)q orientation:(UIInterfaceOrientation)orientation;
- (void)touchDown;
- (void)touchUp;
- (void)startPan:(NSInteger)touchCount;
- (void)updatePan:(CGPoint)translation;
- (void)endPan;
- (void)startPinch;
- (void)updatePinch:(CGFloat) scale;
- (void)endPinch;
- (void)startRotation;
- (void)updateRotation:(CGFloat) angle;
- (void)endRotation;
- (void)doubleTap;
- (void)toggleAspectRatio;
- (void)setAspectRatio:(PhotoPanoViewAspectRatio)aspectRatio;
- (PhotoPanoDescription*)panoDescription;
@end

NS_ASSUME_NONNULL_END
