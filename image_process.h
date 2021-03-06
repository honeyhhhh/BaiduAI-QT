
#ifndef __AIP_IMAGEPROCESS_H__
#define __AIP_IMAGEPROCESS_H__

#include "base/base.h"

namespace aip {

    class Imageprocess: public AipBase
    {
    public:

    
        std::string _image_quality_enhance =
            "https://aip.baidubce.com/rest/2.0/image-process/v1/image_quality_enhance";
        
        std::string _dehaze =
            "https://aip.baidubce.com/rest/2.0/image-process/v1/dehaze";
        
        std::string _contrast_enhance =
            "https://aip.baidubce.com/rest/2.0/image-process/v1/contrast_enhance";
        

        Imageprocess(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }
        
        /**
         * image_quality_enhance
         * 输入一张图片，可以在尽量保持图像质量的条件下，将图像在长宽方向各放大两倍。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value image_quality_enhance(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_image_quality_enhance, null, data, null);

            return result;
        }
        
        /**
         * dehaze
         * 对浓雾天气下拍摄，导致细节无法辨认的图像进行去雾处理，还原更清晰真实的图像。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value dehaze(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_dehaze, null, data, null);

            return result;
        }
        
        /**
         * contrast_enhance
         * 调整过暗或者过亮图像的对比度，使图像更加鲜明。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value contrast_enhance(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_contrast_enhance, null, data, null);

            return result;
        }
        

    };
}
#endif
