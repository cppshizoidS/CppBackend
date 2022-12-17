//
// Created by alexa on 12.12.2022.
//
#include <drogon/HttpController.h>

using namespace drogon;


class SayHello : public HttpController<SayHello>
{
public:
    METHOD_LIST_BEGIN

    METHOD_ADD(SayHello::genericHello, "/", Get);

    METHOD_ADD(SayHello::personalizedHello, "/hello", Get);
    METHOD_LIST_END

protected:
    void genericHello(const HttpRequestPtr &,
                      std::function<void(const HttpResponsePtr &)> &&callback)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody(
                "Hello, this is a generic hello message from the SayHello "
                "controller");
        callback(resp);
    }

    void personalizedHello(
            const HttpRequestPtr &,
            std::function<void(const HttpResponsePtr &)> &&callback)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody(
                "Hi there, this is another hello from the SayHello Controller");
        callback(resp);
    }
};