#pragma once
#include <string>

class Observer {
public:
    virtual void onNotify(const std::string& event) = 0;
    virtual ~Observer() {}
};

class FileLogger : public Observer {
    std::string filename;
public:
    FileLogger(const std::string& fname);
    void onNotify(const std::string& event) override;
};
