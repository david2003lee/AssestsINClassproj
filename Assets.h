//
// Created by MacbookPro on 5/19/24.
//
//David Lee

#ifndef ICASSETSPROJ_ASSETS_H
#define ICASSETSPROJ_ASSETS_H
#include <string>

using std::string;

class Assets {
public:
    Assets();
    Assets(const string& name);
    Assets(const Assets& other);
    ~Assets();
    const Assets& operator=(const Assets& rhs);
    void AddTag(const string& tag);
    string ToString() const;

private:
    string _name;
    size_t _numberOfTags;
    string* _tags;

    void CopyTags(const string* sourceTags, size_t sourceSize);
    void ClearTags();
};

#endif //ICASSETSPROJ_ASSETS_H
