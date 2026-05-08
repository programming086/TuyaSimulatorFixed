//
//  ThingLightSceneEnums.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

typedef enum {
    /// All scenes open
    ThingLightSceneTypeAllOn = 1,
    /// All scenes close
    ThingLightSceneTypeAllOff = 2,
    /// Custom scene
    ThingLightSceneTypeCustom = 3,
} ThingLightSceneType;


typedef enum {
    /// The function type of single lamp
    ThingLightSceneFunctionTypeSingle = 0, 
    /// The function type of group lamp
    ThingLightSceneFunctionTypeGroup = 1, 
} ThingLightSceneFunctionType;



typedef enum {
    /// Preview the single lamp
    ThingLightScenePreviewTypeSingle = 1, 
    /// Preview multiple lights
    ThingLightScenePreviewTypeMuti = 2, 
    /// Preview the group lamp
    ThingLightScenePreviewTypeGroup = 3,
    /// Preview the property lamps
    ThingLightScenePreviewTypeProperty = 5,
} ThingLightScenePreviewType;




