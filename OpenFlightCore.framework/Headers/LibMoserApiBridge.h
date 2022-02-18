//    Copyright (C) 2019 Parrot Drones SAS
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

#import <Foundation/Foundation.h>
#import <simd/simd.h>

#define MOSER_OG_H 100
#define MOSER_OG_V 30
#define MOSER_OG_VSIZE 0.3f

#define MOSER_DM_W 176
#define MOSER_DM_H 90

#define MOSER_THRESHOLD 80

#define MOSER_DISPARITY_MAX 100


@interface LibMoserApiBridge : NSObject {

    /// Disparity frame to process
    @public float *disparityframe;
}

-(instancetype)init;

/**
 update moser occupancy grid using the disparityframe, with love quaternion and droneorigin
 @param quat love quaternion
 @param origin drone position
 @param timestampNs time stamp
 */
-(int)updateFromDisparityFrameWithQuaternion:(float *)quat
                                      origin:(float[3])origin
                                 timestampNs:(const uint64_t)timestampNs;

/// return the grid's origin
-(simd_float3)getOrigin;

/// test is a voxel exists at point
-(BOOL)isVoxel: (simd_int3) point;

@end
