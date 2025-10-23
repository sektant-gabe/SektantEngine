#pragma once

/*===================*
 *     Properties     *
 *===================*/
// This macro creates the definitions of getter and setter method for a Property.
#define SP_DEFINE_PROPERTY(propertyType, propertyName)                     \
    const propertyType &get##propertyName() const { return propertyName; } \
    void                set##propertyName(propertyType const &value) { propertyName = value; }
// This macro creates the definitions of a getter method for a Property.
#define SP_DEFINE_GETTER(propertyType, propertyName) \
    const propertyType &get##propertyName() const { return propertyName; }
// This macro creates the definitions of a setter method for a Property.
#define SP_DEFINE_SETTER(propertyType, propertyName) \
    void set##propertyName(propertyType const &value) { propertyName = value; }
