find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_FASTSRC gnuradio-fastsrc)

FIND_PATH(
    GR_FASTSRC_INCLUDE_DIRS
    NAMES gnuradio/fastsrc/api.h
    HINTS $ENV{FASTSRC_DIR}/include
        ${PC_FASTSRC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_FASTSRC_LIBRARIES
    NAMES gnuradio-fastsrc
    HINTS $ENV{FASTSRC_DIR}/lib
        ${PC_FASTSRC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-fastsrcTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_FASTSRC DEFAULT_MSG GR_FASTSRC_LIBRARIES GR_FASTSRC_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_FASTSRC_LIBRARIES GR_FASTSRC_INCLUDE_DIRS)
