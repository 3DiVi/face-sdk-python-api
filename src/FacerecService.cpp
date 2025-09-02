#include "FacerecService.h"

static std::unique_ptr<face_sdk_3divi::FacerecService> instance;

namespace face_sdk_3divi
{
    FacerecService::FacerecService(const std::string& dllPath, const std::string& confDirectory, const std::string& licenseDirectory) :
        service(pbio::FacerecService::createService(dllPath, confDirectory, licenseDirectory))
    {

    }

    pbio::FacerecService::Ptr& FacerecService::get()
    {
        if (!instance)
        {
            throw std::runtime_error("Call face_sdk.create_service");
        }

        return instance->service;
    }

    FacerecService& FacerecService::createService(const std::string& dllPath, const std::string& confDirectory, const std::string& licenseDirectory)
    {
        if (!instance)
        {
            instance = std::unique_ptr<FacerecService>(new FacerecService(dllPath, confDirectory, licenseDirectory));
        }

        return *instance;
    }

    Context FacerecService::createContext(const py::dict& ctx)
    {
        return Context(ctx);
    }

    Context FacerecService::createContext(const py::bytes& data)
    {
        return Context(data);
    }

    Context FacerecService::createContext(py::array_t<uint8_t> data, int32_t width, int32_t height, Context::Format format, int32_t baseAngle)
    {
        return Context(data, width, height, format, baseAngle);
    }

    Context FacerecService::createContext(const std::string& path)
    {
        return Context(path);
    }

    ProcessingBlock FacerecService::createProcessingBlock(const Context& config)
    {
        return ProcessingBlock(config);
    }

    ProcessingBlock FacerecService::createProcessingBlock(const py::dict& dict)
    {
        return ProcessingBlock(dict);
    }

    DynamicTemplateIndex FacerecService::createDynamicTemplateIndex(const std::vector<ContextTemplate>& templates, const std::vector<std::string>& uuids, const Context& config)
    {
        return DynamicTemplateIndex(templates, uuids, config);
    }

    DynamicTemplateIndex FacerecService::createDynamicTemplateIndex(const Context& config)
    {
        return DynamicTemplateIndex(config);
    }

    ContextTemplate FacerecService::convertTemplate(const Context& config)
    {
        return ContextTemplate(config);
    }

    ContextTemplate FacerecService::loadContextTemplate(py::object& binaryReadStream)
    {
        return ContextTemplate(binaryReadStream);
    }

    std::string FacerecService::getVersion()
    {
        return FacerecService::get()->getVersion();
    }
}
