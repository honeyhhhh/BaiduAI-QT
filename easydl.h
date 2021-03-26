
#ifndef __AIP_EASYDL_H__
#define __AIP_EASYDL_H__

#include "base/base.h"

namespace aip {

    class EasyDL: public AipBase
    {
    public:
        
        

        EasyDL(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }

        
        Json::Value easydl_request_image(
            std::string const & url,
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            Json::Value data;
            
            data["image"] = aip::base64_encode(image.c_str(), (int) image.size());
;

            std::map<std::string, std::string>::const_iterator it;
            for (it = options.begin(); it != options.end(); it++)
            {
                data[it->first] = it->second;
            }

            Json::Value result =
                this->request(url, null, data.toStyledString(), null);

            return result;
        }
        
        Json::Value easydl_request_sound(
                                         std::string const & url,
                                         std::string const & sound,
                                         const std::map<std::string, std::string> & options)
        {
            Json::Value data;
            
            data["sound"] = aip::base64_encode(sound.c_str(), (int) sound.size());
            ;
            
            std::map<std::string, std::string>::const_iterator it;
            for (it = options.begin(); it != options.end(); it++)
            {
                data[it->first] = it->second;
            }
            
            Json::Value result =
            this->request(url, null, data.toStyledString(), null);
            
            return result;
        }

    };
}
#endif
