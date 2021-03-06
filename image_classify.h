
#ifndef __AIP_IMAGECLASSIFY_H__
#define __AIP_IMAGECLASSIFY_H__

#include "base/base.h"

namespace aip {

    class Imageclassify: public AipBase
    {
    public:

    
        std::string _advanced_general =
            "https://aip.baidubce.com/rest/2.0/image-classify/v2/advanced_general";
        
        std::string _dish_detect =
            "https://aip.baidubce.com/rest/2.0/image-classify/v2/dish";
        
        std::string _car_detect =
            "https://aip.baidubce.com/rest/2.0/image-classify/v1/car";
        
        std::string _logo_search =
            "https://aip.baidubce.com/rest/2.0/image-classify/v2/logo";
        
        std::string _logo_add =
            "https://aip.baidubce.com/rest/2.0/realtime_search/v1/logo/add";
        
        std::string _logo_delete =
            "https://aip.baidubce.com/rest/2.0/realtime_search/v1/logo/delete";
        
        std::string _animal_detect =
            "https://aip.baidubce.com/rest/2.0/image-classify/v1/animal";
        
        std::string _plant_detect =
            "https://aip.baidubce.com/rest/2.0/image-classify/v1/plant";
        
        std::string _object_detect =
            "https://aip.baidubce.com/rest/2.0/image-classify/v1/object_detect";
        
        std::string _landmark =
            "https://aip.baidubce.com/rest/2.0/image-classify/v1/landmark";
        

        Imageclassify(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }
        
        /**
         * advanced_general
         * 该请求用于通用物体及场景识别，即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片中的多个物体及场景标签。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * baike_num 返回百科信息的结果数，默认不返回
         */
        Json::Value advanced_general(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_advanced_general, null, data, null);

            return result;
        }
        
        /**
         * dish_detect
         * 该请求用于菜品识别。即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片的菜品名称、卡路里信息、置信度。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * top_num 返回预测得分top结果数，默认为5
         * filter_threshold 默认0.95，可以通过该参数调节识别效果，降低非菜识别率.
         * baike_num 返回百科信息的结果数，默认不返回
         */
        Json::Value dish_detect(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_dish_detect, null, data, null);

            return result;
        }
        
        /**
         * car_detect
         * 该请求用于检测一张车辆图片的具体车型。即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片的车辆品牌及型号。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * top_num 返回预测得分top结果数，默认为5
         * baike_num 返回百科信息的结果数，默认不返回
         */
        Json::Value car_detect(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_car_detect, null, data, null);

            return result;
        }
        
        /**
         * logo_search
         * 该请求用于检测和识别图片中的品牌LOGO信息。即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片中LOGO的名称、位置和置信度。当效果欠佳时，可以建立子库（在[控制台](https://console.bce.baidu.com/ai/#/ai/imagerecognition/overview/index)创建应用并申请建库）并通过调用logo入口接口完成自定义logo入库，提高识别效果。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * custom_lib 是否只使用自定义logo库的结果，默认false：返回自定义库+默认库的识别结果
         */
        Json::Value logo_search(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_logo_search, null, data, null);

            return result;
        }
        
        /**
         * logo_add
         * 使用入库接口请先在[控制台](https://console.bce.baidu.com/ai/#/ai/imagerecognition/overview/index)创建应用并申请建库，建库成功后方可正常使用。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * @param brief brief，检索时带回。此处要传对应的name与code字段，name长度小于100B，code长度小于150B
         * options 可选参数:
         */
        Json::Value logo_add(
            std::string const & image,
            std::string const & brief,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());
            data["brief"] = brief;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_logo_add, null, data, null);

            return result;
        }
        
        /**
         * logo_delete_by_image
         * 使用删除接口请先在[控制台](https://console.bce.baidu.com/ai/#/ai/imagerecognition/overview/index)创建应用并申请建库，建库成功后先调用入库接口完成logo图片入库，删除接口用户在已入库的logo图片中删除图片。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value logo_delete_by_image(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_logo_delete, null, data, null);

            return result;
        }
        
        /**
         * logo_delete_by_sign
         * 使用删除接口请先在[控制台](https://console.bce.baidu.com/ai/#/ai/imagerecognition/overview/index)创建应用并申请建库，建库成功后先调用入库接口完成logo图片入库，删除接口用户在已入库的logo图片中删除图片。
         * @param cont_sign 图片签名（和image二选一，image优先级更高）
         * options 可选参数:
         */
        Json::Value logo_delete_by_sign(
            std::string const & cont_sign,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["cont_sign"] = cont_sign;

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_logo_delete, null, data, null);

            return result;
        }
        
        /**
         * animal_detect
         * 该请求用于识别一张图片。即对于输入的一张图片（可正常解码，且长宽比适宜），输出动物识别结果
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * top_num 返回预测得分top结果数，默认为6
         * baike_num 返回百科信息的结果数，默认不返回
         */
        Json::Value animal_detect(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_animal_detect, null, data, null);

            return result;
        }
        
        /**
         * plant_detect
         * 该请求用于识别一张图片。即对于输入的一张图片（可正常解码，且长宽比适宜），输出植物识别结果。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * baike_num 返回百科信息的结果数，默认不返回
         */
        Json::Value plant_detect(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_plant_detect, null, data, null);

            return result;
        }
        
        /**
         * object_detect
         * 用户向服务请求检测图像中的主体位置。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         * with_face 如果检测主体是人，主体区域是否带上人脸部分，0-不带人脸区域，其他-带人脸区域，裁剪类需求推荐带人脸，检索/识别类需求推荐不带人脸。默认取1，带人脸。
         */
        Json::Value object_detect(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_object_detect, null, data, null);

            return result;
        }
        
        /**
         * landmark
         * 该请求用于识别地标，即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片中的地标识别结果。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value landmark(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_landmark, null, data, null);

            return result;
        }
        

    };
}
#endif
