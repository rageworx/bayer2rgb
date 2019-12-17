#ifndef __BAYER_H__
#define __BAYER_H__

#include <cstdint>

namespace BayerConv
{

typedef enum 
{
    BAYER_METHOD_NEAREST=0,
    BAYER_METHOD_SIMPLE,
    BAYER_METHOD_BILINEAR,
    BAYER_METHOD_HQLINEAR,
    BAYER_METHOD_DOWNSAMPLE,
    BAYER_METHOD_EDGESENSE,
    BAYER_METHOD_VNG,
    BAYER_METHOD_AHD
} bayer_method_t;

typedef enum 
{
    COLOR_FILTER_RGGB = 512,
    COLOR_FILTER_GBRG,
    COLOR_FILTER_GRBG,
    COLOR_FILTER_BGGR
} color_filter_t ;

#define COLOR_FILTER_MIN        COLOR_FILTER_RGGB
#define COLOR_FILTER_MAX        COLOR_FILTER_BGGR
#define COLOR_FILTER_NUM       (COLOR_FILTER_MAX - COLOR_FILTER_MIN + 1)

typedef enum 
{
    SUCCESS                     =  0,
    FAILURE                     = -1,
    NOT_A_CAMERA                = -2,
    FUNCTION_NOT_SUPPORTED      = -3,
    CAMERA_NOT_INITIALIZED      = -4,
    MEMORY_ALLOCATION_FAILURE   = -5,
    TAGGED_REGISTER_NOT_FOUND   = -6,
    NO_ISO_CHANNEL              = -7,
    NO_BANDWIDTH                = -8,
    IOCTL_FAILURE               = -9,
    CAPTURE_IS_NOT_SET          = -10,
    CAPTURE_IS_RUNNING          = -11,
    RAW1394_FAILURE             = -12,
    FORMAT7_ERROR_FLAG_1        = -13,
    FORMAT7_ERROR_FLAG_2        = -14,
    INVALID_ARGUMENT_VALUE      = -15,
    REQ_VALUE_OUTSIDE_RANGE     = -16,
    INVALID_FEATURE             = -17,
    INVALID_VIDEO_FORMAT        = -18,
    INVALID_VIDEO_MODE          = -19,
    INVALID_FRAMERATE           = -20,
    INVALID_TRIGGER_MODE        = -21,
    INVALID_TRIGGER_SOURCE      = -22,
    INVALID_ISO_SPEED           = -23,
    INVALID_IIDC_VERSION        = -24,
    INVALID_COLOR_CODING        = -25,
    INVALID_COLOR_FILTER        = -26,
    INVALID_CAPTURE_POLICY      = -27,
    INVALID_ERROR_CODE          = -28,
    INVALID_BAYER_METHOD        = -29,
    INVALID_VIDEO1394_DEVICE    = -30,
    INVALID_OPERATION_MODE      = -31,
    INVALID_TRIGGER_POLARITY    = -32,
    INVALID_FEATURE_MODE        = -33,
    INVALID_LOG_TYPE            = -34,
    INVALID_BYTE_ORDER          = -35,
    INVALID_STEREO_METHOD       = -36,
    BASLER_NO_MORE_SFF_CHUNKS   = -37,
    BASLER_CORRUPTED_SFF_CHUNK  = -38,
    BASLER_UNKNOWN_SFF_CHUNK    = -39
} error_t;

#define ERROR_MIN  BASLER_UNKNOWN_SFF_CHUNK
#define ERROR_MAX  SUCCESS
#define ERROR_NUM  (ERROR_MAX-ERROR_MIN+1)

error_t decoding_8bit( const uint8_t* bayer, \
                       uint8_t * rgb, \
                       uint32_t sx, uint32_t sy, \
                       color_filter_t tile, \
                       bayer_method_t method );

error_t decoding_16bit( const uint16_t* bayer, \
                        uint16_t * rgb, \
                        uint32_t sx, uint32_t sy, \
                        color_filter_t tile, \
                        bayer_method_t method, \
                        uint32_t bits );

}; /// of Bayer namepsce.

#endif /// of __BAYER_H__
