#include <drogon/drogon.h>
using namespace drogon;

int main()
{
    app().registerHandler(
            "/",
            [](const HttpRequestPtr &,
               std::function<void(const HttpResponsePtr &)> &&callback) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setBody("Hello, World!");
                callback(resp);
            },
            {Get});

    app().registerHandler(
            "/user/{user-name}",
            [](const HttpRequestPtr &,
               std::function<void(const HttpResponsePtr &)> &&callback,
               const std::string &name) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setBody("Hello, " + name + "!");
                callback(resp);
            },
            {Get});

    app().registerHandler(
            "/hello?user={user-name}",
            [](const HttpRequestPtr &,
               std::function<void(const HttpResponsePtr &)> &&callback,
               const std::string &name) {
                auto resp = HttpResponse::newHttpResponse();
                resp->setBody("Hello, " + name + "!");
                callback(resp);
            },
            {Get});

    app().registerHandler(
            "/hello_user",
            [](const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback) {
                auto resp = HttpResponse::newHttpResponse();
                auto name = req->getOptionalParameter<std::string>("user");
                if (!name)
                    resp->setBody("Please tell me your name");
                else
                    resp->setBody("Hello, " + name.value() + "!");
                callback(resp);
            },
            {Get});

    // listen on 127.0.0.1 port 8848
    LOG_INFO << "Server running on 127.0.0.1:8848";
    app().addListener("127.0.0.1", 8848).run();
}
