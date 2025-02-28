macro(find_dependency dep)
  if (NOT ${dep}_FOUND)
    set(cmake_fd_version)
    if (${ARGC} GREATER 1)
      if ("${ARGV1}" STREQUAL "")
        message(FATAL_ERROR "Invalid arguments to find_dependency. VERSION is empty")
      endif()
      if ("${ARGV1}" STREQUAL EXACT)
        message(FATAL_ERROR "Invalid arguments to find_dependency. EXACT may only be specified if a VERSION is specified")
      endif()
      set(cmake_fd_version ${ARGV1})
    endif()
    set(cmake_fd_exact_arg)
    if(${ARGC} GREATER 2)
      if (NOT "${ARGV2}" STREQUAL EXACT)
        message(FATAL_ERROR "Invalid arguments to find_dependency")
      endif()
      set(cmake_fd_exact_arg EXACT)
    endif()
    if(${ARGC} GREATER 3)
      message(FATAL_ERROR "Invalid arguments to find_dependency")
    endif()
    set(cmake_fd_quiet_arg)
    if(${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      set(cmake_fd_quiet_arg QUIET)
    endif()
    set(cmake_fd_required_arg)
    if(${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED)
      set(cmake_fd_required_arg REQUIRED)
    endif()

    get_property(cmake_fd_alreadyTransitive GLOBAL PROPERTY
      _CMAKE_${dep}_TRANSITIVE_DEPENDENCY
    )

    find_package(${dep} ${cmake_fd_version}
        ${cmake_fd_exact_arg}
        ${cmake_fd_quiet_arg}
        ${cmake_fd_required_arg}
    )

    if(NOT DEFINED cmake_fd_alreadyTransitive OR cmake_fd_alreadyTransitive)
      set_property(GLOBAL PROPERTY _CMAKE_${dep}_TRANSITIVE_DEPENDENCY TRUE)
    endif()

    if (NOT ${dep}_FOUND)
      set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "${CMAKE_FIND_PACKAGE_NAME} could not be found because dependency ${dep} could not be found.")
      set(${CMAKE_FIND_PACKAGE_NAME}_FOUND False)
      return()
    endif()
    set(cmake_fd_version)
    set(cmake_fd_required_arg)
    set(cmake_fd_quiet_arg)
    set(cmake_fd_exact_arg)
  endif()
endmacro()

find_dependency(PercipioFoundation)
include("${CMAKE_CURRENT_LIST_DIR}/PercipioNetTargets.cmake")
