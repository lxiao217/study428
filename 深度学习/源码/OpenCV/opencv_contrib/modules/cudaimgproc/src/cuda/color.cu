/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "opencv2/opencv_modules.hpp"

#ifndef HAVE_OPENCV_CUDEV

#error "opencv_cudev is required"

#else

#include "../cvt_color_internal.h"
#include "opencv2/cudev.hpp"

using namespace cv;
using namespace cv::cuda;
using namespace cv::cudev;

namespace cv { namespace cuda { namespace device
{

#define OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name, func_t) \
    void name(const GpuMat& src, GpuMat& dst, Stream& stream) \
    { \
        func_t op; \
        typedef typename func_t::argument_type src_t; \
        typedef typename func_t::result_type   dst_t; \
        gridTransformUnary(globPtr<src_t>(src), globPtr<dst_t>(dst), op, stream); \
    }

#define OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(name) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name, name ## _func)

#define OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(name) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _8u, name ## _func<uchar>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _16u, name ## _func<ushort>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _32f, name ## _func<float>)

#define OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(name) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _8u, name ## _func<uchar>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _32f, name ## _func<float>)

#define OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(name) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _8u, name ## _func<uchar>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _32f, name ## _func<float>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _FULL_8u, name ## _FULL_func<uchar>) \
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR(name ## _FULL_32f, name ## _FULL_func<float>)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_RGBA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_GRAY)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_GRAY)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_GRAY)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_GRAY)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(GRAY_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(GRAY_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_YUV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_YUV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_YUV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_YUV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_YUV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_YUV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_YUV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_YUV4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YUV4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_YCrCb)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_YCrCb)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_YCrCb4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_YCrCb4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_YCrCb)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_YCrCb)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_YCrCb4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_YCrCb4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(YCrCb4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_XYZ)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_XYZ)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGB_to_XYZ4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(RGBA_to_XYZ4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_XYZ)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_XYZ)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGR_to_XYZ4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(BGRA_to_XYZ4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL(XYZ4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGB_to_HSV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGBA_to_HSV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGB_to_HSV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGBA_to_HSV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGR_to_HSV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGRA_to_HSV)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGR_to_HSV4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGRA_to_HSV4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HSV4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGB_to_HLS)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGBA_to_HLS)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGB_to_HLS4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(RGBA_to_HLS4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGR_to_HLS)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGRA_to_HLS)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGR_to_HLS4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(BGRA_to_HLS4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL(HLS4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGB_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGBA_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGB_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGBA_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGR_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGRA_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGR_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGRA_to_Lab4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGB_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGBA_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGB_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGBA_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGR_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGRA_to_Lab)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGR_to_Lab4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGRA_to_Lab4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_LRGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_LRGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_LRGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_LRGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_LBGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_LBGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab_to_LBGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Lab4_to_LBGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGB_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGBA_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGB_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(RGBA_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGR_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGRA_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGR_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(BGRA_to_Luv4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGB_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGBA_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGB_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LRGBA_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGR_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGRA_to_Luv)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGR_to_Luv4)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(LBGRA_to_Luv4)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_LRGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_LRGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_LRGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_LRGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_LBGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_LBGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv_to_LBGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F(Luv4_to_LBGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR_to_BGR555)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR_to_BGR565)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(RGB_to_BGR555)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(RGB_to_BGR565)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGRA_to_BGR555)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGRA_to_BGR565)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(RGBA_to_BGR555)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(RGBA_to_BGR565)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR555_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR565_to_RGB)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR555_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR565_to_BGR)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR555_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR565_to_RGBA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR555_to_BGRA)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR565_to_BGRA)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(GRAY_to_BGR555)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(GRAY_to_BGR565)

    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR555_to_GRAY)
    OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE(BGR565_to_GRAY)

    #undef OPENCV_CUDA_IMPLEMENT_CVTCOLOR
    #undef OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ONE
    #undef OPENCV_CUDA_IMPLEMENT_CVTCOLOR_ALL
    #undef OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F
    #undef OPENCV_CUDA_IMPLEMENT_CVTCOLOR_8U32F_FULL

}}}

#endif
