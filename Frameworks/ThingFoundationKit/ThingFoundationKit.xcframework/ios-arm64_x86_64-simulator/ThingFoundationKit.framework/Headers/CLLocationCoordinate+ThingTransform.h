//
//  CLLocationCoordinate+ThingTransform.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/5/16.
//



#import <CoreLocation/CLLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 GCJ-02: Chinese Geodetic Coordinate System (Mars Coordinates)
 A geodetic datum formulated by the Chinese State Bureau of Surveying and Mapping. Primarily used within China for civilian positioning data.

 BD-09: Baidu Maps Coordinate System
 A geographic coordinate system used by Baidu Maps, known for offsetting GCJ-02 coordinates for use in its services.

 WGS84: World Geodetic System 1984
 The global reference system for geospatial positioning, used most widely in global GPS systems.
 */

/**
 convert WGS84 to GCJ02 if in China
 */
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateWGS84ToGCJ02(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateGCJ02ToWGS84(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateWGS84ToBD09(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateGCJ02ToBD09(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateBD09ToGCJ02(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D Thing_CoordinateBD09ToWGS84(CLLocationCoordinate2D location);

NS_ASSUME_NONNULL_END
