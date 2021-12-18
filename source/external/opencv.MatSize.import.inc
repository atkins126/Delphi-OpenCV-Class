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

// ??0MatSize@cv@@QEAA@PEAH@Z      public: __cdecl cv::MatSize::MatSize(int * __ptr64) __ptr64
// ??4MatSize@cv@@QEAAAEAU01@$$QEAU01@@Z   public: struct cv::MatSize & __ptr64 __cdecl cv::MatSize::operator=(struct cv::MatSize && __ptr64) __ptr64
// ??4MatSize@cv@@QEAAAEAU01@AEBU01@@Z     public: struct cv::MatSize & __ptr64 __cdecl cv::MatSize::operator=(struct cv::MatSize const & __ptr64) __ptr64
// ??RMatSize@cv@@QEBA?AV?$Size_@H@1@XZ
// public: class cv::Size_<int> __cdecl cv::MatSize::operator()(void)const __ptr64
procedure operator_MatSize_MatSizeToSize(const Obj: TMatSize; const s: TSize); external opencv_world_dll
//index 2965
name '??RMatSize@cv@@QEBA?AV?$Size_@H@1@XZ'
{$IFDEF DELAYED_LOAD_DLL} delayed{$ENDIF};
// ?dims@MatSize@cv@@QEBAHXZ       public: int __cdecl cv::MatSize::dims(void)const __ptr64
