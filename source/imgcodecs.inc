(*
  This file is part of Delphi-OpenCV-Class project.
  https://github.com/Laex/Delphi-OpenCV-Class

  It is subject to the license terms in the LICENSE file found in the top-level directory
  of this distribution and at https://www.apache.org/licenses/LICENSE-2.0.txt

  Copyright 2021, Laentir Valetov, laex@bk.ru

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*)

{$IFDEF INTERFACE}

{$IF not defined(OPENCV_IMGCODECS_HPP)}
{$DEFINE OPENCV_IMGCODECS_HPP}

{$IF not defined(OPENCV_CORE_HPP)}
  {$I 'core.inc'}
{$IFEND}
(* *
  @defgroup imgcodecs Image file reading and writing
  @{
  @defgroup imgcodecs_c C API
  @defgroup imgcodecs_flags Flags used for image file reading and writing
  @defgroup imgcodecs_ios iOS glue
  @defgroup imgcodecs_macosx MacOS(OSX) glue
  @}
*)

/// ///////////////////////////// image codec ////////////////////////////////
// namespace cv
// {
Type
  // ! @addtogroup imgcodecs
  // ! @{

  // ! @addtogroup imgcodecs_flags
  // ! @{

  // ! Imread flags
    ImreadModes = type Int;
const
//  ImreadModes = (                    //
    IMREAD_UNCHANGED = -1;           // !< If set, return the loaded image as is (with alpha channel, otherwise it gets cropped). Ignore EXIF orientation.
    IMREAD_GRAYSCALE = 0;            // !< If set, always convert image to the single channel grayscale image (codec internal conversion).
    IMREAD_COLOR = 1;                // !< If set, always convert image to the 3 channel BGR color image.
    IMREAD_ANYDEPTH = 2;             // !< If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
    IMREAD_ANYCOLOR = 4;             // !< If set, the image is read in any possible color format.
    IMREAD_LOAD_GDAL = 8;            // !< If set, use the gdal driver for loading the image.
    IMREAD_REDUCED_GRAYSCALE_2 = 16; // !< If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
    IMREAD_REDUCED_COLOR_2 = 17;     // !< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
    IMREAD_REDUCED_GRAYSCALE_4 = 32; // !< If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
    IMREAD_REDUCED_COLOR_4 = 33;     // !< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
    IMREAD_REDUCED_GRAYSCALE_8 = 64; // !< If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
    IMREAD_REDUCED_COLOR_8 = 65;     // !< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
    IMREAD_IGNORE_ORIENTATION = 128;  // !< If set, do not rotate the image according to EXIF's orientation flag.
//    );

Type
  // ! Imwrite flags
  ImwriteFlags = type int;                                    //
const
       IMWRITE_JPEG_QUALITY        = 1;  //!< For JPEG, it can be a quality from 0 to 100 (the higher is the better). Default value is 95.
       IMWRITE_JPEG_PROGRESSIVE    = 2;  //!< Enable JPEG features, 0 or 1, default is False.
       IMWRITE_JPEG_OPTIMIZE       = 3;  //!< Enable JPEG features, 0 or 1, default is False.
       IMWRITE_JPEG_RST_INTERVAL   = 4;  //!< JPEG restart interval, 0 - 65535, default is 0 - no restart.
       IMWRITE_JPEG_LUMA_QUALITY   = 5;  //!< Separate luma quality level, 0 - 100, default is -1 - don't use.
       IMWRITE_JPEG_CHROMA_QUALITY = 6;  //!< Separate chroma quality level, 0 - 100, default is -1 - don't use.
       IMWRITE_JPEG_SAMPLING_FACTOR = 7; //!< For JPEG, set sampling factor. See cv::ImwriteJPEGSamplingFactorParams.
       IMWRITE_PNG_COMPRESSION     = 16; //!< For PNG, it can be the compression level from 0 to 9. A higher value means a smaller size and longer compression time. If specified, strategy is changed to IMWRITE_PNG_STRATEGY_DEFAULT (Z_DEFAULT_STRATEGY). Default value is 1 (best speed setting).
       IMWRITE_PNG_STRATEGY        = 17; //!< One of cv::ImwritePNGFlags, default is IMWRITE_PNG_STRATEGY_RLE.
       IMWRITE_PNG_BILEVEL         = 18; //!< Binary level PNG, 0 or 1, default is 0.
       IMWRITE_PXM_BINARY          = 32; //!< For PPM, PGM, or PBM, it can be a binary format flag, 0 or 1. Default value is 1.
       IMWRITE_EXR_TYPE            = (3 shl 4) + 0; //* 48 */ //!< override EXR storage type (FLOAT (FP32) is default)
       IMWRITE_EXR_COMPRESSION     = (3 shl 4) + 1; //* 49 */ //!< override EXR compression type (ZIP_COMPRESSION = 3 is default)
       IMWRITE_EXR_DWA_COMPRESSION_LEVEL = (3 shl 4) + 2; //* 50 */ //!< override EXR DWA compression level (45 is default)
       IMWRITE_WEBP_QUALITY        = 64; //!< For WEBP, it can be a quality from 1 to 100 (the higher is the better). By default (without any parameter) and for quality above 100 the lossless compression is used.
       IMWRITE_HDR_COMPRESSION     = (5 shl 4) + 0; //* 80 */ //!< specify HDR compression
       IMWRITE_PAM_TUPLETYPE       = 128;//!< For PAM, sets the TUPLETYPE field to the corresponding string value that is defined for the format
       IMWRITE_TIFF_RESUNIT        = 256;//!< For TIFF, use to specify which DPI resolution unit to set; see libtiff documentation for valid values
       IMWRITE_TIFF_XDPI           = 257;//!< For TIFF, use to specify the X direction DPI
       IMWRITE_TIFF_YDPI           = 258;//!< For TIFF, use to specify the Y direction DPI
       IMWRITE_TIFF_COMPRESSION    = 259;//!< For TIFF, use to specify the image compression scheme. See libtiff for integer constants corresponding to compression formats. Note, for images whose depth is CV_32F, only libtiff's SGILOG compression scheme is used. For other supported depths, the compression scheme can be specified by this flag; LZW compression is the default.
       IMWRITE_JPEG2000_COMPRESSION_X1000 = 272;//!< For JPEG2000, use to specify the target compression rate (multiplied by 1000). The value can be from 0 to 1000. Default is 1000.
       IMWRITE_AVIF_QUALITY        = 512;//!< For AVIF, it can be a quality between 0 and 100 (the higher the better). Default is 95.
       IMWRITE_AVIF_DEPTH          = 513;//!< For AVIF, it can be 8, 10 or 12. If >8, it is stored/read as CV_32F. Default is 8.
       IMWRITE_AVIF_SPEED          = 514; //!< For AVIF, it is between 0 (slowest) and (fastest). Default is 9.
//    );

Type 
    ImwriteJPEGSamplingFactorParams = type int;
Const
       IMWRITE_JPEG_SAMPLING_FACTOR_411 = $411111; //!< 4x1,1x1,1x1
       IMWRITE_JPEG_SAMPLING_FACTOR_420 = $221111; //!< 2x2,1x1,1x1(Default)
       IMWRITE_JPEG_SAMPLING_FACTOR_422 = $211111; //!< 2x1,1x1,1x1
       IMWRITE_JPEG_SAMPLING_FACTOR_440 = $121111; //!< 1x2,1x1,1x1
       IMWRITE_JPEG_SAMPLING_FACTOR_444 = $111111;  //!< 1x1,1x1,1x1(No subsampling)
     

Type
  ImwriteEXRTypeFlags = type int;
const
    (* IMWRITE_EXR_TYPE_UNIT = 0, //!< not supported *)
    IMWRITE_EXR_TYPE_HALF = 1; // !< store as HALF (FP16)
    IMWRITE_EXR_TYPE_FLOAT = 2; // !< store as FP32 (default)

type
  ImwriteEXRCompressionFlags = type int;
const
    IMWRITE_EXR_COMPRESSION_NO = 0;    // !< no compression
    IMWRITE_EXR_COMPRESSION_RLE = 1;   // !< run length encoding
    IMWRITE_EXR_COMPRESSION_ZIPS = 2;  // !< zlib compression, one scan line at a time
    IMWRITE_EXR_COMPRESSION_ZIP = 3;   // !< zlib compression, in blocks of 16 scan lines
    IMWRITE_EXR_COMPRESSION_PIZ = 4;   // !< piz-based wavelet compression
    IMWRITE_EXR_COMPRESSION_PXR24 = 5; // !< lossy 24-bit float compression
    IMWRITE_EXR_COMPRESSION_B44 = 6;   // !< lossy 4-by-4 pixel block compression, fixed compression rate
    IMWRITE_EXR_COMPRESSION_B44A = 7;  // !< lossy 4-by-4 pixel block compression, flat fields are compressed more
    IMWRITE_EXR_COMPRESSION_DWAA = 8;  // !< lossy DCT based compression, in blocks of 32 scanlines. More efficient for partial buffer access. Supported since OpenEXR 2.2.0.
    IMWRITE_EXR_COMPRESSION_DWAB = 9;   // !< lossy DCT based compression, in blocks of 256 scanlines. More efficient space wise and faster to decode full frames than DWAA_COMPRESSION. Supported since OpenEXR 2.2.0.

Type
  // ! Imwrite PNG specific flags used to tune the compression algorithm.
  (* * These flags will be modify the way of PNG image compression and will be passed to the underlying zlib processing stage.

    -   The effect of IMWRITE_PNG_STRATEGY_FILTERED is to force more Huffman coding and less string matching; it is somewhat intermediate between IMWRITE_PNG_STRATEGY_DEFAULT and IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY.
    -   IMWRITE_PNG_STRATEGY_RLE is designed to be almost as fast as IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY, but give better compression for PNG image data.
    -   The strategy parameter only affects the compression ratio but not the correctness of the compressed output even if it is not set appropriately.
    -   IMWRITE_PNG_STRATEGY_FIXED prevents the use of dynamic Huffman codes, allowing for a simpler decoder for special applications.
  *)
  ImwritePNGFlags = type int;
const
    IMWRITE_PNG_STRATEGY_DEFAULT = 0;      // !< Use this value for normal data.
    IMWRITE_PNG_STRATEGY_FILTERED = 1;     // !< Use this value for data produced by a filter (or predictor).Filtered data consists mostly of small values with a somewhat random distribution. In this case, the compression algorithm is tuned to compress them better.
    IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY = 2; // !< Use this value to force Huffman encoding only (no string match).
    IMWRITE_PNG_STRATEGY_RLE = 3;          // !< Use this value to limit match distances to one (run-length encoding).
    IMWRITE_PNG_STRATEGY_FIXED = 4;         // !< Using this value prevents the use of dynamic Huffman codes, allowing for a simpler decoder for special applications.

type
  // ! Imwrite PAM specific tupletype flags used to define the 'TUPETYPE' field of a PAM file.
  ImwritePAMFlags = type int;
const
    IMWRITE_PAM_FORMAT_NULL = 0;            //
    IMWRITE_PAM_FORMAT_BLACKANDWHITE = 1;   //
    IMWRITE_PAM_FORMAT_GRAYSCALE = 2;       //
    IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA = 3; //
    IMWRITE_PAM_FORMAT_RGB = 4;             //
    IMWRITE_PAM_FORMAT_RGB_ALPHA = 5;        //

  // ! @} imgcodecs_flags

  (* * @brief Loads an image from a file.

    @anchor imread

    The function imread loads an image from the specified file and returns it. If the image cannot be
    read (because of missing file, improper permissions, unsupported or invalid format), the function
    returns an empty matrix ( Mat::data==NULL ).

    Currently, the following file formats are supported:

    -   Windows bitmaps - \*.bmp, \*.dib (always supported)
    -   JPEG files - \*.jpeg, \*.jpg, \*.jpe (see the *Note* section)
    -   JPEG 2000 files - \*.jp2 (see the *Note* section)
    -   Portable Network Graphics - \*.png (see the *Note* section)
    -   WebP - \*.webp (see the *Note* section)
    -   Portable image format - \*.pbm, \*.pgm, \*.ppm \*.pxm, \*.pnm (always supported)
    -   PFM files - \*.pfm (see the *Note* section)
    -   Sun rasters - \*.sr, \*.ras (always supported)
    -   TIFF files - \*.tiff, \*.tif (see the *Note* section)
    -   OpenEXR Image files - \*.exr (see the *Note* section)
    -   Radiance HDR - \*.hdr, \*.pic (always supported)
    -   Raster and Vector geospatial data supported by GDAL (see the *Note* section)

    @note
    -   The function determines the type of an image by the content, not by the file extension.
    -   In the case of color images, the decoded images will have the channels stored in **B G R** order.
    -   When using IMREAD_GRAYSCALE, the codec's internal grayscale conversion will be used, if available.
    Results may differ to the output of cvtColor()
    -   On Microsoft Windows\* OS and MacOSX\*, the codecs shipped with an OpenCV image (libjpeg,
    libpng, libtiff, and libjasper) are used by default. So, OpenCV can always read JPEGs, PNGs,
    and TIFFs. On MacOSX, there is also an option to use native MacOSX image readers. But beware
    that currently these native image loaders give images with different pixel values because of
    the color management embedded into MacOSX.
    -   On Linux\*, BSD flavors and other Unix-like open-source operating systems, OpenCV looks for
    codecs supplied with an OS image. Install the relevant packages (do not forget the development
    files, for example, 'libjpeg-dev', in Debian\* and Ubuntu\* ) to get the codec support or turn
    on the OPENCV_BUILD_3RDPARTY_LIBS flag in CMake.
    -   In the case you set *WITH_GDAL* flag to true in CMake and @ref IMREAD_LOAD_GDAL to load the image,
    then the [GDAL](http://www.gdal.org) driver will be used in order to decode the image, supporting
    the following formats: [Raster](http://www.gdal.org/formats_list.html),
    [Vector](http://www.gdal.org/ogr_formats.html).
    -   If EXIF information is embedded in the image file, the EXIF orientation will be taken into account
    and thus the image will be rotated accordingly except if the flags @ref IMREAD_IGNORE_ORIENTATION
    or @ref IMREAD_UNCHANGED are passed.
    -   Use the IMREAD_UNCHANGED flag to keep the floating point values from PFM image.
    -   By default number of pixels must be less than 2^30. Limit can be set using system
    variable OPENCV_IO_MAX_IMAGE_PIXELS

    @param filename Name of file to be loaded.
    @param flags Flag that can take values of cv::ImreadModes
  *)
  // CV_EXPORTS_W Mat imread( const String& filename, int flags = IMREAD_COLOR );
function imread(const filename: String; flag: ImreadModes = IMREAD_UNCHANGED): TMat; {$IFDEF USE_INLINE}inline; {$ENDIF}

(* * @brief Loads a multi-page image from a file.

  The function imreadmulti loads a multi-page image from the specified file into a vector of Mat objects.
  @param filename Name of file to be loaded.
  @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
  @param mats A vector of Mat objects holding each page, if more than one.
  @sa cv::imread
*)
// CV_EXPORTS_W bool imreadmulti(const String& filename, CV_OUT std::vector<Mat>& mats, int flags = IMREAD_ANYCOLOR);
function imreadmulti
(const filename:String; Var mats:vector<TMat>; flags:int = IMREAD_ANYCOLOR):bool;
{$IFDEF USE_INLINE}inline; {$ENDIF} overload;

(* * @brief Loads a of images of a multi-page image from a file.

  The function imreadmulti loads a specified range from a multi-page image from the specified file into a vector of Mat objects.
  @param filename Name of file to be loaded.
  @param start Start index of the image to load
  @param count Count number of images to load
  @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
  @param mats A vector of Mat objects holding each page, if more than one.
  @sa cv::imread
*)
// CV_EXPORTS_W bool imreadmulti(const String& filename, CV_OUT std::vector<Mat>& mats, int start, int count, int flags = IMREAD_ANYCOLOR);
function imreadmulti
(const filename:String; Var mats:vector<TMat>; start, count:int; flags :int = IMREAD_ANYCOLOR):bool;
{$IFDEF USE_INLINE}inline; {$ENDIF} overload;

(* * @brief Returns the number of images inside the give file

  The function imcount will return the number of pages in a multi-page image, or 1 for single-page images
  @param filename Name of file to be loaded.
  @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
*)
// CV_EXPORTS_W size_t imcount(const String& filename, int flags = IMREAD_ANYCOLOR);
function imcount(const filename:String; flags:int = IMREAD_ANYCOLOR):size_t; {$IFDEF USE_INLINE}inline; {$ENDIF}

(* * @brief Saves an image to a specified file.

  The function imwrite saves the image to the specified file. The image format is chosen based on the
  filename extension (see cv::imread for the list of extensions). In general, only 8-bit
  single-channel or 3-channel (with 'BGR' channel order) images
  can be saved using this function, with these exceptions:

  - 16-bit unsigned (CV_16U) images can be saved in the case of PNG, JPEG 2000, and TIFF formats
  - 32-bit float (CV_32F) images can be saved in PFM, TIFF, OpenEXR, and Radiance HDR formats;
  3-channel (CV_32FC3) TIFF images will be saved using the LogLuv high dynamic range encoding
  (4 bytes per pixel)
  - PNG images with an alpha channel can be saved using this function. To do this, create
  8-bit (or 16-bit) 4-channel image BGRA, where the alpha channel goes last. Fully transparent pixels
  should have alpha set to 0, fully opaque pixels should have alpha set to 255/65535 (see the code sample below).
  - Multiple images (vector of Mat) can be saved in TIFF format (see the code sample below).

  If the image format is not supported, the image will be converted to 8-bit unsigned (CV_8U) and saved that way.

  If the format, depth or channel order is different, use
  Mat::convertTo and cv::cvtColor to convert it before saving. Or, use the universal FileStorage I/O
  functions to save the image to XML or YAML format.

  The sample below shows how to create a BGRA image, how to set custom compression parameters and save it to a PNG file.
  It also demonstrates how to save multiple images in a TIFF file:
  @include snippets/imgcodecs_imwrite.cpp
  @param filename Name of the file.
  @param img (Mat or vector of Mat) Image or Images to be saved.
  @param params Format-specific parameters encoded as pairs (paramId_1, paramValue_1, paramId_2, paramValue_2, ... .) see cv::ImwriteFlags
*)
// CV_EXPORTS_W bool imwrite( const String& filename, InputArray img,
// const std::vector<int>& params = std::vector<int>());
function imwrite(const filename: String; const img: TInputArray; const params: Vector<int>): BOOL; overload; {$IFDEF USE_INLINE}inline; {$ENDIF}
function imwrite(const filename: String; const img: TInputArray): BOOL; overload; {$IFDEF USE_INLINE}inline; {$ENDIF}

  /// @overload multi-image overload for bindings
  // CV_WRAP static inline
  // bool imwritemulti(const String& filename, InputArrayOfArrays img,
  // const std::vector<int>& params = std::vector<int>())
  // {
  // return imwrite(filename, img, params);
  // }
function imwritemulti(const filename:String; const img:TInputArrayOfArrays;
   const params:vector<int>):bool; overload; {$IFDEF USE_INLINE}inline; {$ENDIF}
function imwritemulti(const filename:String; const img:TInputArrayOfArrays):bool; overload; {$IFDEF USE_INLINE}inline; {$ENDIF}

  (* * @brief Reads an image from a buffer in memory.

    The function imdecode reads an image from the specified buffer in the memory. If the buffer is too short or
    contains invalid data, the function returns an empty matrix ( Mat::data==NULL ).

    See cv::imread for the list of supported formats and flags description.

    @note In the case of color images, the decoded images will have the channels stored in **B G R** order.
    @param buf Input array or vector of bytes.
    @param flags The same flags as in cv::imread, see cv::ImreadModes.
  *)
  // CV_EXPORTS_W Mat imdecode( InputArray buf, int flags );
function imdecode(const buf: TInputArray; const flags: Integer): TMat; {$IFDEF USE_INLINE}inline; {$ENDIF} overload;

    (* * @overload
      @param buf
      @param flags
      @param dst The optional output placeholder for the decoded matrix. It can save the image
      reallocations when the function is called repeatedly for images of the same size.
    *)
    // CV_EXPORTS Mat imdecode( InputArray buf, int flags, Mat* dst);
function imdecode(const buf:TInputArray; const flags:int; const dst:pMat):TMat; {$IFDEF USE_INLINE}inline; {$ENDIF} overload;

    (* * @brief Encodes an image into a memory buffer.

      The function imencode compresses the image and stores it in the memory buffer that is resized to fit the
      result. See cv::imwrite for the list of supported formats and flags description.

      @param ext File extension that defines the output format.
      @param img Image to be written.
      @param buf Output buffer resized to fit the compressed image.
      @param params Format-specific parameters. See cv::imwrite and cv::ImwriteFlags.
    *)
    // CV_EXPORTS_W bool imencode( const String& ext, InputArray img,
    // CV_OUT std::vector<uchar>& buf,
    // const std::vector<int>& params = std::vector<int>());
function imencode( const ext:string; const img:TInputArray;
         Var buf:vector<uchar>;
         const params:vector<int> ):bool; {$IFDEF USE_INLINE}inline; {$ENDIF} overload;
function imencode( const ext:string; const img:TInputArray;
         Var buf:vector<uchar>):bool; {$IFDEF USE_INLINE}inline; {$ENDIF} overload;

    (* * @brief Returns true if the specified image can be decoded by OpenCV
      @param filename File name of the image
    *)
    // CV_EXPORTS_W bool haveImageReader( const String& filename );
function haveImageReader(const filename:string):bool; {$IFDEF USE_INLINE}inline; {$ENDIF}

    (* * @brief Returns true if an image with the specified filename can be encoded by OpenCV
      @param filename File name of the image
    *)
    // CV_EXPORTS_W bool haveImageWriter( const String& filename );
function haveImageWriter(const filename:string):bool; {$IFDEF USE_INLINE}inline; {$ENDIF}

{$IFEND OPENCV_IMGCODECS_HPP}

{$ENDIF INTERFACE}

// ============================================================================

{$IFDEF IMPLEMENTATION}

{$IF defined(OPENCV_IMGCODECS_HPP) and (not defined(OPENCV_IMGCODECS_HPP_IMPL))}
{$DEFINE OPENCV_IMGCODECS_HPP_IMPL}

function imread(const filename: String; flag: ImreadModes = IMREAD_UNCHANGED): TMat;
begin
{$IF not defined(PACKAGE)}
  Result := func_imread(CppString(filename), flag);
{$IFEND}
end;

function imreadmulti(const filename: String; Var mats: vector<TMat>; flags: int = IMREAD_ANYCOLOR): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_imreadmulti(CppString(filename), mats, flags);
{$IFEND}
end;

function imreadmulti(const filename: String; Var mats: vector<TMat>; start, count: int; flags: int = IMREAD_ANYCOLOR): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_imreadmulti_1(CppString(filename), mats, start, count, flags);
{$IFEND}
end;

function imcount(const filename: String; flags: int = IMREAD_ANYCOLOR): size_t;
begin
{$IF not defined(PACKAGE)}
  Result := func_imcount(CppString(filename), flags);
{$IFEND}
end;

function imwrite(const filename: String; const img: TInputArray; const params: vector<int>): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_imwrite(CppString(filename), img, params);
{$IFEND}
end;

function imwrite(const filename: String; const img: TInputArray): bool;
begin
  Var
    a: vector<int>;
  Result := imwrite(filename, img, a);
end;

function imwritemulti(const filename: String; const img: TInputArrayOfArrays; const params: vector<int>): bool;
begin
  Result := imwrite(filename, img, params);
end;

function imwritemulti(const filename: String; const img: TInputArrayOfArrays): bool;
begin
  Var
    params: vector<int>;
  Result := imwrite(filename, img, params);
end;

function imdecode(const buf: TInputArray; const flags: Integer): TMat;
begin
{$IF not defined(PACKAGE)}
  Result := func_imdecode(buf, flags);
{$IFEND}
end;

function imdecode(const buf: TInputArray; const flags: int; const dst: pMat): TMat;
begin
{$IF not defined(PACKAGE)}
  Result := func_imdecode_1(buf, flags, dst);
{$IFEND}
end;

function imencode(const ext: string; const img: TInputArray; Var buf: vector<uchar>; const params: vector<int>): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_imencode(CppString(ext), img, buf, params);
{$IFEND}
end;

function imencode(const ext: string; const img: TInputArray; Var buf: vector<uchar>): bool;
begin
{$IF not defined(PACKAGE)}
  Var
    V: vector<int>;
  Result := func_imencode(CppString(ext), img, buf, V);
{$IFEND}
end;

function haveImageReader(const filename: string): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_haveImageReader(CppString(filename));
{$IFEND}
end;

function haveImageWriter(const filename: string): bool;
begin
{$IF not defined(PACKAGE)}
  Result := func_haveImageWriter(CppString(filename));
{$IFEND}
end;

{$IFEND}

{$ENDIF IMPLEMENTATION}
