//
// Created by alexa on 12.12.2022.
//
#include <drogon/HttpSimpleController.h>
#include <drogon/HttpResponse.h>

using namespace drogon;

class HelloViewController : public HttpSimpleController<HelloViewController>
{
public:
    PATH_LIST_BEGIN
    PATH_ADD("/view");
    PATH_LIST_END

    void asyncHandleHttpRequest(
            const HttpRequestPtr &req,
            std::function<void(const HttpResponsePtr &)> &&callback) override
    {
        HttpViewData data;
        data["name"] = req->getParameter("name");
        auto resp = HttpResponse::newHttpViewResponse("HelloView", data);
        callback(resp);
    }
};