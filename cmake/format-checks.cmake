set(FORMAT_COMMAND ${PROJECT_SOURCE_DIR}/format.sh)

FIND_PROGRAM(CLANG_CHECK clang-check)

FILE(GLOB_RECURSE FORMAT_FILES *.c *.h)

ADD_CUSTOM_TARGET(
    format
    COMMAND
    ${FORMAT_COMMAND}
    -i
    ${FORMAT_FILES}
    COMMENT "Run in-place formating of .c and .h files"
)

