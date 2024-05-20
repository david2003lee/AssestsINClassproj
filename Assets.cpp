//
// Created by MacbookPro on 5/19/24.
//

#include "Assets.h"
#include <iostream>
#include <sstream>

// Default constructor
Assets::Assets() : _name(""), _numberOfTags(0), _tags(nullptr) {}

// Constructor with name
Assets::Assets(const string& name) : _name(name), _numberOfTags(0), _tags(nullptr) {}

// Copy constructor
Assets::Assets(const Assets& other) : _name(other._name), _numberOfTags(other._numberOfTags), _tags(nullptr) {
    CopyTags(other._tags, other._numberOfTags);
}

// Destructor
Assets::~Assets() {
    ClearTags();
}

// Assignment operator
const Assets& Assets::operator=(const Assets& rhs) {
    if (this != &rhs) {
        ClearTags();
        _name = rhs._name;
        _numberOfTags = rhs._numberOfTags;
        CopyTags(rhs._tags, rhs._numberOfTags);
    }
    return *this;
}

// Add a tag to the list
void Assets::AddTag(const string& tag) {
    string* newTags = new string[_numberOfTags + 1];
    for (size_t i = 0; i < _numberOfTags; ++i) {
        newTags[i] = _tags[i];
    }
    newTags[_numberOfTags] = tag;
    delete[] _tags;
    _tags = newTags;
    ++_numberOfTags;
}

// Generate a string representation of the Assets object
string Assets::ToString() const {
    std::ostringstream oss;
    oss << "{\"name\": \"" << _name << "\", \"numberofTags\" : \"" << _numberOfTags << "\", \"Tags\":";
    for (size_t i = 0; i < _numberOfTags; ++i) {
        oss << _tags[i];
        if (i < _numberOfTags - 1) {
            oss << "; ";
        }
    }
    oss << "}";
    return oss.str();
}

// Copy tags from source to destination
void Assets::CopyTags(const string* sourceTags, size_t sourceSize) {
    if (sourceSize > 0) {
        _tags = new string[sourceSize];
        for (size_t i = 0; i < sourceSize; ++i) {
            _tags[i] = sourceTags[i];
        }
    } else {
        _tags = nullptr;
    }
}

// Clear all tags
void Assets::ClearTags() {
    delete[] _tags;
    _tags = nullptr;
    _numberOfTags = 0;
}
