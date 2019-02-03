#pragma once
#include "TemplateOfTypes.h"

#include "Type.h"

namespace meta17 {

template<template<class...> class To, template<class...> class From, class... Ts>
auto transformTemplate(Type<From<Ts...>>, TemplateOfTypes<To> = {}) -> Type<To<Ts...>> {
    return {};
}

template<template<class...> class To, class From>
using TransformTemplate = decltype(transformTemplate<To>(type<From>));

} // namespace meta17
