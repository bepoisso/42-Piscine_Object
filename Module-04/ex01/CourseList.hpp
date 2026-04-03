#pragma once

#include "singletons.hpp"

class Course;

using CourseList = SingletonList<Course*>;
