aux_source_directory(. TEST_SRC)

set(TEST_APP_NAME ${PROJECT_NAME}_test)
add_executable(
    ${TEST_APP_NAME}
    ${TEST_SRC}
)
target_link_libraries(${TEST_APP_NAME} ${PROJECT_NAME})
