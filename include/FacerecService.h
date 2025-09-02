#pragma once

#include <memory>
#include <string_view>

#include <pbio/FacerecService.h>

#include "Context.h"
#include "ProcessingBlock.h"
#include "DynamicTemplateIndex.h"

namespace face_sdk_3divi
{
    class FacerecService
    {
    private:
        pbio::FacerecService::Ptr service;

    private:
        FacerecService(const std::string& dllPath, const std::string& confDirectory, const std::string& licenseDirectory);

        ~FacerecService() = default;

    public:
        static pbio::FacerecService::Ptr& get();

        static FacerecService& createService(const std::string& dllPath, const std::string& confDirectory, const std::string& licenseDirectory);

        static Context createContext(const py::dict& ctx);

        static Context createContext(const py::bytes& data);

        static Context createContext(py::array_t<uint8_t> data, int32_t width, int32_t height, Context::Format format = Context::Format::FORMAT_BGR, int32_t baseAngle = 0);

        static Context createContext(const std::string& path);

        static ProcessingBlock createProcessingBlock(const Context& config);
        
        static ProcessingBlock createProcessingBlock(const py::dict& dict);

        static DynamicTemplateIndex createDynamicTemplateIndex(const std::vector<ContextTemplate>& templates, const std::vector<std::string>& uuids, const Context& config);

        static DynamicTemplateIndex createDynamicTemplateIndex(const Context& config);

        static ContextTemplate convertTemplate(const Context& config);

        static ContextTemplate loadContextTemplate(py::object& binaryReadStream);

        static std::string getVersion();

        friend struct std::default_delete<FacerecService>;
    };
}
