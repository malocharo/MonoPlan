project(TestCell)
add_executable(TestCell cell_test.c cell.c cell.h ../Liste/liste.c ../Liste/liste.h ../Pile/pile.c ../Pile/pile.h)
target_link_libraries(TestCell m)
install(TARGETS TestCell RUNTIME DESTINATION ${BIN_DIR})