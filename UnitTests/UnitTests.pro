QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    provisilist-ut.cpp \
    ../ProvisiList/ingredientslist.cpp \
    ../ProvisiList/masteringredientslist.cpp

HEADERS += ../ProvisiList/ingredientslist.h \
    ../ProvisiList/masteringredientslist.h

#INCLUDEPATH += ../ProvisiList \

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../unittest-cpp/builds/release/ -lUnitTest++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../unittest-cpp/builds/debug/ -lUnitTest++
else:unix: LIBS += -L$$PWD/../../../unittest-cpp/builds/ -lUnitTest++

INCLUDEPATH += $$PWD/../../../unittest-cpp
DEPENDPATH += $$PWD/../../../unittest-cpp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../unittest-cpp/builds/release/libUnitTest++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../unittest-cpp/builds/debug/libUnitTest++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../unittest-cpp/builds/release/UnitTest++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../unittest-cpp/builds/debug/UnitTest++.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../unittest-cpp/builds/libUnitTest++.a
