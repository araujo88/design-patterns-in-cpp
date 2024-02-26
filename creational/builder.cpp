#include <iostream>
#include <map>
#include <string>

class HTTPRequestBuilder {
public:
    virtual ~HTTPRequestBuilder() {}
    virtual HTTPRequestBuilder& setMethod(const std::string& method) = 0;
    virtual HTTPRequestBuilder& setURL(const std::string& url) = 0;
    virtual HTTPRequestBuilder& setHeader(const std::string& key, const std::string& value) = 0;
    virtual HTTPRequestBuilder& setBody(const std::string& body) = 0;
    virtual HTTPRequestBuilder& addQueryParam(const std::string& key, const std::string& value) = 0;
    // Other builder methods as needed
    virtual std::string build() = 0; // Constructs the final request string or object
};

class ConcreteHTTPRequestBuilder : public HTTPRequestBuilder {
private:
    std::string method = "GET"; // Default method
    std::string url;
    std::map<std::string, std::string> headers;
    std::string body;
    std::map<std::string, std::string> queryParams;
public:
    HTTPRequestBuilder& setMethod(const std::string& method) override {
        this->method = method;
        return *this;
    }

    HTTPRequestBuilder& setURL(const std::string& url) override {
        this->url = url;
        return *this;
    }

    HTTPRequestBuilder& setHeader(const std::string& key, const std::string& value) override {
        headers[key] = value;
        return *this;
    }

    HTTPRequestBuilder& setBody(const std::string& body) override {
        this->body = body;
        return *this;
    }

    HTTPRequestBuilder& addQueryParam(const std::string& key, const std::string& value) override {
        queryParams[key] = value;
        return *this;
    }

    std::string build() override {
        // Construct the request string/object based on the specified parameters
        // This is simplified for demonstration
        std::string request = method + " " + url;
        // Add query parameters, headers, body, etc.
        return request;
    }
};

int main() {
  ConcreteHTTPRequestBuilder builder;
  std::string request = builder
                          .setMethod("POST")
                          .setURL("http://example.com/api/data")
                          .setHeader("Content-Type", "application/json")
                          .setBody(R"({"name":"John Doe","age":30})")
                          .addQueryParam("verbose", "true")
                          .build();

  // Use the request string/object
  std::cout << request << std::endl;
  
  return 0;
}
