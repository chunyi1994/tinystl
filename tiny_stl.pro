TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
LIBS += -pthread
SOURCES += main.cpp

HEADERS += \
    iterator.h \
    allocate.h \
    iterator_traits.h \
    algorithm.h \
    shared_ptr_data.h \
    shared_ptr.h \
    pair.h \
    utility.h \
    stack.h \
    string_ver_1.h \
    blocking_queue.h \
    strings.h \
    nocopyable.h \
    mutex.h \
    mutex_lock.h \
    condition.h \
    queue.h \
    thread.h \
    array.h \
    heap.h

