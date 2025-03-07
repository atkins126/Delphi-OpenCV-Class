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

{$if not defined(OPENCV_STITCHING_MATCHERS_HPP)}
{$define OPENCV_STITCHING_MATCHERS_HPP}

{$if not defined(OPENCV_OPENCV_MODULES_HPP)}{$I 'opencv_modules.inc'}{$ifend}
{$IF not defined(OPENCV_CORE_HPP)}{$I 'core.inc'}{$ifend}
{$if not defined(OPENCV_FEATURES_2D_HPP)}{$i 'features2d.inc'}{$ifend}

//namespace cv {
//namespace detail {

//! @addtogroup stitching_match
//! @{

(** @brief Structure containing image keypoints and descriptors. *)
//struct CV_EXPORTS_W_SIMPLE ImageFeatures
//{
//    CV_PROP_RW int img_idx;
//    CV_PROP_RW Size img_size;
//    CV_PROP_RW std::vector<KeyPoint> keypoints;
//    CV_PROP_RW UMat descriptors;
//    CV_WRAP std::vector<KeyPoint> getKeypoints() { return keypoints; };
//};
(** @brief

@param featuresFinder
@param images
@param features
@param masks
*)
//CV_EXPORTS_W void computeImageFeatures(
//    const Ptr<Feature2D> &featuresFinder,
//    InputArrayOfArrays  images,
//    CV_OUT std::vector<ImageFeatures> &features,
//    InputArrayOfArrays masks = noArray());

(** @brief

@param featuresFinder
@param image
@param features
@param mask
*)
//CV_EXPORTS_AS(computeImageFeatures2) void computeImageFeatures(
//    const Ptr<Feature2D> &featuresFinder,
//    InputArray image,
//    CV_OUT ImageFeatures &features,
//    InputArray mask = noArray());

(** @brief Structure containing information about matches between two images.

It's assumed that there is a transformation between those images. Transformation may be
homography or affine transformation based on selected matcher.

@sa detail::FeaturesMatcher
*)
//struct CV_EXPORTS_W_SIMPLE MatchesInfo
//{
//    MatchesInfo();
//    MatchesInfo(const MatchesInfo &other);
//    MatchesInfo& operator =(const MatchesInfo &other);
//
//    CV_PROP_RW int src_img_idx;
//    CV_PROP_RW int dst_img_idx;       //!< Images indices (optional)
//    std::vector<DMatch> matches;
//    std::vector<uchar> inliers_mask;    //!< Geometrically consistent matches mask
//    CV_PROP_RW int num_inliers;                    //!< Number of geometrically consistent matches
//    CV_PROP_RW Mat H;                              //!< Estimated transformation
//    CV_PROP_RW double confidence;                  //!< Confidence two images are from the same panorama
//    CV_WRAP std::vector<DMatch> getMatches() { return matches; };
//    CV_WRAP std::vector<uchar> getInliers() { return inliers_mask; };
//};

(** @brief Feature matchers base class. *)
//class CV_EXPORTS_W FeaturesMatcher
//{
//public:
//    CV_WRAP virtual ~FeaturesMatcher() {}
//
//    (** @overload
//    @param features1 First image features
//    @param features2 Second image features
//    @param matches_info Found matches
//    *)
//    CV_WRAP_AS(apply) void operator ()(const ImageFeatures &features1, const ImageFeatures &features2,
//                     CV_OUT MatchesInfo& matches_info) { match(features1, features2, matches_info); }
//
//    (** @brief Performs images matching.
//
//    @param features Features of the source images
//    @param pairwise_matches Found pairwise matches
//    @param mask Mask indicating which image pairs must be matched
//
//    The function is parallelized with the TBB library.
//
//    @sa detail::MatchesInfo
//    *)
//    CV_WRAP_AS(apply2) void operator ()(const std::vector<ImageFeatures> &features, CV_OUT std::vector<MatchesInfo> &pairwise_matches,
//                     const cv::UMat &mask = cv::UMat());
//
//    (** @return True, if it's possible to use the same matcher instance in parallel, false otherwise
//    *)
//   CV_WRAP bool isThreadSafe() const { return is_thread_safe_; }
//
//    (** @brief Frees unused memory allocated before if there is any.
//    *)
//   CV_WRAP virtual void collectGarbage() {}
//
//protected:
//    FeaturesMatcher(bool is_thread_safe = false) : is_thread_safe_(is_thread_safe) {}
//
//    (** @brief This method must implement matching logic in order to make the wrappers
//    detail::FeaturesMatcher::operator()_ work.
//
//    @param features1 first image features
//    @param features2 second image features
//    @param matches_info found matches
//     *)
//    virtual void match(const ImageFeatures &features1, const ImageFeatures &features2,
//                       MatchesInfo& matches_info) = 0;
//
//    bool is_thread_safe_;
//};

(** @brief Features matcher which finds two best matches for each feature and leaves the best one only if the
ratio between descriptor distances is greater than the threshold match_conf

@sa detail::FeaturesMatcher
 *)
//class CV_EXPORTS_W BestOf2NearestMatcher : public FeaturesMatcher
//{
//public:
//    (** @brief Constructs a "best of 2 nearest" matcher.
//
//    @param try_use_gpu Should try to use GPU or not
//    @param match_conf Match distances ration threshold
//    @param num_matches_thresh1 Minimum number of matches required for the 2D projective transform
//    estimation used in the inliers classification step
//    @param num_matches_thresh2 Minimum number of matches required for the 2D projective transform
//    re-estimation on inliers
//     *)
//    CV_WRAP BestOf2NearestMatcher(bool try_use_gpu = false, float match_conf = 0.3f, int num_matches_thresh1 = 6,
//                          int num_matches_thresh2 = 6);
//
//    CV_WRAP void collectGarbage() CV_OVERRIDE;
//    CV_WRAP static Ptr<BestOf2NearestMatcher> create(bool try_use_gpu = false, float match_conf = 0.3f, int num_matches_thresh1 = 6,
//        int num_matches_thresh2 = 6);
//
//protected:
//
//    void match(const ImageFeatures &features1, const ImageFeatures &features2, MatchesInfo &matches_info) CV_OVERRIDE;
//    int num_matches_thresh1_;
//    int num_matches_thresh2_;
//    Ptr<FeaturesMatcher> impl_;
//};

//class CV_EXPORTS_W BestOf2NearestRangeMatcher : public BestOf2NearestMatcher
//{
//public:
//    CV_WRAP BestOf2NearestRangeMatcher(int range_width = 5, bool try_use_gpu = false, float match_conf = 0.3f,
//                            int num_matches_thresh1 = 6, int num_matches_thresh2 = 6);
//
//    void operator ()(const std::vector<ImageFeatures> &features, std::vector<MatchesInfo> &pairwise_matches,
//                     const cv::UMat &mask = cv::UMat());
//
//
//protected:
//    int range_width_;
//};

(** @brief Features matcher similar to cv::detail::BestOf2NearestMatcher which
finds two best matches for each feature and leaves the best one only if the
ratio between descriptor distances is greater than the threshold match_conf.

Unlike cv::detail::BestOf2NearestMatcher this matcher uses affine
transformation (affine transformation estimate will be placed in matches_info).

@sa cv::detail::FeaturesMatcher cv::detail::BestOf2NearestMatcher
 *)
//class CV_EXPORTS_W AffineBestOf2NearestMatcher : public BestOf2NearestMatcher
//{
//public:
//    (** @brief Constructs a "best of 2 nearest" matcher that expects affine transformation
//    between images
//
//    @param full_affine whether to use full affine transformation with 6 degress of freedom or reduced
//    transformation with 4 degrees of freedom using only rotation, translation and uniform scaling
//    @param try_use_gpu Should try to use GPU or not
//    @param match_conf Match distances ration threshold
//    @param num_matches_thresh1 Minimum number of matches required for the 2D affine transform
//    estimation used in the inliers classification step
//
//    @sa cv::estimateAffine2D cv::estimateAffinePartial2D
//     *)
//    CV_WRAP AffineBestOf2NearestMatcher(bool full_affine = false, bool try_use_gpu = false,
//                                float match_conf = 0.3f, int num_matches_thresh1 = 6) :
//        BestOf2NearestMatcher(try_use_gpu, match_conf, num_matches_thresh1, num_matches_thresh1),
//        full_affine_(full_affine) {}
//
//protected:
//    void match(const ImageFeatures &features1, const ImageFeatures &features2, MatchesInfo &matches_info) CV_OVERRIDE;
//
//    bool full_affine_;
//};

//! @} stitching_match

//} // namespace detail
//} // namespace cv

{$ifend}//OPENCV_STITCHING_MATCHERS_HPP
