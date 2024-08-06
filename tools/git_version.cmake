# ------------------------------------------------------- MINIMUM CMAKE VERSION
cmake_minimum_required(VERSION 3.20.1)

# Including this file adds functions to generate versioning information from git


#   TARGET          The current target that should have version info added
#   VERSION_ROOT    The prefix attached to a git tag describing the version.
#
#   Currently defined via env:
#   VERSION_REGEX   A regex that will match the version digits.  It is expected
#                   to have three groups defined: major, minor and build.  This
#                   is an optional variable and if not defined will default to
#                   a format of major.minor.build, where:
#                       major is a number between 0 and 65535
#                       minor is a number between 0 and 65535
#                       build is a number between 0 and 65535
#                       rc    is a number between 0 and 65535
#                   Any extra characters following the version are discarded.
#
# After this function has executed, the following variables will be defined in application.c:
#
#   GIT_VERSION_TAG
#   GIT_DESCRIBE_TAG
#   GIT_SHORT_SHA
#   MAJOR_VERSION
#   MINOR_VERSION
#   BUILD_NUMBER
#   FULL_VERSION
function(git_version_add TARGET VERSION_ROOT)

    message(DEBUG "TARGET=>${TARGET}<")
    message(DEBUG "VERSION_ROOT=>${VERSION_ROOT}<")

    # matches 0.1.2 or 0.1.2-rc3 and captures 0,1,2 or 0,1,2,3
    if(NOT DEFINED VERSION_REGEX)
        set(VERSION_REGEX "([0-9]+)\\.([0-9]+)\\.([0-9]+)(-rc)?([0-9]+)?.*")
    endif()

    set(VERSION "${VERSION_ROOT}${VERSION_REGEX}")

    # Get commit sha
    execute_process(
        COMMAND git rev-parse HEAD
        OUTPUT_VARIABLE GIT_COMMIT_SHA
    )
    string(STRIP ${GIT_COMMIT_SHA} GIT_COMMIT_SHA)
    message(STATUS "GIT_COMMIT_SHA              : " ${GIT_COMMIT_SHA})

    # Get the most recent tag
    execute_process(
        COMMAND git describe --always --tags --dirty --exclude "${VERSION_ROOT}[0-9]*.[0-9]*.[0-9]*"
        OUTPUT_VARIABLE GIT_DESCRIBE_TAG
    )
    string(STRIP ${GIT_DESCRIBE_TAG} GIT_DESCRIBE_TAG)
    message(STATUS "GIT_DESCRIBE_TAG            : " ${GIT_DESCRIBE_TAG})


    execute_process(
        COMMAND git describe --match ForceNone --abbrev=10 --always --dirty=+
        OUTPUT_VARIABLE GIT_SHORT_SHA
    )
    string(STRIP ${GIT_SHORT_SHA} GIT_SHORT_SHA)
    message(STATUS "GIT_SHORT_SHA               : " ${GIT_SHORT_SHA})

    # Get the most recent semantic versioning tag number
    execute_process(
        COMMAND git describe --always --tags --dirty --match "${VERSION_ROOT}[0-9]*.[0-9]*.[0-9]*"
        # COMMAND_ECHO STDOUT
        # ECHO_OUTPUT_VARIABLE
        RESULT_VARIABLE GIT_STATUS
        OUTPUT_VARIABLE GIT_OUTPUT
        ERROR_VARIABLE GIT_ERROR
    )
    if(GIT_STATUS AND NOT GIT_STATUS EQUAL 0)
        message(NOTICE "Couldn't find version tags matching '${VERSION}': ${GIT_OUTPUT} (${GIT_STATUS})")
        set(GIT_VERSION_TAG "${VERSION_ROOT}0.0.0")
    else()
        if("${GIT_OUTPUT}" STREQUAL "")
            message(NOTICE "Couldn't match '${VERSION}': ${VERSION_ROOT}*")
            set(GIT_VERSION_TAG "${VERSION_ROOT}0.0.0")
        else()
            string(STRIP ${GIT_OUTPUT} GIT_VERSION_TAG)
        endif()
    endif()
    message(STATUS "GIT_VERSION_TAG             : " ${GIT_VERSION_TAG})

    if(GIT_OUTPUT MATCHES ".*dirty.*")
        message(WARNING "Building with dirty git repo!!")
    endif()

    string(REGEX REPLACE ${VERSION} "\\1" MAJOR_VERSION ${GIT_VERSION_TAG})
    string(REGEX REPLACE ${VERSION} "\\2" MINOR_VERSION ${GIT_VERSION_TAG})
    string(REGEX REPLACE ${VERSION} "\\3" BUILD_NUMBER ${GIT_VERSION_TAG})
    string(REGEX REPLACE ${VERSION} "\\5" RC_NUMBER ${GIT_VERSION_TAG})

    # Use the output from the above string commands to create global variables
    set(MAJOR_VERSION ${MAJOR_VERSION})
    set(MINOR_VERSION ${MINOR_VERSION})
    set(BUILD_NUMBER ${BUILD_NUMBER})
    set(RC_NUMBER ${RC_NUMBER})

    message(DEBUG "MAJOR_VERSION=>${MAJOR_VERSION}<")
    message(DEBUG "MINOR_VERSION=>${MINOR_VERSION}<")
    message(DEBUG "BUILD_NUMBER=>${BUILD_NUMBER}<")
    message(DEBUG "RC_NUMBER=>${RC_NUMBER}<")

    # Verify values
    if(NOT (("${MAJOR_VERSION}" GREATER_EQUAL 0) AND ("${MAJOR_VERSION}" LESS_EQUAL 65535)))
        message(NOTICE "Invalid app major version: ${MAJOR_VERSION}")
        message(NOTICE "  Is the branch tagged with version root:'${VERSION_ROOT}' or missing version tag?\n\n")
        set(MAJOR_VERSION 0)
    endif()

    if(NOT (("${MINOR_VERSION}" GREATER_EQUAL 0) AND ("${MINOR_VERSION}" LESS_EQUAL 65535)))
        message(NOTICE "Invalid app minor version: ${MINOR_VERSION}")
        message(NOTICE "  Is the branch tagged with version root:'${VERSION_ROOT}' or missing version tag?\n\n")
        set(MINOR_VERSION 0)
    endif()

    if(NOT (("${BUILD_NUMBER}" GREATER_EQUAL 0) AND ("${BUILD_NUMBER}" LESS_EQUAL 65535)))
        message(NOTICE "Invalid app build: ${BUILD_NUMBER}")
        message(NOTICE "  Is the branch tagged with version root:'${VERSION_ROOT}' or missing version tag?\n\n")
        set(BUILD_NUMBER 0)
    endif()

    if(NOT (("${RC_NUMBER}" GREATER_EQUAL 0) AND ("${RC_NUMBER}" LESS_EQUAL 65535)))
        message(NOTICE "Invalid app build: ${RC_NUMBER}")
        message(NOTICE "  Is the branch tagged with version root:'${VERSION_ROOT}' or missing version tag?\n\n")
        set(RC_NUMBER 0)
    endif()

    if("${RC_NUMBER}" GREATER 0)
        set(FULL_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${BUILD_NUMBER}-rc${RC_NUMBER}")
    else()
        set(FULL_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${BUILD_NUMBER}")
    endif()

    message(DEBUG "FULL_VERSION=>${FULL_VERSION}<")

    # Get and inject version information
    configure_file(${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../../templates/versioning/application_version.c.in ${CMAKE_BINARY_DIR}/generated/application_version.c NEWLINE_STYLE UNIX)
    target_sources(${TARGET} PRIVATE ${CMAKE_BINARY_DIR}/generated/application_version.c)
    # target_compile_options(${TARGET}
    #     PRIVATE
    #     -D__GIT_SHORT_SHA=${GIT_SHORT_SHA}
    #     -D__GIT_DESCRIBE_TAG=${GIT_DESCRIBE_TAG}
    #     -D__GIT_COMMIT_SHA=${GIT_SHORT_SHA}
    #     -D__GIT_VERSION_TAG=${GIT_VERSION_TAG}
    #     -DAPP_MAJOR_VERSION=${MAJOR_VERSION},
    #     -DAPP_MINOR_VERSION=${MINOR_VERSION},
    #     -DAPP_BUILD_NUMBER=${BUILD_NUMBER},
    #     -DAPP_RC_NUMBER=${RC_NUMBER}
    # )

endfunction()