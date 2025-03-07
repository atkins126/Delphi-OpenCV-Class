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

{$ifndef OPENCV_OBJDETECT_FACE_HPP}
{$define OPENCV_OBJDETECT_FACE_HPP}

{$IF not defined(OPENCV_CORE_HPP)}{$I 'core.inc'}{$ifend}

(** @defgroup dnn_face DNN-based face detection and recognition
 *)

//namespace cv
//{
(*
/** @brief DNN-based face detector, model download link: https://github.com/ShiqiYu/libfacedetection.train/tree/master/tasks/task1/onnx.
 */
class CV_EXPORTS_W FaceDetectorYN
{
public:
    virtual ~FaceDetectorYN() {};

    /** @brief Set the size for the network input, which overwrites the input size of creating model. Call this method when the size of input image does not match the input size when creating model
     *
     * @param input_size the size of the input image
     */
    CV_WRAP virtual void setInputSize(const Size& input_size) = 0;

    CV_WRAP virtual Size getInputSize() = 0;

    /** @brief Set the score threshold to filter out bounding boxes of score less than the given value
     *
     * @param score_threshold threshold for filtering out bounding boxes
     */
    CV_WRAP virtual void setScoreThreshold(float score_threshold) = 0;

    CV_WRAP virtual float getScoreThreshold() = 0;

    /** @brief Set the Non-maximum-suppression threshold to suppress bounding boxes that have IoU greater than the given value
     *
     * @param nms_threshold threshold for NMS operation
     */
    CV_WRAP virtual void setNMSThreshold(float nms_threshold) = 0;

    CV_WRAP virtual float getNMSThreshold() = 0;

    /** @brief Set the number of bounding boxes preserved before NMS
     *
     * @param top_k the number of bounding boxes to preserve from top rank based on score
     */
    CV_WRAP virtual void setTopK(int top_k) = 0;

    CV_WRAP virtual int getTopK() = 0;

    /** @brief A simple interface to detect face from given image
     *
     *  @param image an image to detect
     *  @param faces detection results stored in a cv::Mat
     */
    CV_WRAP virtual int detect(InputArray image, OutputArray faces) = 0;

    /** @brief Creates an instance of this class with given parameters
     *
     *  @param model the path to the requested model
     *  @param config the path to the config file for compability, which is not requested for ONNX models
     *  @param input_size the size of the input image
     *  @param score_threshold the threshold to filter out bounding boxes of score smaller than the given value
     *  @param nms_threshold the threshold to suppress bounding boxes of IoU bigger than the given value
     *  @param top_k keep top K bboxes before NMS
     *  @param backend_id the id of backend
     *  @param target_id the id of target device
     */
    CV_WRAP static Ptr<FaceDetectorYN> create(const String& model,
                                              const String& config,
                                              const Size& input_size,
                                              float score_threshold = 0.9f,
                                              float nms_threshold = 0.3f,
                                              int top_k = 5000,
                                              int backend_id = 0,
                                              int target_id = 0);
};

/** @brief DNN-based face recognizer, model download link: https://drive.google.com/file/d/1ClK9WiB492c5OZFKveF3XiHCejoOxINW/view.
 */
class CV_EXPORTS_W FaceRecognizerSF
{
public:
    virtual ~FaceRecognizerSF() {};

    /** @brief Definition of distance used for calculating the distance between two face features
     */
    enum DisType { FR_COSINE=0, FR_NORM_L2=1 };

    /** @brief Aligning image to put face on the standard position
     *  @param src_img input image
     *  @param face_box the detection result used for indicate face in input image
     *  @param aligned_img output aligned image
     */
    CV_WRAP virtual void alignCrop(InputArray src_img, InputArray face_box, OutputArray aligned_img) const = 0;

    /** @brief Extracting face feature from aligned image
     *  @param aligned_img input aligned image
     *  @param face_feature output face feature
     */
    CV_WRAP virtual void feature(InputArray aligned_img, OutputArray face_feature) = 0;

    /** @brief Calculating the distance between two face features
     *  @param _face_feature1 the first input feature
     *  @param _face_feature2 the second input feature of the same size and the same type as _face_feature1
     *  @param dis_type defining the similarity with optional values "FR_OSINE" or "FR_NORM_L2"
     */
    CV_WRAP virtual double match(InputArray _face_feature1, InputArray _face_feature2, int dis_type = FaceRecognizerSF::FR_COSINE) const = 0;

    /** @brief Creates an instance of this class with given parameters
     *  @param model the path of the onnx model used for face recognition
     *  @param config the path to the config file for compability, which is not requested for ONNX models
     *  @param backend_id the id of backend
     *  @param target_id the id of target device
     */
    CV_WRAP static Ptr<FaceRecognizerSF> create(const String& model, const String& config, int backend_id = 0, int target_id = 0);
};

} // namespace cv
*)
{$endif}
