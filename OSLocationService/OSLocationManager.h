//
//  OSLocationManager.h
//  OSLocationService
//
//  Created by Shrikantreddy Tekale on 25/09/2015.
//  Copyright © 2015 Ordnance Survey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OSLocationManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Different frequency options for location updates
 */
typedef NS_ENUM(NSInteger, OSLocationUpdatesFrequency) {
    /**
     *  Low frequency updates at 100 meters with minimum accuracy of 10 meters
     */
    OSLocationUpdatesFrequencyLow,
    /**
     *  Medium frequency updates at 40 meters with minimum accuracy of 25 meters
     */
    OSLocationUpdatesFrequencyMedium,
    /**
     *  High frequency updates at 10 meters with minimum accuracy of 40 meters
     */
    OSLocationUpdatesFrequencyHigh,
    /**
     *  Custom frequency updates. Use `distanceFilter` amd `desiredAccuracy` propererites to set desired values.
     */
    OSLocationUpdatesFrequencyCustom
};

/**
 *  Different update options for location and heading
 */
typedef NS_OPTIONS(NSUInteger, OSLocationServiceUpdateOptions) {
    /**
     *  Receive no updates
     */
    OSLocationServiceNoUpdates = 0,
    /**
     *  Receive only location change updates
     */
    OSLocationServiceLocationUpdates = 1 << 0,
    /**
     *  Receive only heading change updates
     */
    OSLocationServiceHeadingUpdates = 1 << 1,
    /**
     *  Receive both location and heading change updates
     */
    OSLocationServiceAllOptions = OSLocationServiceLocationUpdates | OSLocationServiceHeadingUpdates
};

/**
 * Wrapper around core location
 */
@interface OSLocationManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Convenience initialiser with `OSLocationUpdatesFrequency` update frequency
 *
 *  @param delegate the delegate to receive callback
 *
 *  @return instance of `OSLocationManager`
 */
- (instancetype)initWithDelegate:(id<OSLocationManagerDelegate>)delegate;

/**
 *  Designated initialiser
 *
 *  @param delegate  the delegate to receive callback
 *  @param frequency the frequency for the updates
 *
 *  @return instance of `OSLocationManager`
 */
- (instancetype)initWithDelegate:(id<OSLocationManagerDelegate>)delegate frequency:(OSLocationUpdatesFrequency)frequency NS_DESIGNATED_INITIALIZER;

/**
 *  Starts location service updates
 *
 *  @param options the different updates needed
 */
- (void)startLocationServiceUpdatesWithOptions:(OSLocationServiceUpdateOptions)options;

/**
 *  Stops current location service updates
 */
- (void)stopLocationserviceUpdates;

/**
 *  Specifies the minimum update distance in meters
 */
@property (assign, nonatomic) CLLocationDistance distanceFilter;

/**
 *  The desired location accuracy
 */
@property (assign, nonatomic) CLLocationAccuracy desiredAccuracy;

@end

NS_ASSUME_NONNULL_END