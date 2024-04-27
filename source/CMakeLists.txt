project(banana-core)

add_library(banana STATIC core.cpp)
target_include_directories(banana PRIVATE ${BANANA_ROOT_DIR}/third_party/json)
target_include_directories(banana PUBLIC ${BANANA_ROOT_DIR}/include)
target_compile_features(banana PUBLIC cxx_std_17)
target_compile_definitions(banana PUBLIC
        BANANA_VERSION_MAJOR=${BANANA_VERSION_MAJOR}
        BANANA_VERSION_MINOR=${BANANA_VERSION_MINOR}
        BANANA_VERSION_PATCH=${BANANA_VERSION_PATCH}
)

# === Agents ===

add_subdirectory(agents)

set(SCRIPT_DIR "${BANANA_ROOT_DIR}/script")
set(OUT_INCLUDE_PATH "${BANANA_ROOT_DIR}/include/banana/detail/generated")
set(OUT_SOURCE_PATH "${BANANA_ROOT_DIR}/source/generated")

find_package (Python3 COMPONENTS Interpreter)

if(Python3_FOUND)
        add_custom_command(OUTPUT ${SCRIPT_DIR}/api.json
                COMMAND Python3::Interpreter ${SCRIPT_DIR}/custom2json.py
                DEPENDS ${SCRIPT_DIR}/custom.json
                WORKING_DIRECTORY ${SCRIPT_DIR}
                COMMENT "Generate api.json"
        )

        add_custom_target(generate_banana_code
                ${CMAKE_COMMAND} -E make_directory "${OUT_SOURCE_PATH}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${OUT_INCLUDE_PATH}"
                COMMAND Python3::Interpreter ${SCRIPT_DIR}/json2cpp.py
                DEPENDS ${SCRIPT_DIR}/api.json
                WORKING_DIRECTORY ${SCRIPT_DIR}
                COMMENT "Generate banana_code"
        )
endif()
