//    Copyright (C) 2018 Parrot Drones SAS
//
//    Redistribution and use in source and binary forms, with or without
//    modification, are permitted provided that the following conditions
//    are met:
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
//    * Neither the name of the Parrot Company nor the names
//      of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written
//      permission.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
//    PARROT COMPANY BE LIABLE FOR ANY DIRECT, INDIRECT,
//    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
//    OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
//    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
//    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//    SUCH DAMAGE.

#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>

/** Processing status code */
typedef NS_ENUM(NSInteger, PhotoPanoPreset) {
    // Numerical values must be kept in sync with C++ code (enum MakerPreset)
    /** Spherical panorama. */
    PhotoPanoPresetSphere = 0,
    /** Little-planet panorama. */
    PhotoPanoPresetPlanet = 1,
    /** Tunnel panorama. */
    PhotoPanoPresetTunnel = 2,
    /** Horizontal panorama, 180° spherical 2:1. */
    PhotoPanoPresetHorizontal = 3,
    /** Vertical panorama, 70° recti 1:2. */
    PhotoPanoPresetVertical = 4,
    /** Spherical panorama optimized for fast rendering. */
    PhotoPanoPresetFastSphere = 5,
    /** Superwide panorama. */
    PhotoPanoPresetSuperWide = 6,
    /** Custom panorama. */
    PhotoPanoPresetCustom = 7,
};

/** Processing status code */
typedef NS_ENUM(NSInteger, PhotoPanoProcessingStatus) {
    // Numerical values must be kept in sync with C++ code (enum MakerStatus)
    /** Waiting */
    PhotoPanoProcessingStatusWaiting = 0,
    /** Estimating */
    PhotoPanoProcessingStatusEstimating = 1,
    /** Wrapping */
    PhotoPanoProcessingStatusWrapping = 2,
    /** Cutting */
    PhotoPanoProcessingStatusCutting = 3,
    /** Blending */
    PhotoPanoProcessingStatusBlending = 4,
    /** Cancelled */
    PhotoPanoProcessingStatusCancelled = 5,
    /** Failed */
    PhotoPanoProcessingStatusFailed = 6,
    /** Success */
    PhotoPanoProcessingStatusSuccess = 7,
};

/** Completion callback */
typedef void(^PhotoPanoProcessingStatusUpdate)(PhotoPanoProcessingStatus status);

/** define a PhotoPanoDescription */
@interface PhotoPanoDescription: NSObject
@property (nonatomic) CMQuaternion cam_to_world;
@property (nonatomic) float hfov_deg;
@property (nonatomic) float planet_factor;
@property (nonatomic) float planet_width;
@property (nonatomic) float planet_hcrop_factor;
@end

/** define a PhotoPano */
@interface PhotoPano : NSObject

/**
 * Process to create a panorama.
 *
 * Blocking function.
 *
 * @param preset presets of the panorama to create.
 * @param inputs Paths of input pictures
 * @param width width of the output picture to create
 * @param height height of the output picture to create
 * @param output path of the picture to create
 * @param estimationIn path to input json estimation file
 * @param estimationOut path to output json estimation file
 * @param description panorama description
 * @param statusUpdateBlock completion callback
 * @return ending status.
 *         Returns directly PhotoPanoProcessingStatusFailed if a process is already running.
 *
 * @see #abort()
 */
- (PhotoPanoProcessingStatus) processWithPreset:(PhotoPanoPreset)preset
                                         inputs:(NSArray*)inputs
                                          width:(int)width
                                         height:(int)height
                                         output:(NSURL*)output
                                   estimationIn:(NSURL*)estimationIn
                                  estimationOut:(NSURL*)estimationOut
                                    description:(PhotoPanoDescription*)description
                                   statusUpdate:(PhotoPanoProcessingStatusUpdate)statusUpdateBlock
NS_SWIFT_NAME(process(preset:inputs:width:height:output:estimationIn:estimationOut:description:statusUpdate:));


/**
 * Aborts the process.
 *
 * @see process()
 */
- (void) abort;

/**
 * Retrieves the percentage of the process progression.
 *
 * @return percentage of the current processing. {@code 0.0} if no process running.
 */
- (double) progress;

@end
