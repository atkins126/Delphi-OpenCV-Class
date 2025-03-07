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

{$IF defined(OPENCV_STITCHING_STITCHER_HPP) and (not defined(OPENCV_STITCHING_STITCHER_HPP_IMPL))}
{$DEFINE OPENCV_STITCHING_STITCHER_HPP_IMPL}

{$IF defined(OPENCV_FEATURES_2D_HPP) and (not defined(OPENCV_FEATURES_2D_HPP_IMPL))}{$i 'features2d.inc'}{$ifend}
{$IF defined(OPENCV_IMGPROC_HPP) and (not defined(OPENCV_IMGPROC_HPP_IMPL))}{$I 'imgproc.inc'}{$ifend}

{ TStitcher }

class function TStitcher.Create(const mode: TStitcher.mode = mode.PANORAMA): TPtr<TStitcher>;
begin
{$IF not defined(PACKAGE)}
  class_proc_CV_STITCHER_create(Result._Ptr, mode);
{$ifend}
end;

function TStitcher.stitch(const images: TInputArrayOfArrays; const pano: TOutputArray): TStitcher.Status;
begin
{$IF not defined(PACKAGE)}
  Result := class_func_CV_STITCHER_stitch_1(Self, images, pano);
{$ifend}
end;

{$IFEND}
